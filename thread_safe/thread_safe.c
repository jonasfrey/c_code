
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a_n[1000];// every thread will have its own stack 

int * a_n__heap;
int n_len_a_n__heap = 9333;

void *f_fill_array_with_zeros(void *arg) {
   int *a_n__heap = (int *) arg;

   for(int n_index_a_n__heap = 0; n_index_a_n__heap < n_len_a_n__heap; n_index_a_n__heap+=1){
      // if(n_index_a_n__heap % 2 == 0){
         a_n__heap[n_index_a_n__heap] = 0;
         printf("a_n__heap[n_index_a_n__heap]: %d\n", a_n__heap[n_index_a_n__heap]);
      // }
   }
}

void *f_fill_array_with_ones(void *arg) {
   int *a_n__heap = (int *) arg;
   
   for(int n_index_a_n__heap = 0; n_index_a_n__heap < n_len_a_n__heap; n_index_a_n__heap+=1){
      //if(n_index_a_n__heap % 2 == 1){
         a_n__heap[n_index_a_n__heap] = 1;
         printf("a_n__heap[n_index_a_n__heap]: %d\n", a_n__heap[n_index_a_n__heap]);
      // }
   }
}
void f_print_a_n(int * a_n, int n_len_a_n){
   printf("a_n__heap: [");
   for(int n_index_a_n = 0; n_index_a_n < n_len_a_n; n_index_a_n+=1){

      printf("%d,", a_n[n_index_a_n]);
   }
   printf("]");
}
int main() {

   // in this example 
   // we create two threads which access the same array 
   // thread 1 writes 0 to each index
   // thread 2 writes 1 to each index 
   // in the end we can see that the array has random mixed content
   // depending on which thread did the write 

   a_n__heap = calloc(n_len_a_n__heap, sizeof(int));
   printf("n_len_a_n__heap: %d\n", n_len_a_n__heap);


   for(int n_index_a_n__heap = 0; n_index_a_n__heap < n_len_a_n__heap; n_index_a_n__heap+=1){
      a_n__heap[n_index_a_n__heap] = 18;
      // printf("a_n__heap[n_index_a_n__heap]: %d\n", a_n__heap[n_index_a_n__heap]);
   }

   f_print_a_n(a_n__heap, n_len_a_n__heap);

   pthread_t n_id__thread1;
   pthread_t n_id__thread2;
   int n_pthread_create_return1 = pthread_create(&n_id__thread1, NULL, f_fill_array_with_zeros, (void*)a_n__heap);
   if (n_pthread_create_return1) {
      printf("Error:unable to create thread, %d\n", n_pthread_create_return1);
      exit(-1);
   }

   int n_pthread_create_return2 = pthread_create(&n_id__thread2, NULL, f_fill_array_with_ones, (void*)a_n__heap);
   if (n_pthread_create_return2) {
      printf("Error:unable to create thread, %d\n", n_pthread_create_return2);
      exit(-1);
   }
   for(int n = 0; n< 929496729; n+=1){
      //idle
   }

   f_print_a_n(a_n__heap, n_len_a_n__heap);

   pthread_exit(NULL);

}