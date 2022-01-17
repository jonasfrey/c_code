
// c file 
#include <stdio.h>


// from final sample exam
// 5. Explain the meaning of the const keyword. Example: void func(const void *p);

void func(const void *p){ 
   printf("\nfunc was called, param const void *p is: %p", p);

}

void func_without_const(void *p){
   printf("\nfunc_without_const was called, param void *p is: %p", p);

}

int main() {
   /* my first program in C */
   printf("main function called");
   
   int n_my_num = 11235;

   //    func(n_my_num); //error: passing argument 1 of ‘func’ makes pointer from integer without a cast
   
   func(&n_my_num);

   n_my_num = 444; 

   func(&n_my_num);

   int n_a_num = 99; 
   
   func_without_const(&n_a_num);
   
   n_a_num = 111; 
   
   func_without_const(&n_a_num);

   return 0;
}
