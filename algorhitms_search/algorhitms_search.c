
// c file 
#include <stdio.h>
#include <stdlib.h>
int f_n_linear_search(
   int n_length_a_n_numbers,
   int * a_n_numbers, 
   int n_target_number
){

   int n_index_a_n_numbers = 0; 
   int b_found = 0;
   while (n_index_a_n_numbers < n_length_a_n_numbers)
   {
      if(a_n_numbers[n_index_a_n_numbers] == n_target_number){
         b_found = 1; 
         break;
      }
      n_index_a_n_numbers++;
   }
   
   printf("b_found:%i\n", b_found);
   printf("n_index_a_n_numbers:%i\n", n_index_a_n_numbers);

   if(b_found){
      return n_index_a_n_numbers;
   }else{
      return -1; 
   }

   
}
double f_n_random_normalized(){

   return (double)rand() / (double)RAND_MAX ;

}
void f_print_array_items(
   int n_length_array,
   int * a_n_array 
){
   printf("[");
   for(int n_i = 0; n_i < n_length_array; n_i++){
      printf("%i", a_n_array[n_i]);
      if(n_i < n_length_array-1){
         printf(",");
      }
   }
   printf("]");

}
void f_demo_linear_search(){
   int n_length_a_n_random = 10;
   int a_n_random[n_length_a_n_random];
   int n_random_max = 20;
   int i;
   for (i = 0; i < n_length_a_n_random; i++) {
      int n_random = (int) (f_n_random_normalized()*n_random_max);
      a_n_random[i] = n_random;

   }
   f_print_array_items(n_length_a_n_random, a_n_random);

   int n_index = f_n_linear_search(
      n_length_a_n_random,
      a_n_random,
      18
   );
   printf("n_index: %i\n", n_index);

}
int main() {

   f_demo_linear_search();

}
