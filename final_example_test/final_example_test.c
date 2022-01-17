
// c file
#include <stdio.h>

#include "./../c_helpers/dnd.c"

int foo(int arr[4])
{
   int ret = 0;

   for (int i = 0; i < 40; i++)
   {
      ret += arr[i, 1];
   }
   return ret;
}

enum Rights
{
   RIGHT_TO_READ,
   RIGHT_TO_WRITE,
   RIGHT_TO_EXECUTE,
};

int abort(){ 
   printf("abort");
   return 0;
}
struct MyFile
{
   enum Rights rights;
   // ...
};
int do_read(struct MyFile f)
{
   if (f.rights & RIGHT_TO_READ)
   {
      //...
      printf("f.rights & RIGHT_TO_READ");
   }
   else
      abort();
}
int do_write(struct MyFile f)
{
   if (0 != (f.rights & RIGHT_TO_WRITE))
   {
      printf("f.rights & RIGHT_TO_WRITE");

      //...
   }
   else
      abort();
}
int do_execute(struct MyFile f)
{
   if (RIGHT_TO_EXECUTE != f.rights & RIGHT_TO_EXECUTE)
   {
      //...
      printf("f.rights & RIGHT_TO_EXECUTE");

   }
   else
      abort();
}
int allow_all(struct MyFile f)
{
   f.rights = RIGHT_TO_READ | RIGHT_TO_WRITE | RIGHT_TO_EXECUTE;
}

int main()
{
   /* my first program in C */
   printf("main function called");

   int data[4] = {1, 2, 3, 4};
   return foo(data + 1);


   printf("second example");




   return 0;
}
