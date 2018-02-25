#define HAVE_STDBOOL_H

#ifdef HAVE_STDBOOL_H
  #include <stdbool.h>
#elif !defined(__cplusplus)
  typedef char bool;
#endif

#define HAVE___BUILTIN_EXPECT

#define HAVE___ATTRIBUTE__

#ifdef HAVE___ATTRIBUTE__
  #define CMARK_ATTRIBUTE(list) __attribute__ (list)
#else
  #define CMARK_ATTRIBUTE(list)
#endif

#if 1
#ifndef U3_ALL
#define U3_ALL
#define malloc(a) u3a_malloc(a)
#define calloc(a,b) u3a_calloc(a,b)
#define realloc(a,b) u3a_realloc(a,b)
#define free(a) u3a_free(a)
/* From i/n/a.h
*/
  /* u3a_malloc(): aligned storage measured in bytes.
  */
    extern void*
    u3a_malloc(size_t len_i);

  /* u3a_calloc(): aligned storage measured in bytes.
  */
    extern void*
    u3a_calloc(size_t num_i, size_t len_i);

  /* u3a_realloc(): aligned realloc in bytes.
  */
    extern void*
    u3a_realloc(void* lag_v, size_t len_i);

  /* u3a_free(): free for aligned malloc.
  */
    extern void
    u3a_free(void* tox_v);
#endif
#endif
