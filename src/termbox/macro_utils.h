#ifndef TERMBOX_MACRO_UTILS_H
#define TERMBOX_MACRO_UTILS_H

/**
 *  @def SO_IMPORT
 *
 *  Configures symbol visibility for shared objects
 *  when using a modern version of GCC.
 */

#if __GNUC__ >= 4
#    define SO_IMPORT __attribute__((visibility("default")))
#else
#    define SO_IMPORT
#endif

#endif // TERMBOX_MACRO_UTILS_H
