// c file 
#include <stdio.h>


// array prime_factors(){}


// a pretty bad and slow algorhitm to get the grosster gemeinsamer teiler 
int biggest_together_divisor(int a, int b){
   
   int n_bigger = a;
   int n_smaller = b;

   if(b > a){
      n_bigger = b; 
      n_smaller = a; 
   }

   int biggest_together_divisor = n_smaller;
   int n_algorhitm_cycle_counter = 0;

   while(1){

      n_algorhitm_cycle_counter++;

      int n_remainder_bigger = n_bigger % biggest_together_divisor;
      int n_remainder_smaller = n_smaller % biggest_together_divisor;

      if(n_remainder_smaller == 0 && n_remainder_bigger == 0){
         break;
      }

      biggest_together_divisor --; 
   }
   
   printf("\n n_algorhitm_cycles needed:%i ",n_algorhitm_cycle_counter );

   return biggest_together_divisor;
}

int ggt_euclidian(int a, int b){

   int n_bigger = a; 
   int n_smaller = b; 
   
   if(b > a){
      n_bigger = b; 
      n_smaller = a; 
   }
   
   int n_result = 0;
   
   int n_algorhitm_cycle_counter = 0;

   while(n_bigger != n_smaller){
      n_algorhitm_cycle_counter++;
      printf("\n n_algorhitm_cycle:%i ",n_algorhitm_cycle_counter );
      
      printf("%i(n_result) = %i(n_bigger) - %i(n_smaller)", n_result, n_bigger, n_smaller);

      n_result = n_bigger - n_smaller; 

      if(n_result > n_smaller){
         n_bigger = n_result;
      }else{
         n_bigger = n_smaller; 
         n_smaller = n_result; 
      }
   }
   
   //n_bigger == n_smaller
   return n_bigger;
}

#include <time.h>

int main() {
   /* my first program in C */
   
   int n_a;
   printf("a: ");
   scanf("%d", &n_a);

   int n_b;
   printf("b: ");
   scanf("%d", &n_b);

   printf("\n ------- algorhitm: bruteforce decrement (while not found --) --------");

   clock_t start = clock();

   int n_biggest_together_divisor = biggest_together_divisor(n_a, n_b); 

   clock_t end = clock(); 

   double delta_time = (double) (end-start) / CLOCKS_PER_SEC;

   //printf("\n the groesster gemeinsamer teiler von a(%i) und b(%i) ist %i", n_a, n_b , n_biggest_together_divisor);
   

   printf("\n time_delta (%f time): ", delta_time); 
   printf("\n ggT(%i,%i) =  %i", n_a, n_b , n_biggest_together_divisor);

   printf("\n ------- algorhitm: euclidean --------");

   start = clock();

   n_biggest_together_divisor = ggt_euclidian(n_a, n_b); 

   end = clock(); 

   delta_time = (double) (end-start) / CLOCKS_PER_SEC;

   //printf("\n the groesster gemeinsamer teiler von a(%i) und b(%i) ist %i", n_a, n_b , n_biggest_together_divisor);
   printf("\n time_delta (%f time): ", delta_time); 
   printf("\n ggT(%i,%i) =  %i", n_a, n_b , n_biggest_together_divisor);

   return 0;
}