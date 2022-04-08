
// c file 
#include <stdio.h>
#include <pthread.h> // we have to link -pthread or -lpthread
#include <unistd.h>
void my_turn(){
   while(1){
      sleep(1);
      printf("my_turn\n");
   }
}
void * my_turn_for_thread(void * arg){
   while(1){
      sleep(1);
      printf("my_turn_for_thread\n");
   }
   return NULL;
}

void your_turn(){
   while(1){
      sleep(1);
      printf("your_turn\n");
   }
}
void * my_turn_for_thread_8times(void * arg){
   for(int i = 8; i > 0; i--){
      sleep(1);
      printf("my_turn_for_thread %i\n", i);
   }
   return NULL;
}
void your_turn_3times(){
   for(int i = 3; i > 0; i--){
      sleep(1);
      printf("your_turn %i\n", i);
   }
}
int main() {

   // processes are isolated, their memory is separate 
   // threads  have no isolation, so memory is shared
   // threads have separate memory stacks, but 
   // one thread can write in the memory of the other

   //    my_turn(); repeats infinitly 
   //    and your_turn() wont ever be called
   // my_turn();
   // your_turn();

   // //    to let em run parrallel we 
   // //    can use pthread_t

   // //    now the functions are running parallell/concurrently
   // //    pthread_t new_trhead;
   // pthread_create(&new_trhead, NULL, my_turn_for_thread, NULL);
   // your_turn();

   // // now what happens when on of both is limited 
   // // and runs out after a time

   // pthread_t new_trhead;
   // pthread_create(&new_trhead, NULL, my_turn_for_thread_8times, NULL);
   // your_turn_3times();
   // printf("done\n");
   // // main finished before the my_turn_for_thread_8times is completed


   // // to bring the threads together , ensure that every thread
   // // fully completes 
   // // we can use pthread_join()
   pthread_t new_trhead;
   pthread_create(&new_trhead, NULL, my_turn_for_thread_8times, NULL);
   your_turn_3times();
   pthread_join(&new_trhead,NULL);

   printf("done\n");
   
   return 0;
}
