
// c file 
#include <stdio.h>
#include <math.h>

int main() {
   int n = 1000000; 
   for(int i = 2; i < n; i++){
      int is_prime = 1;
      for(int j = 2; j < sqrt((float)i); j++){
         if(i % j == 0){
            is_prime = 0;
            break;
         }
      }
      if(is_prime){
         printf("\n%i", i);
      }
   }
}
