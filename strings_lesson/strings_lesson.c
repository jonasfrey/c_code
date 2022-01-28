
// c file 
#include <stdio.h>

#include <string.h>
#include "./../c_helpers/dnd.c"
#include "./../c_helpers/bitshifting_helpers.c"

void some_stuff(){
   /* my first program in C */
   printf("main function called");

   char s_a_string[] = "give me string"; 

   for(int i = 0; i<strlen(s_a_string); i++){
      printf("\n%c", s_a_string[i]);
   }
   
   char s_input[20];
   
   scanf("%s",s_input);

   printf("%s", s_input);

   for(int i = 0; i< strlen(s_input); i++){

      printf("\nchar is %c: ", s_input[i]);
      printf("\nnum is %i: ", s_input[i]);

      if(s_input[i] > 90){
         
         int uppercase_num = s_input[i] -32;

         printf("\n UPPPERCASE char is %c: ", uppercase_num);
         printf("\n UPPERCASE num is %i: ", uppercase_num);
         
      }

   }
}

const char* f_s_ill_return_a_string(){
   return "i was returned from a function";
}

void strings_in_different_scopes(){
   
   //printf("\n %s", f_s_ill_return_a_string());

   // char[5] = "";

}

void strlen_and_strnlen(){

   char asdf[4] = "asdf"; 
   printf("strlen(asdf[4] = \"asdf\")):%li", strlen(asdf));

   //now imagine we have a string where there is no '\0'

   char string_without_null_terminator[] = "asdfasdfasdfasdfasdfasdfasdfasdf";  // 8*asdf -> length = 8*4=32, nulter = 32
   string_without_null_terminator[32] = 'a';// overwriting nulter by will

   // int len = strlen(string_without_null_terminator);/// strlen would maybe search forever
   // dnd(len);
   int strnlen_len;
   strnlen_len = strnlen(string_without_null_terminator, 10);// 10 is now a fallback , if strlen was not found earlier, it will return 10
   dnd(strnlen_len);
   strnlen_len = strnlen(string_without_null_terminator, 50);// 50 is now a fallback , if strlen was not found earlier, it will return 50
   dnd(strnlen_len);


      
   // printf("strnlen(asdf[4] = \"asdf\")):%li", strnlen(asdf));
}

int get_strlengt_of_unicode_string(char * string){
   int n_strlen_len = (strlen(string));
   print_as_binary(string[0]);
   int n_unicode_stringlen = 0; 

   // ascii 0         -       127
   //       0000'0000 - 0111'1111

   // utf 8
   //       128       - 1,112,064
   //       1100'0000 - 1111'0xxx 10xx'xxxx 10xx'xxxx 10xx'xxxx
   
   // 110x'xxxx 10xx'xxxx 10xx'xxxx 
   // ^^ two    cont.byte cont.byte

   // 1110'xxxx 10xx'xxxx 10xx'xxxx 10xx'xxxx
   // ^^^ three cont.byte cont.byte cont.byte

   // 1111'0xxx 10xx'xxxx 10xx'xxxx 10xx'xxxx
   // ^^^^ four cont.byte cont.byte cont.byte
   

   // so if the int of the char is > 127 it is has continuition bytes
   int n_char_index = 0;
   int n_cont_bytes = 0;
   int n_nth_bit = 8;

   for(int i = 0; i < n_strlen_len; i ++){
      
      char n_char = string[n_char_index];
      n_nth_bit = 8; 
      n_cont_bytes = 0; 
      while(f_b_nth_bit_is_set(n_char, n_nth_bit)){
         
         printf("%d", n_char);
         print_as_binary(n_char);

         n_cont_bytes ++; 
         n_nth_bit --; 
      }
      i += n_cont_bytes; 
      n_char_index = i; 

   }

   n_unicode_stringlen = n_char_index+1;
   return n_unicode_stringlen;
}

void unicode_stuff(){

   char simple_ascii[] = "asdf";
   //returns number of bytes in string, ascii has 1 char = 1 byte
   int strlen_simple_ascii = strlen(simple_ascii);
   dnd(strlen_simple_ascii);

   char arabic_alif[] = "ااا"; 
   // returns numbver of bytes in string, utf-8 has 1 char = 1-4 bytes...
   int strlen_arabic_alif = strlen(arabic_alif);
   dnd(strlen_arabic_alif);// we have 3 chars  ااا  but strlen returs 6...


   dnd(get_strlengt_of_unicode_string(arabic_alif));

}


void string_by_index(){
   char * s_test = "asdf=1=2";

   printf("%s", s_test);
}

int main() {

   // some_stuff();

   // strlen_and_strnlen();

   // unicode_stuff();


   // strings_in_different_scopes()

   string_by_index();
   return 0;
}
