
// c file 
#include <stdio.h>
#include <stdlib.h>
void f_static_size(){
   unsigned char a_n_uint8[10]; 

   a_n_uint8[0] = 12;
   a_n_uint8[1] = 2;
   a_n_uint8[2] = 32;
   a_n_uint8[3] = 5;

   printf("a_n_uint8[0]:%d\n", a_n_uint8[0] ); 
   printf("a_n_uint8[1]:%d\n", a_n_uint8[1] ); 
   printf("a_n_uint8[2]:%d\n", a_n_uint8[2] ); 
   printf("a_n_uint8[3]:%d\n", a_n_uint8[3] ); 

   printf("index of a_n_uint8   : %p\n", a_n_uint8);
   printf("index of a_n_uint8[0]: %p\n", &a_n_uint8[0]);
   printf("index of a_n_uint8[1]: %p\n", &a_n_uint8[1]);
   printf("index of a_n_uint8[2]: %p\n", &a_n_uint8[2]);
   printf("index of a_n_uint8[3]: %p\n", &a_n_uint8[3]);

}

void f_dynamic_size(){
   unsigned char * a_n_uint8 = malloc(0);
   a_n_uint8[0] = 12;
   printf("a_n_uint8[0]:%d\n", a_n_uint8[0] ); 
   printf("&a_n_uint8[0]:%p\n", &a_n_uint8[0] ); 
   printf("&a_n_uint8[1]:%p\n", &a_n_uint8[1] ); 
   printf("&a_n_uint8[2]:%p\n", &a_n_uint8[2] ); 

   printf("a_n_uint8[2]:%d\n", a_n_uint8[2] ); 
   printf("a_n_uint8[100000]:%d\n", a_n_uint8[100000] ); // why tf does this work?

   // printf("a_n_uint8[1]:%d\n", a_n_uint8[1] ); 
}
int main() {
   // f_static_size();
   f_dynamic_size();
   /* my first program in C */
   printf("main function called");
   
   return 0;
}
