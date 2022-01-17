
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
int main(int argc, char **argv)
{
   printf("%d %d\n", t() & f(), f() && t());
}

int what_is_the_output_of_this(int argc, char ** argv) {
printf("%1.0f %3.0f\n", 10.0, 0.0);
}

int main()
{
   /* my first program in C */
   printf("main function called");

   return 0;
}
