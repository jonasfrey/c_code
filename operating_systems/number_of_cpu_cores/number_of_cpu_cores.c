
// c file 
#include <stdio.h>
#include <unistd.h>

int main() {

   long n_number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);
   
   printf("long n_number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);");
   printf("\nn_number_of_processors: %ld\n", n_number_of_processors);

   return 0;
}
