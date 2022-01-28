
// c file 
#include <stdio.h>
#include <stdlib.h>

void legga(){
   int n_max_chars =1024;
   char *s_fgets_return;
   char *s_line = malloc(n_max_chars+1);
   
   s_fgets_return =fgets(s_line, n_max_chars, stdin);
   while(s_fgets_return != NULL){
      printf("%s\n", s_line); 
      s_fgets_return = fgets(s_line, n_max_chars, stdin);
   }

}
void nidsolegga(){
   int n_max_chars = 1024; 
   char *s_line = malloc(n_max_chars+1);

   while(fgets(s_line, n_max_chars ,stdin)!= NULL){
      
      fgets(s_line, n_max_chars ,stdin);
      printf("%s\n", s_line);
   }

}
int main() {
   // nidsolegga();
   legga();
   return 0;
}
