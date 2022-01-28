
// c file 
#include <stdio.h>
#include <stdlib.h>

char* give_me_a_string(int length){

   // not working 
   char *the_string;

   the_string = (char *) malloc(length);

   return the_string;
}

int main() {

   char * string = give_me_a_string(5);
   
   printf("\n%s", string);

   return 0;
}
