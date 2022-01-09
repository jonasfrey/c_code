
// c file 
#include <stdio.h>

int main() {
   
   // arrays are defined as follows 

   // type arrayName [ arraySize ];
   
   int a_natural_numbers [10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

   // to print the array we have to loop over it
   // to do so we have to find out the length of it 

   // the sized of the complete array in bytes
   int a_natural_numbers_size_in_bytes = sizeof(a_natural_numbers);

   // the size of any element of the array in bytes

   int a_natural_numbers_first_element_in_bytes = sizeof(a_natural_numbers[0]); 

   // now to get the numbers of elements / the length of the array 
   // we have to devide the whole size / the size of a single element 

   int a_natural_numbers_length = a_natural_numbers_size_in_bytes / a_natural_numbers_first_element_in_bytes; 

   // since c has no var_dump or console.log or print() or Console.WriteLine
   // we have to loop over the array to print every item 
   for(int i = 0; i < a_natural_numbers_length; i++){
      printf("\n index: %i ", i); 
      printf("\n value: %i", i);
   }
   

   // strings 
   // since a string is noting more than an array of chars we can create strings like so 

   char s_this_is_a_string [16] = "this is a string";

   printf("\nstring is: %s", s_this_is_a_string);

   printf("\nstring[8] is: %c", s_this_is_a_string[8]);

   // dynamic sized array ??? 

   // we cant even initialize an array with the size as a variable !, wtf 

   //    int n_array_size = 10; 
   //    int n_nat_nums [n_array_size] = {1,2,3,4,5,6,7,8,9,0}; 


   return 0;
}


