#ifndef TERMBOX_UTF8_H
#define TERMBOX_UTF8_H

#include <stdint.h>
#include <termbox/macro_utils.h>

/**
 * Converting a '\0' character to UTF-8 returns this error
 */
#define TB_UTF8_EOF -1

/**
 * Get the number of bytes used to represent a given character in utf-8.
 *
 * @param c character to calculate length of
 * @return number of bytes used to represent c
 */
SO_IMPORT int tb_utf8_char_length(char c);

/**
 * Encode a C character as UTF8
 *
 * @warning It is very likely that multiple elements of c are read
 *          to fully parse a UTF8 character! Make sure to increment your
 *          iterator by the return value of this function (if successful).
 *
 * @param out 4-Byte block that will contain the UTF8 representation of c
 * @param c input character that should be encoded as UTF8
 * @return Number of Bytes read from c to parse a UTF8 character. In case of an
 *         Error it returns a value < 0.
 */
SO_IMPORT int tb_utf8_char_to_unicode(uint32_t *out, const char *c);

/**
 * Convert a UTF8 4-Byte block to a C character array.
 *
 * @param out character array that contains the C representation of c
 * @param c   UTF8 character that should be represented as C char array
 * @return number of elements in out needed to encode c
 */
SO_IMPORT int tb_utf8_unicode_to_char(char *out, uint32_t c);

#endif // TERMBOX_UTF8_H
