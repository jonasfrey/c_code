#include <stdio.h>

int main()
{
   int n_password;
   printf("enter password...\n");
   scanf("%d", &n_password);
   if (n_password == 4566)
   {
      printf("you are login\n");
      printf("opening function\n");
   }
   else
   {
      printf("you are not login\n");
      printf("please try again\n");
   }

   return 1;
}