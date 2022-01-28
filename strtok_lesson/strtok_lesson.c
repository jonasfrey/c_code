#include <string.h>
#include <stdio.h>

int main () {
   
   char s_string_pointer[100] = "split.me.by.points.please";
   const char s_separator[2] = ".";
   char *s_part;
   
   /* get the first token */
   s_part = strtok(s_string_pointer, s_separator);
   
   /* walk through other tokens */
   while( s_part != NULL ) {
      printf( " %s\n", s_part );
      s_part = strtok(NULL, s_separator);
   }
   
   return(0);
}