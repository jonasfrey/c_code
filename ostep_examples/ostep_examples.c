
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <math.h>
char * f_s_format_long(long n){
   int b = 1;
   int n_last_decimal_place = n % 10;
   double n_res = n/10.; 
   int n_i = 0;
   int n_decimal_places = floor(log10((double)n));

   char s_num[50];
   sprintf(&s_num, "%ld", n);
   n = 0; 
   char s_out[50];
   int n2 = 0;
   while (n < 50){
      char s = s_num[n]; 

      if((n+n_decimal_places) % 3 == 0){
         if(s != NULL){
            s_out[n2] = '\'';
            n2+=1;
         }
      }
      s_out[n2] = s;
      n2 +=1;

      if(s == NULL){
         break;
      }
      n+=1;
   }
   char *s_out_ptr = s_out;

   return s_out_ptr;
   // printf("%s", s_num);

}
void f_fork_example(){

   // with fork, a new process can be created
   // this new process is called child process

   int n_process_id__child = fork();
   
   if(n_process_id__child < 0){
      printf( "error: fork() returned: %d", n_process_id__child);
      exit(1);
   }

   pid_t n_process_id__current = getpid();

   printf("Hello from process: %d\n", n_process_id__current);

}

void f_many_processes(){

   int n_i = 0;
   int n_max = 3; // the following will not only fork n_max times a process, 
   while(n_i < n_max){
      int n_procid__child = fork();
      if(n_procid__child < 0){
         printf( "error: fork() returned: %d", n_procid__child);
         exit(1);
      }
      n_i+=1;
   }
   // first loop , n_i = 0, n_max = 3
   //    p1:fork() -> p1,p2 running 
   // second loop, 
   //    p1:fork() -> p1,p2,p3 
   //    p2:fork() -> p1,p2,p3,p4
   // third loop
   //    p1:fork() -> p1,p2,p3,p4,p5
   //    p2:fork() -> p1,p2,p3,p4,p5,p6
   //    p3:fork() -> p1,p2,p3,p4,p5,p6,p7
   //    p4:fork() -> p1,p2,p3,p4,p5,p6,p7,p8
   
   // so the formula is pow(2,n_max) 

   pid_t n_process_id__current = getpid();
   printf("Started process: %d\n", n_process_id__current);
   int n_i_sleeploop = 0;
   int n_i_sleeploop_max = 20;
   while(n_i_sleeploop < n_i_sleeploop_max){
      sleep(5);
      printf("process: %d, sleeploop index: %d\n", n_process_id__current, n_i_sleeploop);
      n_i_sleeploop+=1;
   }

   printf("Ended process: %d\n", n_process_id__current);
   exit(1);
}
void f_heavy_cpu_load(){

   int n_i = 0;
   int n_exponent = 16; //this will create pow(2,n_exponent) processes
   while(n_i < n_exponent){
      int n_procid__child = fork();
      if(n_procid__child < 0){
         printf( "error: fork() returned: %d", n_procid__child);
         exit(1);
      }
      n_i+=1;
   }

   pid_t n_process_id__current = getpid();
   printf("Started process: %d\n", n_process_id__current);

   int n = 0;
   while(n< 100000){
      printf("unneccessary");
      float n_unniccessary = (int) pow((double) 22.2, 22.2);
      n_unniccessary = (int) pow((double) 22.2, 22.2);
      n_unniccessary = (int) pow((double) 22.2, 22.2);
      n+=1;
   }  

   printf("Ended process: %d\n", n_process_id__current);
   exit(1);


}
void f_print_virutal_adress(){

   printf("pointer/address/index of the current code (function):\n");
   printf("hex: %20p\n", f_print_virutal_adress);
   printf("dec: %20s\n", f_s_format_long((long) f_print_virutal_adress));
   void * n_ptr = malloc(100e6);

   printf("pointer/address/index of the current heap:\n");
   printf("hex: %20p\n", n_ptr);
   printf("dec: %20s\n", f_s_format_long((long) n_ptr) );
   int n_x = 0;

   printf("pointer/address/index of the current stack:\n");
   printf("hex: %20p\n", &n_x);
   printf("dec: %20s\n", f_s_format_long((long) &n_x));

   //example output
   // pointer/address/index of the current code (function):
   // 0x560ffb743437, 0d  94'626'643'194'935
   // pointer/adress/index of the current heap:
   // 0x7f40fcca1010, 0d 139'917'095'735'312
   // pointer/adress/index of the current stack:
   // 0x7ffcbfae3fcc, 0d 140'723'524'353'996
   
   // we can see that the 'code' has the lowest memory address 
   // followed by the 'heap'
   // followed by the 'stack'

}


int main() {
   // f_fork_example();
   // f_many_processes();
   // f_heavy_cpu_load();
   f_print_virutal_adress();

}
