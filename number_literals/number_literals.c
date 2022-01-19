
// c file 
#include <stdio.h>

int main() {
   /* my first program in C */
   // printf("\n100u unsigned: %d", 100u);
   // printf("\n100u unsigned: %d", -10u);
   // printf("\n100 :%d", 100);
   
   // printf("\n normal int is usually 2^32=4,2 billion eng. if signed +2.1 billion -2.1billion");
   // 1. number literals cannot have spaces or any other characters dividing the number
   //    printf("\n4 000 000 000 : %d", 4 000 000 000 ); // error: expected ')' before numeric constant
      // printf("\n4'000'000'000 : %d", 4'000'000'000 ); // error: multi-character character constant
   
   // 2. 
   // this is not true but why?   // // if the literal is higher than the standard int 2^32 on most systems 
   // // it has to be suffixed with for example 'L' //
   // // on my system a int is 
   // printf("\n4000000000 : %li", 4000000000 );

   // 3. we can initialize hex and octal values by using the suffix

   printf("\n printf with %%d , 0xf3 : %d", 0xf3);

   // we can format them as hex aswell, but the 0x wont be displayed, actually too bad :(
   printf("\n printf with %%x , 0xf3 : %x", 0xf3);

   
   // 4. the same for octal values 
   printf("\n printf with %%d , 0363: %d", 0363);

   printf("\n printf with %%o , 0363: %o", 0363);



   return 0;
}
