
// c file
#include <stdio.h>

static int i;
int foo(int arr[4])
{
   int ret = 0;
   for (int i= 0; i < 40; i++)
      printf("%i\n", arr[i,1]);
      ret += arr[i, 1];
   return ret;
}
int main()
{
   int data[4] = {1,2,3,4};
   printf("%i",foo(data +1));
   return foo(data +1);
   
}