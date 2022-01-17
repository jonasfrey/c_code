
// c file 
#include <stdio.h>
#include "./../c_helpers/dnd.c"

int main() {
   /* my first program in C */
   printf("main function called");

   int a_my_numbers[5] = {1,2,3,4,5}; 
   
   dnd((int) sizeof(a_my_numbers));
   
   for(int i = 0; i < (sizeof(a_my_numbers)/sizeof(a_my_numbers[0])); i++){
      printf("\nint :%i", a_my_numbers[i]);
   }
   int n_i = a_my_numbers[4];
   dnd(n_i);

   // int n_i_2 = a_my_numbers[(1,4)];
   // dnd(n_i_2);

   int a_my_2d_nums[5][2] = {{1,2},{1,2},{1,2},{1,2},{1,2}};

   int length_first_dimension = (sizeof(a_my_2d_nums)/sizeof(a_my_2d_nums[0]));

   // dnd(a_my_2d_nums[0,1]);
   // int i = a_my_2d_nums[1, 1];
   // dnd(i);

   for(int i = 0; i < length_first_dimension; i++){
      printf("\nint :%p", a_my_2d_nums[i]);

      dnd(a_my_2d_nums[i][0]);
   }

   
   return 0;
}
