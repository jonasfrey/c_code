
// c file 
#include <stdio.h>



void give_me_a_string(char* test){ 

   //    printf("\nyou gave me the string: %s", test); // error: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’ 
   printf("\nyou gave me the string: %s", test); // error: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’ 


}

void give_me_a_int(int test){

   printf("\nyou gave me the int: %i", test); 

}


int main() {
   /* my first program in C */
   printf("\nmain function called");

   // why can we pass ints? 
   int n_num = 1234;   
   give_me_a_int(n_num); 


   // but not strings 
   char* s_string = "asdf";
   
   printf("\n%%p pointer as hex: %p", s_string);
   printf("\n(int) %%li: pointer %li", (long) s_string);

   give_me_a_string(s_string);


   return 0;
}
