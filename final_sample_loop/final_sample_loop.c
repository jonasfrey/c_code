
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
   return i + foo(4);
}