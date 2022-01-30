
// compile:
//    gcc -Wall -g -O0 disasemble_lesson.c -o disasemble_lesson
// disasemble:
//    objdump -d ./disasemble_lesson > disasemble_lesson_disasembled.asm

int main() {
   // this local variable should go on the stack 
   // so if we disassemble this c programm 
   // we should see a push somewhere 
   int i;

   return 0;
}
