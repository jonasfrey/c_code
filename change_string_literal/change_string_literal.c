
// c file 
#include <stdio.h>

void f_change_content_of_string_literal(){
   
   char * s_my_str = "this is a string literal"; 

   // any attempt to change a string literal
   s_my_str[10] = 'B'; 
   // will result in undefined behavior => segmentation fault (core dumped)
}

void f_change_whole_string_literal(){
   // the string "between theese double quotes this is a string literal" has a pointer somewhere in memory
   char * s_my_str = "between theese double quotes this is a string literal"; 
   // the s_my_str pointer will be that pointer
   
   // when we do 
   s_my_str = "i am another string literal";
   // we change the pointer s_my_str to the pointer of the literal "i am another string literal"

   printf("\n%s\n", s_my_str);
   printf("\n%p\n", s_my_str);
}

void f_same_string_literal_different_pointer_questionmark(){
// this function demonstrates, how the same string has the same adress
// maybe this depends on the compiler optimization level ? 
   char * s_my_str1 = "i have 1:1 the same content but still a different pointer in memory?";
   char * s_my_str2 = "i have 1:1 the same content but still a different pointer in memory?";

   printf("pointer of s_my_str1: %p\n", (void*) s_my_str1);
   printf("pointer of s_my_str1: %p\n", (void*) s_my_str1);
   // printf("pointer of s_my_str1: %p\n", (void*) s_my_str1); // Whenever using "%p" on printf, you should cast the pointer to void * as in printf("%p", (void *)str);  https://stackoverflow.com/questions/164194/why-do-i-get-a-segmentation-fault-when-writing-to-a-char-s-initialized-with-a
   // printf("pointer of s_my_str2: %p\n", (void*) s_my_str2);

   // after this experiment we will see that both pointers have the same value

   char * s_my_str3 = "i have not the same content and of course i wont have the same pointer?";
   printf("pointer of s_my_str3: %p\n", s_my_str3);
   
}

int main() {

   // f_change_content_of_string_literal();
   // f_change_whole_string_literal();
   f_same_string_literal_different_pointer_questionmark();
   return 0;
}

