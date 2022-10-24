
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int main() {

   pthread_t n_thread_id;
   void * n_attributes = NULL;
   void * n_arguments = NULL;
   int n_error_code = pthread_create(
      &n_thread_id, 
      n_attributes, 
      f_callback,
      n_arguments
   );

   /* my first program in C */
   printf("main function called");
   
   return 0;
}
