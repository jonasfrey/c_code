
// c file 
#include <math.h>
#include <stdio.h>
#include <string.h>


char * f_s_encode_bytes(
   char * s_input
){
   // utf max num is 
   // 0b11110111 10111111 10111111 10111111
   long n_max_character_num_utf8 = 0b11110111101111111011111110111111;

   // ascii is simply 2^8 -1 => 0b11111111
   long n_max_character_num_ascii = 011111111;

   // an array where the index is the 
   // ascii number of the character 
   // and the value is the number of counts of this 
   // character
   // the string AAABBD would be 
   // [
   //     0: 0,
   //    ...
   //    65: 3, 
   //    66: 2, 
   //    67: 0, 
   //    68: 1, 
   //    ...
   //    255:0
   // ]

   long a_character_count[n_max_character_num_ascii];
   int n_char_index = 0; 
   while(n_char_index < strlen(s_input)){
      printf("%c\n", a_character_count[n_char_index]);
      n_char_index ++;
   }
   char * s_output;
   return s_input; 
}
void f_test_1(){
   char * s_string = "this is a simple text which uses 41 bytes";
   f_s_encode_bytes(s_string);
}
int main() {
   f_test_1();
}
