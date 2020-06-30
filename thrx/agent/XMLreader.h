
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

#ifndef _XML_READER_H_
#define _XML_READER_H_ 1


#ifdef OS_LINUX
#include <linux/types.h>
#endif /* OS_LINUX */

struct XML_node 
{
   char *key;
   char *value;
   char **attr;
   struct XML_node *child;
   struct XML_node *parent;
   struct XML_node *next;
};

struct SStr {
   char* s;
   int len;
};


#define BUFSIZE 8192


class XMLreader
{
public:

   /**
    * Parse xml-node. Return root node.
    * TODO: // temporrary static
    */
   static XML_node *xml_parse(const char *filename);

   /**
    * TODO://
    * TODO: // temporrary static
    */
   static int xml_parse_with_report(const char *filename, char *erbuf, int erlen);

   /**
    * TODO: //
    * TODO: // temporrary static
    */
   static XML_node *xml_get(const char *key, XML_node *ref, int recurs);

   /**
    * TODO: //
    * TODO: // temporrary static
    */
   static XML_node *xml_node_str(char *str, int len);

   /**
    * TODO: should implement with checking memory-leaks.
    * TODO: // temporrary static
    */
   static void xml_free(XML_node *node);

private:

   static XML_node *xml_alloc(XML_node *parent);

   static void xml_el_start(void *data, const char *name, const char **attr);

   static void xml_el_end(void *data, const char *name);

   static void xml_charhndl(void *data, const char *s, int len);

};

#endif
