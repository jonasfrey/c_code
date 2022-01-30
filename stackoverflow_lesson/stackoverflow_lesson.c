
// c file 
#include <stdio.h>
#include <stdlib.h>

void is_this_heap_overflow(){
   long n = 1000;
   char * s = malloc(n);
   while (1)
   {
      n = n + 1000;
      
      printf("realloc() %li bytes, %li kilobytes, %li megabytes, %li gigabytes \n", n , (long)(n/1024.0), (long)(n/(1024*1024.0)), (long)(n/(1024*1024*1024.0)));
      /* code */
      s = realloc(s, n);
   }
   
}

void heapoverflow2(){
   long n = 1024*1024*500; // 500 megabyte
   char * s = malloc(n);
   for(long i=0; i<n;i++){
      s[i] = 'a';
      if(i%1024*1024 == 0){
         printf("char at: %li bytes, %li kilobytes, %li megabytes, %li gigabytes \n", i , (long)(i/1024.0), (long)(i/(1024*1024.0)), (long)(i/(1024*1024*1024.0)));
      }

   }

}

void heapoverflow3(){
   long n = 1024*1024*1000; // 1000 megabyte
   char * s = malloc(n);
   for(long i=0; i<n;i++){
      s[i] = 'a';
      if(i%1024*1024 == 0){
         printf("char at: %li bytes, %li kilobytes, %li megabytes, %li gigabytes \n", i , (long)(i/1024.0), (long)(i/(1024*1024.0)), (long)(i/(1024*1024*1024.0)));
      }

   }

}

void trying_to_cause_stackoverflow(){

}

int main() {
   // is_this_heap_overflow();   
   // heapoverflow2();
   heapoverflow3();
   return 0;
}
