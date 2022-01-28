
// c file 
#include <stdio.h>

#ifndef INCLUDED_TYPENAME
   #include "./../c_helpers/typename.c"
#endif


int main() {

   int n_int = 15; 
   
   printf("\nn_int %i", n_int);
   printf("\n&n_int %p", &n_int);
   printf("\ntypename(&n_int) %s", typename(&n_int));
   printf("\ntypename(n_int) %s", typename(n_int));

   long n_long = n_int;
   

   printf("\n%li", n_long);
   printf("\n%s", typename(n_long));
   return 0;
}