
// c file 
#include <stdio.h>

#include <string.h>
#include "./../c_helpers/dnd.c"

int main() {
   /* my first program in C */
   printf("main function called");

   char s_a_string[] = "give me string"; 

   for(int i = 0; i<strlen(s_a_string); i++){
      printf("\n%c", s_a_string[i]);
   }
   
   char s_input[20];
   
   scanf("%s",s_input);

   printf("%s", s_input);

   for(int i = 0; i< strlen(s_input); i++){

      printf("\nchar is %c: ", s_input[i]);
      printf("\nnum is %i: ", s_input[i]);

      if(s_input[i] > 90){
         
         int uppercase_num = s_input[i] -32;

         printf("\n UPPPERCASE char is %c: ", uppercase_num);
         printf("\n UPPERCASE num is %i: ", uppercase_num);
         
      }

   }


   return 0;
}
