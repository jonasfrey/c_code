
// c file 
#include <stdio.h>

void f_print_memory_layout(){

   printf(
   ".____________________.\n"
   "|                    |\n"
   "|____________________|\n"
   "|        stack       |\n"
   "|                    |\n"
   "|--------------------|\n"
   "|         ↓          |\n"
   "|                    |\n"
   "|         ↑          |\n"
   "|--------------------|\n"
   "|        heap        |\n"  // 
   "|____________________|\n"
   "| uninitialized data |\n"
   "|         (bss)      |\n"
   "|____________________|\n"
   "|  initialized data  |\n"
   "|____________________|\n"
   "|  text/code segment |\n"
   "|____________________|\n"

   );

}
void f_static_memory_allocation(){

   // this memory is static 
   // we can not in- and de- -crease this size at runtime!
   int a_n_i32[7] = {-3,-2,-1,0,1,2,3};

   // if at runtime we would try to put in more elements than possible 
   // it would crash or misbehave
   // int n_index = 6;
   // a_n_i32[n_index] = 18;//tihs would work
   // n_index+=1;
   // a-n_i32[n_index] = 33; // this can crash or misbehave since
   //                        // the n_index is now 7 and the array max index is 6 
}

void f_dynamic_memory_allocation(){
   // the process of allocating memory at the time of execution is called 
   //"dynamic memory allocation"

}
int main() {
   /* my first program in C */
   printf("main function called");
   
   return 0;
}
