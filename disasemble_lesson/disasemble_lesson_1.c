
// compile:
//    gcc -Wall -g -O0 disasemble_lesson_1.c -o disasemble_lesson_1
// disasemble:
//    objdump -d ./disasemble_lesson_1 > disasemble_lesson_1_disasembled.asm

int main() {
   // now we assign a specific literal number to the int value, to check if 
   // we can find it in the assembler
   int i = 112358; 
   // 1131:	c7 45 f4 e6 b6 01 00 	movl   $0x1b6e6,-0xc(%rbp) // 0x1b6e6 is hexadecimal for 11235

   char * s = "hello i am a string"; 
   
   return 0;
}
