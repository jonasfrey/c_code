
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void f_i_take_strings(
   char * s_literal_readonly,
   char * s_stack_string,
   char * s_malloc_heap_string
){
   printf("f_i_take_strings\n");

   printf("address of s_literal_readonly: %p\n", s_literal_readonly);
   printf("address of s_stack_string: %p\n", s_stack_string);
   printf("address of s_malloc_heap_string: %p\n", s_malloc_heap_string);

   //there are different ways to set the string
   // memset
   // memset(s_literal_readonly, 65, 4); // we cannot change read only string literals
   // memset(s_stack_string, 65, 4);
   // memset(s_malloc_heap_string, 65, 4);

   // array access with brackets [n_index]
   // int n_i = 0; 
   // while(n_i < 10){
   //    s_stack_string[n_i] = 65;
   //    n_i++; 
   // }

   //strcpy
   // strcpy(s_stack_string, "a s d f");
   // strcpy(s_malloc_heap_string, "hello");


   // [
   //    0b1111 1111,// 94 201 786 114 464
   //    //             ^
   //    //             tri-              -llion
   //    //                bi-            -llion
   //    //                    mi-        -llion
   // ]

   // 1 byte = 8 bit 
   // 1 kilobyte = 1024 byte , 
   // 1 kibibyte = 1000 byte
   

}

void f_string_address_in_two_scopes(){
   printf("f_string_address_in_two_scopes\n");

   char * s_literal_readonly = "i am a static readonly literal";
   char s_stack_string[100] = "i am a strring on the stack"; 
   char * s_malloc_heap_string = malloc(100);

   printf("address of s_literal_readonly: %p\n", s_literal_readonly);
   printf("address of s_stack_string: %p\n", s_stack_string);
   printf("address of s_malloc_heap_string: %p\n", s_malloc_heap_string);


   printf("before f_i_take_string: %s\n", s_literal_readonly);
   printf("before f_i_take_string: %s\n", s_stack_string);
   printf("before f_i_take_string: %s\n", s_malloc_heap_string);

   f_i_take_strings(
      s_literal_readonly,
      s_stack_string,
      s_malloc_heap_string
   );

   
   printf("after f_i_take_string: %s\n", s_literal_readonly);
   printf("after f_i_take_string: %s\n", s_stack_string);
   printf("after f_i_take_string: %s\n", s_malloc_heap_string);

}

int main() {

   // f_change_content_of_string_literal();
   // f_change_whole_string_literal();
   // f_same_string_literal_different_pointer_questionmark();
   f_string_address_in_two_scopes();
   return 0;
}

