#include <stdio.h>
#include "tc.h"

/* Inspired by Gregg Ink video */

void colors_test() {
  printf("%sHello I should be blue\n%s", COLOR_BLUE, COLOR_RESET);
  printf("%sHello I should be Magenta\n%s", COLOR_MAGENTA, COLOR_RESET);
  printf("%sHello I should be bold Yellow\n%s", COLOR_B_YELLOW, COLOR_B_RESET);
  printf("%sHello I should have a red background, uwu, spooky!%s%s\n",
      COLOR_BG_RED, COLOR_BG_RESET, COLOR_RESET);
}

void cursor_test() {
  tc_move_cursor(15, 15);
  printf("Hello there!\n");
}


void write_in_other_terminal(char *path, char *text) {
  FILE *otherTermOrFile = fopen(path, "w");
  fprintf(otherTermOrFile, "%s%s%s\n", COLOR_BLUE, text, COLOR_RESET);
  fclose(otherTermOrFile);
}


int main() {

  printf("Hi! my name is Sido\n");
  tc_clear_screen();
  colors_test();
  cursor_test();

  // can also use, /proc/{id}/{fd}"
  write_in_other_terminal("/dev/pts/3", "Hello I was teleported ^_^");

  

  return 0;
}
