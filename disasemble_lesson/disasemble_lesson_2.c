
// compile &&  disasemble:
/*    
gcc -Wall -g -Og disasemble_lesson_2.c -o disasemble_lesson_2 &&
objdump -d ./disasemble_lesson_2 > disasemble_lesson_2_disasembled.asm

or

gcc -Wall -g -O0 disasemble_lesson_2.c -o disasemble_lesson_2 &&
gdb -q ./disasemble_lesson_2 

or 
gcc -S disasemble_lesson_2.c -o disasemble_lesson_2_disasembled.asm
*/
#include <stdio.h>section .text
int main() {
   char * this_is_a_charpointer_to_readonly_memory1 = "A B C D do you find me in the disassembled file????"; 
   char * this_is_a_charpointer_to_readonly_memory2 = "A B C D do you find me in the disassembled file????"; 
   char * this_is_a_charpointer_to_readonly_memory3 = "A B C D do you find me in the disassembled file????"; 
   char * this_is_a_charpointer_to_readonly_memory4 = "A B C D do you find me in the disassembled file????";
   printf("%s", this_is_a_charpointer_to_readonly_memory1);
   printf("%s", this_is_a_charpointer_to_readonly_memory2);
   printf("%s", this_is_a_charpointer_to_readonly_memory3);
   printf("%s", this_is_a_charpointer_to_readonly_memory4);
   char this_is_a_modifiable_char_array[] = "!!!!i should not be easy visible"; 
   
   return 0;
}
