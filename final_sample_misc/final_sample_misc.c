
// c file
#include <stdio.h>

int t()
{
   printf("t ");
   return 1;
}
int f()
{
   printf("f ");
   return 0;
}

void and_operators()
{
   printf("%d %d\n", t() & f(), f() && t());
}

void what_is_the_output_of_this() {
   // printf("%1.0f %3.0f\n", 10.01234, 0.01234);
   // printf("%.1f %.3f\n", 10.01234, 0.01234);
   // printf("%.1f %.3f\n", 10.0, 0.0
   printf("%1.0f %3.0f\n", 10.0, 0.0); 
}

int main()
{
   // int x = 0;

   printf("%_5d\n", 10);
   /* my first program in C */
   what_is_the_output_of_this();

   return 0;
}
