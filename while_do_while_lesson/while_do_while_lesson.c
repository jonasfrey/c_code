
// c file 
#include <stdio.h>

void while_do(){

   printf("\n while_do");
   int test = 10; 

   while(test){
      printf("\n num is %i", test);
      test--;
   }
}
void do_while(){
   printf("\n do_while");
   int test = 10;
   do{ 
      printf("\n num is %i", test);
      test--;
   }while(test);
}
int main() {

   do_while();

   while_do();

   return 0;
}
