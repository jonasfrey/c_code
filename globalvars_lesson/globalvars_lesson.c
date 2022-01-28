
// c file 
#include <stdio.h>

int n_global_num = 11235;

void increment_global_var(){
   n_global_num++;
   printf("%i\n", n_global_num); 
}
// int n_global_num = 11235; // not working, because definintion is after function which uses it 

int main() {
   printf("main function called\n");
   
   printf("%i\n", n_global_num); 
   
   increment_global_var();

   printf("%i\n", n_global_num); 

   n_global_num ++;

   increment_global_var();

   printf("%i\n", n_global_num); 

   return 0;
}
