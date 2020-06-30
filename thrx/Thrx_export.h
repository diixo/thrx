
#ifndef THRX_EXPORT_H
#define THRX_EXPORT_H

#ifdef THRX_STATIC_DEFINE
#  define THRX_EXPORT
#elif defined(_MSC_VER )
#  ifndef THRX_EXPORT
#    ifdef thrx_EXPORTS
          /* We are building this library */
#      define THRX_EXPORT __declspec(dllexport)
#    else
          /* We are using this library */
#      define THRX_EXPORT __declspec(dllimport)
#    endif
#  endif
#else
#  define THRX_EXPORT
#endif

#endif /* THRX_EXPORT_H */
