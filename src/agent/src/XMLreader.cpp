/*
* Licensed to the Apache Software Foundation (ASF) under one
* or more contributor license agreements. See the NOTICE file
* distributed with this work for additional information
* regarding copyright ownership. The ASF licenses this file
* to you under the Apache License, Version 2.0 (the
* "License"); you may not use this file except in compliance
* with the License. You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing,
* software distributed under the License is distributed on an
* "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
* KIND, either express or implied. See the License for the
* specific language governing permissions and limitations
* under the License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "../XMLreader.h"
#include "../../TLogging.h"

namespace thrx
{

// https://stackoverflow.com/questions/6062822/whats-wrong-with-strndup
char *strndup(const char *str, size_t chars)
{
   size_t n = 0;

   char* buffer = (char *)malloc(chars + 1);
   if (buffer)
   {
      for (n = 0; ((n < chars) && (str[n] != 0)); n++) 
         buffer[n] = str[n];

      buffer[n] = 0;
   }
   return buffer;
}

// https://code.woboq.org/userspace/glibc/string/strndup.c.html
//char * __strndup(const char *s, size_t n)
//{
//   size_t len = strnlen(s, n);
//   char *new_str = (char *)malloc(len + 1);
//   
//   if (new_str == NULL)
//      return NULL;
//
//   new_str[len] = '\0';
//
//   return (char *)memcpy(new_str, s, len);
//}

}  //namespace thrx


#if FALSE

//#include <expat.h>

XML_node *XMLreader::xml_alloc(XML_node *parent)
{
   XML_node *n, **link = &parent->child;

   if ((n = (XML_node *)malloc(sizeof(XML_node))) == NULL)
   {
      T_ERROR("Out of memory\n");
      exit(1);
   }

   n->key = NULL;
   n->value = NULL;
   n->attr = NULL;
   n->child = NULL;
   n->next = NULL;
   n->parent = parent;

   while (*link != NULL) {
      link = &(*link)->next;
   }

   return *link = n;
}

void XMLreader::xml_free(XML_node *node)
{
   int i;

   if (node == NULL)
      return;

   if (node->key != NULL)
      free(node->key);

   if (node->value != NULL)
      free(node->value);

   if (node->attr != NULL) {
      for (i = 0; node->attr[i]; i++)
         free(node->attr[i]);
      free(node->attr);
   }

   xml_free(node->next);
   xml_free(node->child);
}

void XMLreader::xml_el_start(void *data, const char *name, const char **attr)
{
   int i, nattr = 1;
   XML_node *node = xml_alloc(*((XML_node **)data));

   if (node == NULL)
   {
      T_ERROR("Out of memory node");
      return;
   }

   node->key = strdup(name);

   for (i = 0; attr[i]; i++)
   {
      nattr++;
   }

   if ((node->attr = (char **)malloc(sizeof(char *) * nattr)) == NULL)
   {
      T_ERROR("Out of memory node attr");
      xml_free(node);
      return;
   }

   for (i = 0; attr[i]; i++) {
      node->attr[i] = strdup(attr[i]);
      //printf("ATTR: %s\n", attr[i]);
   }

   node->attr[i] = NULL;

   *((XML_node **)data) = node;
}

void XMLreader::xml_el_end(void *data, const char *name)
{
   XML_node *node = *((XML_node **)data);

   *((XML_node **)data) = node->parent;
}

void XMLreader::xml_charhndl(void *data, const char *s, int len)
{
   XML_node *node = *((XML_node **)data);

   if (len > 5)
   {
      node->value = strndup(s, len);
   }
}

XML_node *XMLreader::xml_parse(const char *filename)
{
   int done = 0;
   FILE *xptr;
   XML_Parser p;
   static char buf[BUFSIZE];
   XML_node root, *ret;

   if ((xptr = fopen(filename, "r")) == NULL)
   {
      T_ERROR("Unable to open file: [%s]", filename);
      return NULL;
   }

   root.child = NULL;

   if ((ret = xml_alloc(&root)) == NULL)
   {
      fclose(xptr);
      T_ERROR("Out of memory root child");
      return NULL;
   }

   if ((p = XML_ParserCreate(NULL)) == NULL)
   {
      fclose(xptr);
      T_ERROR("Out of memory parser create");
      return NULL;
   }

   XML_SetUserData(p, &ret);
   XML_SetElementHandler(p, xml_el_start, xml_el_end);
   XML_SetCharacterDataHandler(p, xml_charhndl);

   while (!done)
   {
      int len;

      len = fread(buf, 1, BUFSIZE, xptr);
      if (ferror(xptr))
      {
         T_ERROR("Read error");
         xml_free(ret);
         ret = NULL;
         break;
      }
      done = feof(xptr);

      if (XML_Parse(p, buf, len, done) == 0)
      {
         T_ERROR("Parse error at line [%d]:[%s]", (int)XML_GetCurrentLineNumber(p), XML_ErrorString(XML_GetErrorCode(p)));
         xml_free(ret);
         ret = NULL;
         break;
      }
   }

   if (ret != NULL)
      ret->parent = NULL;

   fclose(xptr);
   XML_ParserFree(p);
   return ret;
}


int XMLreader::xml_parse_with_report(const char *filename, char *erbuf, int erlen)
{
   int done = 0, myval = 1;
   FILE *xptr;
   XML_Parser p;
   static char buf[BUFSIZE];
   XML_node root, *ret;

   if ((xptr = fopen(filename, "r")) == NULL)
   {
      snprintf(erbuf, erlen, "Unable to open file: [%s]", filename);
      return 0;
   }

   root.child = NULL;
   if ((ret = xml_alloc(&root)) == NULL)
   {
      fclose(xptr);
      snprintf(erbuf, erlen, "Out of memory root child");
      return 0;
   }

   if ((p = XML_ParserCreate(NULL)) == NULL)
   {
      fclose(xptr);
      snprintf(erbuf, erlen, "Out of memory parser create");
      return 0;
   }

   XML_SetUserData(p, &ret);
   XML_SetElementHandler(p, xml_el_start, xml_el_end);
   XML_SetCharacterDataHandler(p, xml_charhndl);

   while (!done)
   {
      int len;
      len = fread(buf, 1, BUFSIZE, xptr);
      if (ferror(xptr))
      {
         snprintf(erbuf, erlen, "Read error");
         xml_free(ret);
         ret = NULL;
         myval = 0;
         break;
      }
      done = feof(xptr);

      if (XML_Parse(p, buf, len, done) == 0)
      {
         snprintf(erbuf, erlen, "Parse error at line [%d]:[%s]", (int)XML_GetCurrentLineNumber(p), XML_ErrorString(XML_GetErrorCode(p)));
         xml_free(ret);
         ret = NULL;
         myval = 0;
         break;
      }
   }

   if (ret != NULL)
      ret->parent = NULL;

   fclose(xptr);
   XML_ParserFree(p);

   if (ret) xml_free(ret);
   return myval;
}


XML_node *XMLreader::xml_node_str(char *str, int len)
{
   FILE *xptr = NULL;
   XML_Parser p;
   static char buf[BUFSIZE];
   XML_node root, *ret;

   if (NULL == str) return NULL;

   root.child = NULL;
   if ((ret = xml_alloc(&root)) == NULL)
   {
      T_ERROR("Out of memory root child");
      return NULL;
   }

   if ((p = XML_ParserCreate(NULL)) == NULL)
   {
      T_ERROR("Out of memory parser create");
      return NULL;
   }

   XML_SetUserData(p, &ret);
   XML_SetElementHandler(p, xml_el_start, xml_el_end);
   XML_SetCharacterDataHandler(p, xml_charhndl);

   if (XML_Parse(p, str, len, 1) == 0)
   {
      T_ERROR("Parse error at line [%d]:[%s]", (int)XML_GetCurrentLineNumber(p), XML_ErrorString(XML_GetErrorCode(p)));
      xml_free(ret);
      ret = NULL;
   }

   if (ret != NULL)
      ret->parent = NULL;

   XML_ParserFree(p);
   return ret;
}


XML_node * XMLreader::xml_get(const char *key, XML_node *ref, int recurs)
{
   XML_node *ret = NULL;

   if (ref->key != NULL && !strcmp(ref->key, key)) {
      return ref;
   }

   if (recurs && ref->child != NULL && (ret = xml_get(key, ref->child, recurs)) != NULL) {
      return ret;
   }

   if (ref->next != NULL && (ret = xml_get(key, ref->next, recurs)) != NULL) {
      return ret;
   }

   return NULL;
}

#endif
