#ifndef FONT_H_
#define FONT_H_

#include <lcd.h>

#define FONTDATAMAX 11264
#define HIGH    22
#define WIDTH   12

extern void display_string_buf(int buf_n, int x, int y, const char *str, int col);

#endif
