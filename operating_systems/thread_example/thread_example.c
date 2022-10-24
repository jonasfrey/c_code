

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void * f_callback(void *variable_arg){
   printf("f f_callback: start\n");

   printf("f f_callback: done\n");

   return NULL;
}

void f_start_thread(){
   printf("f f_start_thread: start\n");

   sleep(1);
   pthread_t n_thread_id;
   void * n_attributes = NULL;
   void * n_arguments = NULL;
   int n_error_code = pthread_create(
      &n_thread_id, 
      n_attributes, 
      f_callback,
      n_arguments
   );
   
   printf("f_start_thread called\n");

   if(n_error_code){
      printf("thread had an error!\n");
      printf("n_error_code %d\n", n_error_code);
   }

   printf("f f_start_thread: done\n");


}
int main(void){
   printf("f main: start\n");

   f_start_thread();
   printf("f main: done\n");

}
// #include<assert.h>
// #include<pthread.h>
// #include<stdio.h>
// void * mythread(void*arg){
//    printf("%s\n",(char*)arg);
//    return NULL;
// }
// int main(void){
//    printf("main:begin\n");
//    pthread_t t1; 
//    pthread_t t2;
//    assert(0==pthread_create(&t1,NULL,mythread,"A"));
//    assert(0==pthread_create(&t2,NULL,mythread,"B"));
//    //joinwaitsforthethreadstofinish
//    assert(0==pthread_join(t1,NULL));
//    assert(0==pthread_join(t2,NULL));
//    printf("main:end\n");
// }