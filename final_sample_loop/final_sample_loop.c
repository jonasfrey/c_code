
// c file
#include <stdio.h>

static int i;
int foo(int i)
{
   int ret = i;
   for (int i; i < 4; i++)
      ret += i;
   return ret;
}
int main()
{
   printf("%i", i);
   printf("%i", i + foo(4));
   return 0;
   // return i + foo(4);
}