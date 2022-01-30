
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void malloc_simple(){

   char *str; 

   str = (char *) malloc(15); 
   strcpy(str, "asdfasdf "); 
   printf("string %s, adress: %p\n", str, str); 
   
   // re allocating

   str = (char *) realloc(str, 25); 
   strcat(str, ".com"); 
   printf("string : %s, address: %p", str, str);
}

void malloc_and_free(){
   char * s_test = malloc(3);
   s_test = "ho"; 
   printf("s: %s", s_test);
   // should we free now ? 
   //    free(s_test); // segmentation fault core dumped
   free(s_test);
}
int maino() {
   //malloc_simple();
   // malloc_and_free();

   char * s_test = malloc(3);
   s_test = "ho"; 
   printf("s: %s", s_test);
   // should we free now ? 
   free(s_test); // segmentation fault core dumped
   return 0;
}
int main2() {
   char * s_test = malloc(3);
   s_test = "ho";
   printf("s: %s", s_test);
   // should we free now ? 
   free(s_test); // segmentation fault core dumped
   return 0;
}

int main3() {
   char * s_test = malloc(3);
   s_test[0] = 'h'; 
   s_test[1] = 'o'; 
   printf("s: %s", s_test);
   // should we free now ? 
   free(s_test); // segmentation fault core dumped
   return 0;
}

int main() {
   char * s_test = malloc(3);
   //s_test = {'h', 'o', '\0'};
   char s_test2[3] = {'h', 'o', '\0'};
   
   printf("s: %s", s_test);
   // should we free now ? 
   // free(s_test); // segmentation fault core dumped
   free(s_test2);
   return 0;
}

