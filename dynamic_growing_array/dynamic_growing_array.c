
// c file 
#include <stdio.h>
#include <stdlib.h>

void f_dynamic_allocated_array(){
   int n_i; 
   // type 
   int * a_n_number = malloc(sizeof(int));

   n_i = 0; 
   while(n_i < 10){
      a_n_number = realloc(a_n_number, n_i+1 * sizeof(int));
      a_n_number[n_i] = (n_i * 3)  % __INT_MAX__;
      n_i+=1;
   }

   n_i = 0; 
   while(n_i < 10){
      // printf("a_n_number[%i]: %i\n", n_i, a_n_number[n_i]);
      n_i+=1;
   }

   free(a_n_number);
}

void f_dynamic_array_manual(){
   char * a_char = malloc(1);
   a_char = realloc(a_char, 10);
   long n_adress_of_a_char = (long) &a_char;
   printf("address %li\n", n_adress_of_a_char);

   a_char[0] = 10;

   printf("value %i\n", a_char[0]);
   // int a_char_address = ()
}


void f_wtf_why_is_this_working(){

   int * a_n_number = malloc(sizeof(int));

   a_n_number[0] = 22;
   a_n_number[1] = 42;
   a_n_number[2] = 55;
   a_n_number[3] = 12;
   a_n_number[4] = 2;
   a_n_number[5] = 3;
   a_n_number[6] = 1;
   // a_n_number[7] = 99;
   // a_n_number[8] = 123;
   // a_n_number[9] = 321;

   printf("a_n_number[0]: %i\n", a_n_number[0]);
   printf("a_n_number[1]: %i\n", a_n_number[1]);
   printf("a_n_number[2]: %i\n", a_n_number[2]);
   printf("a_n_number[3]: %i\n", a_n_number[3]);
   printf("a_n_number[4]: %i\n", a_n_number[4]);
   printf("a_n_number[5]: %i\n", a_n_number[5]);
   // printf("a_n_number[6]: %i\n", a_n_number[6]);
   // printf("a_n_number[7]: %i\n", a_n_number[7]);
   // printf("a_n_number[8]: %i\n", a_n_number[8]);
   // printf("a_n_number[9]: %i\n", a_n_number[9]);

}





int main() {
   
   // f_wtf_why_is_this_working();
   // f_dynamic_allocated_array();
   f_dynamic_array_manual();
   return 0;
}
