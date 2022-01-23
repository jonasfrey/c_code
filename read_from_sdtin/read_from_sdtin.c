#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_SIZE 512

int main( void )
{

   char a_strings[512][MAX_STR_SIZE];

   char *str = malloc(MAX_STR_SIZE);     /* (1) */
   int i = 0;
   while(fgets(str, MAX_STR_SIZE, stdin) != NULL){
         fgets( str, MAX_STR_SIZE, stdin );
         strcpy( a_strings[i] ,str);
         // printf("str is %s", str);
      i++;
   }
   int a_strings_lengt = i; 



   free(str);

   return 0;
}