
// c file 
#include <stdio.h>

#include "./../c_helpers/dnd.c"
void abstand_char_pointers_in_string(){

   char * s_first = "asdf";
   //first char
   dndc(s_first[0]);
   //address of first char
   dnd(s_first)// address of char pointer, which is adress of first char
   dnd(&s_first[0]);

   //adress of second char, is it adress of first char +1? 
   dnd(&s_first[1]);
   dnd(s_first+1) // yes it is!

   
   // char s_second[5] = "asdf";
   // dnd(s_second);

}
int main() {
   abstand_char_pointers_in_string();
   return 0;
}
