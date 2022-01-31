
// c file 
#include <stdio.h>

int t(){
   printf("t ");
   return 1; 
}
int f(){
   printf("f ");
   return 0; 
}
int main() {
   /* my first program in C */
   // int a = t() & f();
   // printf("%i", t() & f()); // t f 0
   // printf("%d", t() & f()); // t f 0
   // printf("%i", t() && f()); // t f 0
   // printf("%d", t() && f()); // t f 0

   int a = t() & f();
   printf("%i", a);
   printf("\n");
   int b = f() & t();
   printf("%i", b);
   
   printf("\n");
   int aa = t() && f();
   printf("%i", aa);
   printf("\n");

   int bb = f() && t(); // if any value in the && chain is hitting 0 , the rest does not get evaluated further 
   printf("%i", bb);

   printf("\n");

   // if any value in the && chain is hitting 0 , the rest does not get evaluated further 
   int dd = 5 && printf("hi ") && 123 && printf("how ") && 420 && printf("are ") && 0 && printf("you? ");
   printf("\n");
   // this does not work with bitwise operators
   int d = 1 & printf("hi ") & 1 & printf("how ") & 1 & printf("are ") & 0 & printf("you? ");
   
   // printf("%i", cc);

   // int a = t() & f();
   // int b = f() && t();
   // printf("%d %d\n", a, b);
   // printf("%d %d\n", t() & f(), f() && t());
   return 0;
}
