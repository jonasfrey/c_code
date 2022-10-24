#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void f_get_new_address()
{
   int *n_int_address = malloc(sizeof(int));

   int b_true = 1;
   int n_count = 0;
   while (n_count < 10)
   {
      n_count += 1;
      sleep(1);
      printf("n_int_address address/index/pointer: %p\n", n_int_address);
      printf("n_int_address actual number value: %d\n", n_int_address);
      n_int_address = n_count; // we can change the address !
   }
}

// c file
#include <stdio.h>

int main()
{
   f_get_new_address();

   return 0;
}
