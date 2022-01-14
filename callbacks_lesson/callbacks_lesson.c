
// c file 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill_array(int a_empty_array[], size_t array_size, int (callback)(void)){

   for(int i = 0; i<array_size; i++){
      a_empty_array[i] = callback();
   }
}

int get_random_integer(void){
   return rand();
}


void foreach_integer_in_array(int a_empty_array[], int array_size, int (callback)(int array_value)){
   for(int i = 0; i < array_size; i++){
      a_empty_array[i] = callback(a_empty_array[i]);
   }
}
int subtract_hundret(int num){
   return num - 100;
}

int main(void)
{
   
   // initializzation for rand 
   srand(time(NULL));
   int random_integers[10];
   fill_array(random_integers, 10, get_random_integer);

   printf("random_integers === [");
   for(int i = 0; i<10; i++){
      printf("%i,", random_integers[i]);
   printf("]");
   }

   foreach_integer_in_array(random_integers, 10, subtract_hundret);

   printf("\n"); 
   
   printf("random_integers === [");
   for(int i = 0; i<10; i++){
      printf("%i,", random_integers[i]);
   printf("]");
   }
   
}