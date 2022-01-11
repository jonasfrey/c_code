#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main (int argc, char const *argv[]) {

  printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_RESET "\n");


   int n_end = 128; 
   int n_start = 10; 
   
   char s_n_current[3];

   while(n_start < n_end){

      sprintf(s_n_current, "%d", n_start);

      n_start++; 
      printf("\x1b[");
      printf("%s", s_n_current);
      printf("m");
      printf(" \\x1b[%s: ", s_n_current);
      printf("quick brown fox jumps over the lazy dog" ANSI_COLOR_RESET "\n");
   }

  return 0;
}