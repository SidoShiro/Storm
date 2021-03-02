#include "tc.h"


void tc_clear_screen() {
  // puts("\x1B[2J");
  printf("\x1B[2J");
}

void tc_move_cursor(unsigned x, unsigned y) {
  printf("\033[%d;%dH", x, y);
}

void tc_get_cols_row(int *cols, int *rows) {
  struct winsize size;
  ioctl(1, TIOCGWINSZ, &size);
  *cols = size.ws_col;
  *rows = size.ws_row;
}


