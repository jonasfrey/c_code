
// c file 
#include <stdio.h>
#include "./../c_helpers/bitshifting_helpers.c"

void print_as_binary(unsigned n)
{
    unsigned i;
    printf("\n");
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}


void check_if_a_nth_bit_is_set(){

   // if we want to check if a bit is set
   // 8dec = 1000bin
   print_as_binary(8);

   // now we shift 8 to right 2
   // we get 0010 
   print_as_binary(8<<2);

   // if we want to check if the 3rd bit is set
   // 1000
   //  ^      

   // 1000
   // 0100 < this is our check number 
   //  ^ if bot bits are 1 , then the 3rd bit is set

   // how do we get a checknumber/mask ? 

   // 0001 < we start with 1dec = 0001bin
   // we left shift (3 - 1)=2 times
   // 0010 1 left shift
   // 0100 2 left shift
   //  ^ 3rd bit set

   int b_third_bit_is_set = (
                              8 
                              & 
                              1<<(3-1)
                        );
   if(b_third_bit_is_set){
      printf("\nthird bit in number 8 is set!");
   }else{
      printf("\nthird bit in number 8 is not set!");
   }

   // you can use this function 
   // from bitshifting_helpers.c

   if(f_b_nth_bit_is_set(8, 4)){
      printf("\nthe 4rth bit in number 8 is set!");
   }

}
int main()
{
   check_if_a_nth_bit_is_set();
    return 0;
}
