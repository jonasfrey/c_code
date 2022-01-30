
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

long long stack_overflow_recursion(long long i){
   i = i+1; 
   if(i < 100000){
   // if(i < 1000000){ // segmentation fault
   // if(i < 10000000){ // segmentation fault

      return stack_overflow_recursion(i); // some really bad recursion here
   }
   return i;
}

void stack_overflow(){
   long long i = 10; 
   i = stack_overflow_recursion(i);
   printf("%lli", i);
   fflush(stdout);
}

void trying_to_cause_stackoverflow(){

}

int create_c_file_with_many_vars(){


   printf("----------------------------------------\n");
   printf("test starting\n");
   FILE * file_pointer;

   // use appropriate location if you are using MacOS or Linux
   long j = 1000000;
   printf("creating file with %li variables\n", j);

   char file_name[150];
   char file_path_name[200];
   
   sprintf(file_name,"c_file_with_many_vars_%li",j);
   sprintf(file_path_name,"./%s.c",file_name);


   remove(file_path_name);
   file_pointer = fopen(file_path_name, "a");// a=append
   if(file_pointer == NULL){
      printf("fopen error");
      exit(1);
   }

   fprintf(file_pointer,"//file is generated automatically by c function fopen()\n");
   fprintf(file_pointer,"#include <stdio.h>\n");
   fprintf(file_pointer,"int main(){\n");
   long i = 0;

   char var_name[20]; 
   for(i = 0; i < j; i++){
      sprintf(var_name, "variable_number_%li", i);
      fprintf(file_pointer, "long long %s = %li;\n", var_name,i);
   }
   
   fprintf(file_pointer, "printf(\"last variable name:value, %s:%li\");\n", var_name, i);

   fprintf(file_pointer,"}\n");
   fclose(file_pointer);


   printf("compiling ...\n");
   char compile_command[500]; 
   sprintf(compile_command, "gcc %s -o %s", file_path_name, file_name);
   system(compile_command);

   printf("running binary... \n");
   char run_binary_command[500]; 
   sprintf(run_binary_command, "./%s", file_name);
   system(run_binary_command);

   printf("----------------------------------------\n");
   printf("test finished\n");

   return 0;

}


void stack_overflow2(){

   char a_really_huge_char_which_should_cause_stackoverflow[1000000000]; 
   printf("%s", a_really_huge_char_which_should_cause_stackoverflow); 

}


void stack_overflow_int_array(){
//run this programm to check at what size stackoverflow happens for your pc 
//mine happens at 
//   array size:              2100000 -> 2'100'000 at 2 million 
//                               so the actual bytes are 2 million * sizeof(int) which is 4 on this machine
//                            2100000 * 4 = 8'400'000 bytes
//                            8'400'000 / 1024 = 8203 kilobytes
//                                8'203 / 1024 =    8 megabytes

   printf("sizeof(short): %li\n", sizeof(int));
   sleep(2);
   for(int i = 0; i<(10000000); i++){
      if(i%10000 == 0){
         printf("   array size: %20i\n", i);
         long stack_size_bytes = (i * sizeof(int)); 
         float stack_size_kilobytes = stack_size_bytes /1024.0;
         float stack_size_megabytes = stack_size_kilobytes /1024.0;

         printf("   stack used: %li Bytes, %.2fKB, %.2fMB", stack_size_bytes, stack_size_kilobytes, stack_size_megabytes);
         int huge_int_array[i];
         huge_int_array[0] = 11235; 
         printf("huge_int_array[0]: %20i\n", huge_int_array[0]);
      }
   }

   // int huge_2_d_array[1000][10000];
   // huge_2_d_array[0][0] = 1;
   // printf("huge_2_d_array[0][0]: %i\n", huge_2_d_array[0][0]);

}
void stack_overflow_shortint_array(){
// segmentation fault happens at size
//array size:              4190000 -> 4'190'000 at 4 million
   printf("sizeof(short): %li\n", sizeof(short));
   sleep(2);

   for(int i = 0; i<(1000000000); i++){
      if(i%10000 == 0){
         printf("   array size: %20i\n", i);
         short huge_shortint_array[i];
         huge_shortint_array[0] = 11235; 
         printf("huge_shortint_array[0]: %20i\n", huge_shortint_array[0]);
      }
   }

}
void stack_overflow_longint_array(){
//run this programm to check at what size stackoverflow happens for your pc 
//mine happens at 
//   array size:              1050000 -> 1'050'000 at 1 million
   printf("sizeof(long): %li\n", sizeof(int));
   sleep(2);
   for(int i = 0; i<(10000000); i++){
      if(i%10000 == 0){
         printf("   array size: %20i\n", i);
         long huge_longint_array[i];
         huge_longint_array[0] = 11235; 
         printf("huge_longint_array[0]: %20li\n", huge_longint_array[0]);
      }
   }

   // int huge_2_d_array[1000][10000];
   // huge_2_d_array[0][0] = 1;
   // printf("huge_2_d_array[0][0]: %i\n", huge_2_d_array[0][0]);

}
int main() {
   
   // WARNING, its highly recommended to try this stuff with a Virtual Machine!
   // the following c programms CAN CRASH your PC! 

   // is_this_heap_overflow();   
   // heapoverflow2();
   // heapoverflow3();
   // stack_overflow();
   // create_c_file_with_many_vars();
   // stack_overflow2();
   stack_overflow_int_array();
   // stack_overflow_shortint_array();
   // stack_overflow_longint_array();

   return 0;

}
