
// c file 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
   // long a_character_count[n_max_character_num_ascii];

   // MISSISSIPPI 
   // 
   // a_character_value_index_map 
   // [
   //    ...
   //    (index) ascii  :(value) how many times the char occurs in the string
   //    num of char 
   //    73('I')        : 4, 
   //    77('M')        : 1, 
   //    80('P')        : 2, 
   //    83('S')        : 4, 
   //    ...
   // ]
   long a_character_value_index_map[n_max_character_num_ascii];

   int n_index_s_input = 0; 
   while(n_index_s_input < strlen(n_index_s_input)){
      u_int8_t n_ascii_num_of_char = s_input[n_index_s_input];
      if(a_character_value_index_map[n_ascii_num_of_char] == NULL){
         a_character_value_index_map[n_ascii_num_of_char] = 1;
      }else{
         a_character_value_index_map[n_ascii_num_of_char]++;
      }
      n_index_s_input ++;
   }
   char * s_output;
   return s_input; 
}
void f_test_1(){
   char * s_string = "this is a simple text which uses 41 bytes";
   f_s_encode_bytes(s_string);
}
void f_test_mississippi(){
   char * s_string = "MISSISSIPPI";
   f_s_encode_bytes(s_string);
}
int main() {
   // f_test_1();
   f_test_mississippi();
}
