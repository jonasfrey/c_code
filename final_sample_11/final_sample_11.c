
// c file
#include <stdio.h>
int foo(int v)
{
   for (int j = 0; j < v; j++)
      bar(v - 1);
}
int bar(int v)
{
   for (int j = 0; j < v; j++)
      foo(v - 1);
   printf("%d", v);
}
int main(int argc, char **argv)
{
   foo(5);
   return 0;
}