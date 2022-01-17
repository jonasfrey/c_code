
// c file
#include <stdio.h>
#include <stdlib.h>
#include "./../c_helpers/dnd.c"

enum Rights
{
   RIGHT_TO_READ,
   RIGHT_TO_WRITE,
   RIGHT_TO_EXECUTE,
};

// abort is defined in <stdlib.h>
// int abort(){ 
//    printf("abort");
//    return 0;
// }
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
   else{
      abort();
   }
}
int do_write(struct MyFile f)
{
   if (0 != (f.rights & RIGHT_TO_WRITE))
   {
      printf("f.rights & RIGHT_TO_WRITE");

      //...
   }
   else{
      abort();
   }
}
int do_execute(struct MyFile f)
{
   if (RIGHT_TO_EXECUTE != f.rights & RIGHT_TO_EXECUTE)
   {
      //...
      printf("f.rights & RIGHT_TO_EXECUTE");

   }
   else{
      abort();
   }
}
int allow_all(struct MyFile f)
{
   f.rights = RIGHT_TO_READ | RIGHT_TO_WRITE | RIGHT_TO_EXECUTE;
}

int main() {
   /* my first program in C */
   printf("main function called");
   struct MyFile i_my_file;
   
   i_my_file.rights = RIGHT_TO_EXECUTE;

   printf("%i", i_my_file.rights);
   //dnd(my_file);

   return 0;
}

