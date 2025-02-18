#include <stdio.h>
#include <string.h>

#define BOARD_WIDTH 7
#define BOARD_HEIGHT 6

// Constants to print in bold red text, bold yellow text, and to reset text style
#define START_RED "\033[1m\033[31m"
#define START_YELLOW "\033[1m\033[33m"
#define RESET_COLOR "\033[0m"

int main() {
  // Print text in the default terminal colors
  printf("This is normal text.\n");

  // Now print something in red
  printf(START_RED);
  printf("This text will appear in red.\n");
  printf(RESET_COLOR);

  // Now print something in yellow
  // Notice that you can put string constants next to each other in C and the compiler will just combine them.
  printf(START_YELLOW "This text will appear in yellow.\n" RESET_COLOR);

  // Print something again. This will be back to the default oclor because we ended each block of output above with RESET_COLOR
  printf("This is normal text again.\n");

  return 0;
}
