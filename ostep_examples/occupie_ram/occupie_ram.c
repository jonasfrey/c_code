

// c file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int n_arguments, char *a_s_argument[]) {

   int n_pid = getpid();
   printf("process id is: %d\n", n_pid);
   printf("number of arguments %d\n", n_arguments);
   int n = 0; 
   if(n_arguments < 2){
      printf("please pass the number of bytes that should be occupied in the RAM memory as the first argument , ('./occupie_ram 2000000000') would be 2 gigabyte\n");
      exit(1);
   }
   while(n < n_arguments){
      printf("a_s_argument[%d]: %s\n", n, a_s_argument[n]);
      n+=1;
   }
   unsigned long n_bytes_to_occupie = 1*1000*1000;//1gb
   if(n >= 2){
      sscanf (a_s_argument[1],"%lu",&n_bytes_to_occupie);
      // n_bytes_to_occupie = a_s_argument[1];
   }
   printf("     bytes to occupie: %lu\n", n_bytes_to_occupie);
   printf("kilo-bytes to occupie: %lu\n", n_bytes_to_occupie/1000);
   printf("mega-bytes to occupie: %lu\n", n_bytes_to_occupie/1000/1000);
   printf("giga-bytes to occupie: %lu\n", n_bytes_to_occupie/1000/1000/1000);

   char * s_huge_string = malloc(n_bytes_to_occupie);
   // 1. malloc does not set the memory it just allocates the adress
   //    so we have to set the memory ourselfs by just inserting data into this huge string
   int n_index = 0; 
   char s;
   while(n_index < n_bytes_to_occupie){
      s_huge_string[n_index] = ((n_index%26) +65);
      s = s_huge_string[n_index];
      // n_index = (n_index+1) % n_bytes_to_occupie;
      n_index +=1;
      // printf("n_index: %d\n", n_index);
   }
   free(s_huge_string);

   // 2. the max limit of malloc is 16'711'568:  "The malloc() function reserves a block of storage of size bytes. Unlike the calloc() function, malloc() does not initialize all elements to 0. The maximum size for a non-teraspace malloc() is 16711568 bytes."
   // on my machine the maximum size for one char * with malloc is around 2'000'000'000 which is 2GB
   // so to fill the desired amount of RAM we need to create multiple char * 

   int n_divisor = 100;
   unsigned long n_length_a_s_huge_string = n_divisor; 
   char ** a_s_huge_string = malloc(n_length_a_s_huge_string);
   int n_index_a_s_huge_string = 0;
   while(n_index_a_s_huge_string < n_length_a_s_huge_string){
      char * s_text = malloc(n_bytes_to_occupie/n_divisor);
      memset(s_text, 'A', n_bytes_to_occupie/n_divisor);

      // a_s_huge_string[n_index_a_s_huge_string] = malloc(n_bytes_to_occupie/n_divisor);
      // we can use memset to conviniently set memor
      // memset(a_s_huge_string[n_index_a_s_huge_string], 'A', n_bytes_to_occupie/n_divisor);
      n_index_a_s_huge_string +=1;
   };
   while(1){
      //looping forever
   }
   // char s_char_to_be_set = 'A';
   // int n_num_of_bytes_to_set = n_bytes_to_occupie;
   // while(n_index < 128){
   //    n_index = (n_index+1) % 128;
   //    memset(s_huge_string, ((n_index%26) +65), n_num_of_bytes_to_set);
   // }
}
