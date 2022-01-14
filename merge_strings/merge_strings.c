
// c file 
#include <stdio.h>
#include <string.h>

int merge_strings(char s_a[], char s_b[]){

   char s_tmp[];
   strcpy(s_tmp, s_a);

   

   strcpy(s_a, s_tmp);
   free(s_tmp);

}
int main() {
   /* my first program in C */
   printf("main function called");
   
   return 0;
}
