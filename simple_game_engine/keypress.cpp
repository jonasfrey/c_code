#include <curses.h>

int
main (void)
{
  int c;

  initscr ();
  noecho ();
  timeout (0);

  while (1)
    {
      c = getch ();
      printf("--- --- ---\r\n");
      printf("--- --- ---\r\n");
      printf("--- --- ---\r\n");
      printf("--- --- ---\r\n");
      if (c != ERR)
      {
        printw ("%c", c);
      }
      if (c == 27)
      {
        break;
      }
    //   printf("key is %c\n", c);
    }

  echo ();
  endwin ();
  return 0;
}

// g++ -o keypress keypress.cpp -lcurses