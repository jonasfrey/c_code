
// c file 
#include <stdio.h>
#include "./../c_helpers/bitshifting_helpers.c"

// void print_as_binary(unsigned n)
// {
//     unsigned i;
//     printf("\n");
//     for (i = 1 << 31; i > 0; i = i / 2)
//         (n & i) ? printf("1") : printf("0");
// }

//helper function 
/* --- PRINTF_BYTE_TO_BINARY macro's --- */
#define PRINTF_BINARY_PATTERN_INT8 "%c%c%c%c%c%c%c%c"
#define PRINTF_BYTE_TO_BINARY_INT8(i)    \
    (((i) & 0x80ll) ? '1' : '0'), \
    (((i) & 0x40ll) ? '1' : '0'), \
    (((i) & 0x20ll) ? '1' : '0'), \
    (((i) & 0x10ll) ? '1' : '0'), \
    (((i) & 0x08ll) ? '1' : '0'), \
    (((i) & 0x04ll) ? '1' : '0'), \
    (((i) & 0x02ll) ? '1' : '0'), \
    (((i) & 0x01ll) ? '1' : '0')

#define PRINTF_BINARY_PATTERN_INT16 \
    PRINTF_BINARY_PATTERN_INT8              PRINTF_BINARY_PATTERN_INT8
#define PRINTF_BYTE_TO_BINARY_INT16(i) \
    PRINTF_BYTE_TO_BINARY_INT8((i) >> 8),   PRINTF_BYTE_TO_BINARY_INT8(i)
#define PRINTF_BINARY_PATTERN_INT32 \
    PRINTF_BINARY_PATTERN_INT16             PRINTF_BINARY_PATTERN_INT16
#define PRINTF_BYTE_TO_BINARY_INT32(i) \
    PRINTF_BYTE_TO_BINARY_INT16((i) >> 16), PRINTF_BYTE_TO_BINARY_INT16(i)
#define PRINTF_BINARY_PATTERN_INT64    \
    PRINTF_BINARY_PATTERN_INT32             PRINTF_BINARY_PATTERN_INT32
#define PRINTF_BYTE_TO_BINARY_INT64(i) \
    PRINTF_BYTE_TO_BINARY_INT32((i) >> 32), PRINTF_BYTE_TO_BINARY_INT32(i)

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

int f_n_combine_two_8_bit_integers_to_one_16_bit(
   int n_8bit_high, 
   int n_8bit_low
){
   //for example 
   // n_8bit_high = 1111 0011 // 243
   // n_8bit_low = 1111 1001 // 249

   // target 
   // 11110011 11111001 //->  62457

   // 0000 0000 1111 1100 //n_8bit_high
   // to << 8 left
   // 1111 1100 0000 0000
   int n_combined_to_16bit = n_8bit_high << 8; 

   // setting the low 8 bits

   // 1111 1100 0000 0000 // n_8bit_high shifted << 8  
   // OR 
   // 0000 0000 1111 1001 // n_8bit_low
   // -------------------
   // 1111 1100 1111 1001 

 
   n_combined_to_16bit = n_combined_to_16bit | n_8bit_low;

   return n_combined_to_16bit;

}
void f_combine_8_bit_values(){

   int n_high_8_bit = 0b11110011; // 243 
   int n_low_8_bit = 0b11111001; // 249
   int n_16_bit_value = f_n_combine_two_8_bit_integers_to_one_16_bit(
      n_high_8_bit, 
      n_low_8_bit
   );
   printf("n_high_8_bit:"PRINTF_BINARY_PATTERN_INT8"\n", PRINTF_BYTE_TO_BINARY_INT8(n_high_8_bit));
   printf("n_low_8_bit:"PRINTF_BINARY_PATTERN_INT8"\n", PRINTF_BYTE_TO_BINARY_INT8(n_low_8_bit));
   printf("n_16_bit_value:"PRINTF_BINARY_PATTERN_INT16"\n", PRINTF_BYTE_TO_BINARY_INT16(n_16_bit_value));
}
int main()
{
   // check_if_a_nth_bit_is_set();
   f_combine_8_bit_values();
    return 0;
}
