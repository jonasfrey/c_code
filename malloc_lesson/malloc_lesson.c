
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void does_realloc_delete_the_content(){
//this function shows, that realloc does not change the content 
// of in this case the char pointer/string
   char * s = malloc(2);
   s[0] = 'a'; 
   s[1] = '\0';
   printf("before realloc: %s\n", s);

   s = realloc(s, 4); 
   printf("after realloc: %s\n", s);

   s[1] = 'b';
   s[2] = 'c';
   s[3] = '\0';

   printf("after realloc and changing chars by [1], [2] and [3]: %s\n", s);

}

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
int should_we_free() {
   //malloc_simple();
   // malloc_and_free();

   char * s_test = malloc(3);
   s_test = "ho"; 
   printf("s: %s", s_test);
   // should we free now ? 
   free(s_test); // segmentation fault core dumped
   return 0;
}
int should_we_free2() {
   char * s_test = malloc(3);
   s_test = "ho";
   printf("s: %s", s_test);
   // should we free now ? 
   free(s_test); // segmentation fault core dumped
   return 0;
}

int should_we_free3() {
   char * s_test = malloc(3);
   s_test[0] = 'h'; 
   s_test[1] = 'o'; 
   printf("s: %s", s_test);
   // should we free now ? 
   free(s_test); // segmentation fault core dumped
   return 0;
}


int should_we_free4() {
   char * s_test = malloc(3);
   //s_test = {'h', 'o', '\0'};
   // char s_test2[3] = {'h', 'o', '\0'}; // error attempt to free a non heap object
      
      // printf("s: %s", s_test);
      // // should we free now ? 
      // // free(s_test); // segmentation fault core dumped
      // free(s_test2);
   return 0;
}


int main(){
   does_realloc_delete_the_content();
   return 0; 
}