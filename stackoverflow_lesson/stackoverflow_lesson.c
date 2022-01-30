
// c file 
#include <stdio.h>
#include <stdlib.h>
void is_this_heap_overflow(){
   int n = 1000;
   char * s = malloc(n);
   while (1)
   {
      n = n + 1000;
      printf("reallocating to %i bytes\n", n);
      /* code */
      s = realloc(s, n);
   }
   
}

void trying_to_cause_stackoverflow(){

}

int main() {
   is_this_heap_overflow();   
   return 0;
}
