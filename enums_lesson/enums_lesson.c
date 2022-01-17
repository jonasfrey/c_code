
// c file 
#include <stdio.h>
#include "./../c_helpers/dnd.c"

int main() {
   /* my first program in C */
   printf("main function called");
   
   enum my_enumeration{alpha, beta, gamma}; 


   enum my_enumeration my_enumeration_var; 
   my_enumeration_var = alpha; 
   printf("\n%d", my_enumeration_var); 


   my_enumeration_var = beta; 
   printf("\n%i", my_enumeration_var);


   //    my_enumeration_var = asdf; //error:"asdf" undeclared
   my_enumeration_var = gamma;
    
   dnd(my_enumeration_var);

   return 0;
}
