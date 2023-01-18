
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int b_mutex = 0;

pthread_mutex_t n_thread_lock;

void* f_thread1(void* arg){
   if(b_mutex){
      pthread_mutex_lock(&n_thread_lock);
   }
   for(int n = 0; n < 333; n++){
      printf("-"); 
      fflush(stdout);
      for(long n_delay = 0; n_delay<0xffffff; n_delay++){
         //delay / idle / sleep
      }
   }
   if(b_mutex){
      pthread_mutex_unlock(&n_thread_lock);
   }
}
void* f_thread2(void* arg){
   if(b_mutex){
      pthread_mutex_lock(&n_thread_lock);
   }
   for(int n = 0; n < 333; n++){
      printf("x"); 
      fflush(stdout);
      for(long n_delay = 0; n_delay<0xffffff; n_delay++){
         //delay / idle / sleep
      }
   }
   if(b_mutex){
      pthread_mutex_unlock(&n_thread_lock);
   }
}

int main() {

   pthread_t n_id__thread1;
   pthread_t n_id__thread2;
   pthread_mutex_init(&n_thread_lock, NULL);

   printf("Enter 1 to enable Mutex, 0 to disable: ");
   scanf("%d", &b_mutex);

   
   pthread_create(&n_id__thread1, NULL, &f_thread1, NULL);
   pthread_create(&n_id__thread2, NULL, &f_thread2, NULL);
   
   pthread_join(n_id__thread1, NULL);
   pthread_join(n_id__thread2, NULL);
   pthread_mutex_destroy(&n_thread_lock);

   return 0;

}