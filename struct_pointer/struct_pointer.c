
// c file 
#include <stdio.h>

struct O_number_normalized{
   int n_min;
   int n_max; 
   float n;
   int n_unnormalized;
};

void f_update_n_unnormalized(
   struct O_number_normalized * o_number_normalized // we expect only the adress / index of the struct
){

   // to change struct data we need to use the arrow "parent->child" notation
   o_number_normalized->n_unnormalized = o_number_normalized->n * o_number_normalized->n_max;

}
int main() {

   struct O_number_normalized n_degrees;

   // in this scope we can change the struct data with the dot "parent.child" notation
   n_degrees.n_unnormalized = 0;
   n_degrees.n_max = 360;
   n_degrees.n_min = 0;
   n_degrees.n = 0.5;

   printf("n_degrees.n_unnormalized:%d\n", n_degrees.n_unnormalized);

   f_update_n_unnormalized(&n_degrees);// we need to pass the adress/index with '&'

   printf("n_degrees.n_unnormalized:%d\n", n_degrees.n_unnormalized);

   return 0;
}
