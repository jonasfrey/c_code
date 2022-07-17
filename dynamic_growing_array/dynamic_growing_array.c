
// c file 
#include <stdio.h>
#include <stdlib.h>

void f_dynamic_allocated_array(){
   int n_i; 
   // type 
   int * a_n_number = malloc(sizeof(int));

   n_i = 0; 
   while(n_i < 10){
      a_n_number = realloc(a_n_number, n_i+1 * sizeof(int));
      a_n_number[n_i] = (n_i * 3)  % __INT_MAX__;
      n_i+=1;
   }

   n_i = 0; 
   while(n_i < 10){
      // printf("a_n_number[%i]: %i\n", n_i, a_n_number[n_i]);
      n_i+=1;
   }

   free(a_n_number);
}

void f_dynamic_array_manual(){
   char * a_char = malloc(1);
   a_char = realloc(a_char, 10);
   long n_adress_of_a_char = (long) &a_char;
   printf("address %li\n", n_adress_of_a_char);

   a_char[0] = 10;

   printf("value %i\n", a_char[0]);
   // int a_char_address = ()
}


void f_wtf_why_is_this_working(){

   int * a_n_number = malloc(sizeof(int));

   a_n_number[0] = 22;
   a_n_number[1] = 42;
   a_n_number[2] = 55;
   a_n_number[3] = 12;
   a_n_number[4] = 2;
   a_n_number[5] = 3;
   a_n_number[6] = 1;
   // a_n_number[7] = 99;
   // a_n_number[8] = 123;
   // a_n_number[9] = 321;

   printf("a_n_number[0]: %i\n", a_n_number[0]);
   printf("a_n_number[1]: %i\n", a_n_number[1]);
   printf("a_n_number[2]: %i\n", a_n_number[2]);
   printf("a_n_number[3]: %i\n", a_n_number[3]);
   printf("a_n_number[4]: %i\n", a_n_number[4]);
   printf("a_n_number[5]: %i\n", a_n_number[5]);
   // printf("a_n_number[6]: %i\n", a_n_number[6]);
   // printf("a_n_number[7]: %i\n", a_n_number[7]);
   // printf("a_n_number[8]: %i\n", a_n_number[8]);
   // printf("a_n_number[9]: %i\n", a_n_number[9]);

}




// start array for char -------------------------------------------------------------
typedef struct{
   size_t n_capacity; 
   size_t n_length; 
   char * a; 
} A_s_char;
void f_init_a_s_char(
   A_s_char * a_s_char
){
   a_s_char->n_capacity = 0; 
   a_s_char->n_length = 0;
   a_s_char->a = malloc(a_s_char->n_capacity * sizeof(char)); 
   // return &a_s_char;
}
void f_push_a_s_char(
   A_s_char * a_s_char, 
   char s_char
){
   a_s_char->n_capacity +=1;
   a_s_char->n_length +=1;
   a_s_char->a = realloc(a_s_char->a, a_s_char->n_length * sizeof(char));
   a_s_char->a[a_s_char->n_length-1] = s_char;
}
void f_remove_by_index_a_s_char(
   A_s_char * a_s_char, 
   int n_index 
){
   while(n_index < a_s_char->n_length){
      n_index+=1;
      a_s_char->a[n_index-1] = a_s_char->a[n_index];
   }
   a_s_char->n_capacity -=1;
   a_s_char->n_length -=1;
   a_s_char->a = realloc(a_s_char->a, a_s_char->n_length * sizeof(char));
}
int f_n_index_a_s_char(
   A_s_char * a_s_char, 
   char s_char 
){
   int n_i = 0;
   int n_index = -1; 
   while(n_i < a_s_char->n_length){
      if(a_s_char->a[n_i] == s_char){
         n_index = n_i;
         break;
      }
      n_i+=1;
   }
   return n_index;
}
void f_shift_a_s_char(
   A_s_char * a_s_char
){
   f_remove_by_index_a_s_char(a_s_char, 0);
}
void f_pop_a_s_char(
   A_s_char * a_s_char 
){
   f_remove_by_index_a_s_char(a_s_char, a_s_char->n_length-1);
}
void f_free_a_s_char(
   A_s_char * a_s_char
){
   free(a_s_char->a);
   a_s_char->a = NULL;
   a_s_char->n_capacity = 0;
   a_s_char->n_length = 0;
}
// end array for char ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 

// now if we want arrays of different types we would have to create the whole struct 
// multiple times foreach type
// struct A_s_char...   -> char => 8bit 
// struct A_n_short...  -> char => 16bit 
// struct A_n_int...    -> char => 32bit  
// that is why we use the preprocessor !!!

void f_dynamic_a_s_char(){
   // A_s_char * a_s_cahr = f_a_s_char_new();
   A_s_char a_s_char;
   f_init_a_s_char(&a_s_char);
   f_push_a_s_char(&a_s_char,'h');
   f_push_a_s_char(&a_s_char,'a');
   f_push_a_s_char(&a_s_char,'l');
   f_push_a_s_char(&a_s_char,'l');
   f_push_a_s_char(&a_s_char,'o');
   f_push_a_s_char(&a_s_char,'?');
   f_push_a_s_char(&a_s_char,'!');
   // printf("s is %s", a_s_char.a);

   printf("a_s_char printed as string (printf %%s): %s\n", a_s_char.a);

   f_remove_by_index_a_s_char(&a_s_char, 2);

   printf("\n");

   printf("a_s_char.a[0] %i\n", a_s_char.a[0]);
   printf("a_s_char.a[1] %i\n", a_s_char.a[1]);
   printf("a_s_char.a[2] %i\n", a_s_char.a[2]);
   printf("a_s_char.a[3] %i\n", a_s_char.a[3]);
   printf("a_s_char printed as string (printf %%s): %s\n", a_s_char.a);

   int n_index_of_question_mark = f_n_index_a_s_char(&a_s_char, '?');
   printf("index of '?' is : %i\n", n_index_of_question_mark);

   int n_index_of_nonexisting_char = f_n_index_a_s_char(&a_s_char, 'q');
   printf("index of 'q' is : %i\n", n_index_of_nonexisting_char);

   f_shift_a_s_char(&a_s_char);
   f_pop_a_s_char(&a_s_char);
   printf("a_s_char printed as string (printf %%s): %s\n", a_s_char.a);

}






int main() {
   
   // f_wtf_why_is_this_working();
   // f_dynamic_allocated_array();
   // f_dynamic_array_manual();

   f_dynamic_a_s_char();



   return 0;
}
