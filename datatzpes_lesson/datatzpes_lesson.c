
// c file 
#include <stdio.h>

int main() {
   /* my first program in C */
   printf("main function called");
   
   //cast to int 
   // does it get rounded  up or down?
   printf("\n(int) 1.2: %i", (int) 1.2); // round down to 1?
   printf("\n(int) 1.8:  %i", (int) 1.8); // round up to 2?
   // no always rounded down 


   //cast to float 
   // does it get rounded  up?
   printf("\n(float) 1.2123468: %f", (float) 1.2123468);
   //                       ^   gets rounded up to 7 
   printf("\n(float) 1.2123463: %f", (float) 1.2123463);
   //                       ^   gets rounded down to 6 

   printf("\n(float) 1.2123465: %f", (float) 1.2123465);
   //                       ^   gets rounded down to 7 
   //yes!


   printf("\n(float) 1.8:  %f", (float) 1.8); 

   return 0;

}
