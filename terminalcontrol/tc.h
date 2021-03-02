#ifndef TERMINA_CONTROL_H_
#define TERMINA_CONTROL_H_

/* Includes */
#include <stdio.h>
#include <ioctl.h>

/* MACROS */
#define COLOR_RESET       "\x1B[0m"
#define COLOR_RED         "\x1B[1;31m"
#define COLOR_GREEN       "\x1B[1;32m"
#define COLOR_YELLOW      "\x1B[1;33m"
#define COLOR_BLUE        "\x1B[1;34m"
#define COLOR_MAGENTA     "\x1B[1;35m"
#define COLOR_CYAN        "\x1B[1;36m"
#define COLOR_WHITE       "\x1B[1;37m"

#define COLOR_B_RESET     "\x1B[0m"
#define COLOR_B_RED       "\x1B[0;31m"
#define COLOR_B_GREEN     "\x1B[0;32m"
#define COLOR_B_YELLOW    "\x1B[0;33m"
#define COLOR_B_BLUE      "\x1B[0;34m"
#define COLOR_B_MAGENTA   "\x1B[0;35m"
#define COLOR_B_CYAN      "\x1B[0;36m"
#define COLOR_B_WHITE     "\x1B[0;37m"

#define COLOR_BG_RESET    "\x1B[40m"
#define COLOR_BG_RED      "\x1B[41m"
#define COLOR_BG_GREEN    "\x1B[42m"
#define COLOR_BG_YELLOW   "\x1B[43m"
#define COLOR_BG_BLUE     "\x1B[44m"
#define COLOR_BG_MAGENTA  "\x1B[45m"
#define COLOR_BG_CYAN     "\x1B[46m"
#define COLOR_BG_WHITE    "\x1B[47m"

/* Functions */
void tc_clear_screen();
void tc_move_cursor(unsigned x, unsigned y);
void tc_get_cols_row(int *cols, int *rows);


#endif /* ! TERMINA_CONTROL_H_ */
