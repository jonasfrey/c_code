
// c file 
#include <stdio.h>
#include <stdlib.h>

int main() {
   /* my first program in C */
   printf("main function called");

   char *str; 

   str = (char *) malloc(15); 
   strcpy(str, "asdfasdf "); 
   printf("string %s, adress: %u\n", str, str); 
   
   // re allocating

   str = (char *) realloc(str, 25); 
   strcat(str, ".com"); 
   printf("string : %s, address: %u", str, str);


   return 0;
}
