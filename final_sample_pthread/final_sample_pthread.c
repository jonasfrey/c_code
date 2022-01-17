
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
  
// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
      sleep(1);
      printf("Printing GeeksQuiz from Thread \n");
      return NULL;
}
   
int main()
{
      pthread_t thread_id;
      printf("Before Thread\n");
      pthread_create(&thread_id, NULL, myThreadFun, NULL);
      pthread_join(thread_id, NULL);
      printf("After Thread\n");
      exit(0);
}

// sample from exam 

// c file
#include <stdio.h>

static int r;
static void *add(void *p)
{
   r++;
}
int main(int argc, char **argv)
{
   pthread_t p1;
   pthread_t p2;
   pthread_create(&p1, NULL, &add, NULL);
   pthread_create(&p2, NULL, &add, NULL);
   printf("%d ", r);
   pthread_join(p1, NULL);
   pthread_join(p2, NULL);
   printf("%d\n", r);
   return 0; 
}