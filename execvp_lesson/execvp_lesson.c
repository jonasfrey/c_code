
// c file 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main() {
   
   int n_len = 1000;

   char * s_lineinput = malloc(n_len);
   char * s_fgets_ret = malloc(n_len);


   s_fgets_ret = fgets(s_lineinput,n_len, stdin);

   while(s_fgets_ret!=NULL){
      printf("your string is: %s", s_lineinput);
      

      int n_i = 0;
      char *s_part = strtok(s_lineinput, " ");
      char *a_args[10];

      while (s_part != NULL)
      {
         a_args[n_i++] = s_part;
         s_part = strtok (NULL, " ");
      }
      
      int n_ret = execvp(a_args[0], a_args);

      s_fgets_ret = fgets(s_lineinput,n_len, stdin);
      
      printf("n_ret: %i\n", n_ret);
   }


   
   return 0;
}
