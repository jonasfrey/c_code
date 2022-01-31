
// c file 
#include <stdio.h>

void pointer_not_const(){
   int num = 1234;
   int other_num = 420; 
   int * pointer_to_num = &num;
   printf("*pointer_to_num: %i \n", *pointer_to_num);

   *pointer_to_num = 420; 
   printf("*pointer_to_num: %i \n", *pointer_to_num);

}
void pointer_consts(){
//although we cannot modify a constant value
// it its a const pointer we can exchange its address 

int num = 1234;
int other_num = 420; 
const int * pointer_to_num = &num;

printf("*pointer_to_num: %i \n", *pointer_to_num);

//    not working, because pointer_to_num is const
// *pointer_to_num = 420; // trying to change the value at the adress of num;

//    but we can exchange the pointer address
pointer_to_num = &other_num; 

printf("*pointer_to_num: %i \n", *pointer_to_num);

}
void simple_const(){
// the const is a keyword to tell the compiler prevent the developer from modifying a variable
   const int tau = 6.28; 
   printf("tau is now %i", tau);
   //    so we cannot modify the const value 
   // tau = 3.14;  //error: assignment of read-only variable
   // printf("tau is now %i", tau);

}
int main() {
   
   // simple_const();
   pointer_consts();
   // pointer_not_const();
   return 0;
}
