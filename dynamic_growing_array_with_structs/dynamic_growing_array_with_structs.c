
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



char * a_s_name[11] = {
   "Dachshund",
   "Dalmadoodle",
   "Eagle",
   "Earthworm",
   "Earwig",
   "Eastern Barred Bandicoot",
   "Falcon",
   "Fallow deer",
};

char * f_s_name(){
   double n_max = 1; 
   double n_min = 0;
   double n_range = (n_max - n_min); 
   double n_division = RAND_MAX / n_range;
   double n_random_normalized = n_min + (rand() / n_division);

   printf("rand %f: \n", n_random_normalized);
   int n_random_index = (int) ((double) (11-1) * n_random_normalized);
   char * s_name = a_s_name[n_random_index];
   return s_name;
}

typedef struct O_person{
   int n_id;
   // char * s_name; 
   char s_name[100];
} O_person;

typedef struct{
   size_t n_capacity; 
   size_t n_length; 
   O_person * a; 
} A_o_person;
void f_init_a_o_person(
   A_o_person * a_o_person
){
   a_o_person->n_capacity = 0; 
   a_o_person->n_length = 0;
   a_o_person->a = malloc(a_o_person->n_capacity * sizeof(O_person)); 
   // return &a_o_person;
}
void f_insertafterindex_a_o_person(
   A_o_person * a_o_person, 
   O_person o_person, 
   size_t n_index
){
   a_o_person->n_capacity +=1;
   a_o_person->n_length +=1;
   a_o_person->a = realloc(a_o_person->a, a_o_person->n_length * sizeof(O_person));
   int n_i_reversed = a_o_person->n_length -1;
   while(n_i_reversed > n_index){
      a_o_person->a[n_i_reversed] = a_o_person->a[n_i_reversed-1];
      n_i_reversed-=1;
   }
   a_o_person->a[n_index] = o_person;
}
void f_push_a_o_person(
   A_o_person * a_o_person, 
   O_person o_person
){
   f_insertafterindex_a_o_person(a_o_person, o_person, a_o_person->n_length);
}

void f_insertbeforeindex_a_o_person(
   A_o_person * a_o_person, 
   O_person o_person,
   size_t n_index
){
   f_insertafterindex_a_o_person(a_o_person, o_person, n_index-1);
}
void f_remove_by_index_a_o_person(
   A_o_person * a_o_person, 
   int n_index 
){
   while(n_index < a_o_person->n_length){
      n_index+=1;
      a_o_person->a[n_index-1] = a_o_person->a[n_index];
   }
   a_o_person->n_capacity -=1;
   a_o_person->n_length -=1;
   a_o_person->a = realloc(a_o_person->a, a_o_person->n_length * sizeof(O_person));
}
int f_n_index_a_o_person(
   A_o_person * a_o_person, 
   O_person * o_person 
){

   int n_i = 0;
   int n_index = -1; 
   while(n_i < a_o_person->n_length){
      int n = memcmp(&a_o_person->a[n_i], o_person, sizeof(O_person));
      // memcopy returns (n<0) the first byte that does not match in both memory blocks has a lower value in ptr1 than in ptr2 (if evaluated as unsigned char values) 
      // memcpy  returns (n == 0) the contents of both memory blocks are equal
      // memcopy return (n>0) he first byte that does not match in both memory blocks has a greater value in ptr1 than in ptr2 (if evaluated as unsigned char values)
      if(n == 0){ 
         n_index = n_i; 
         break;
      }
      n_i+=1;
   }
   return n_index;
}
void f_shift_a_o_person(
   A_o_person * a_o_person
){
   f_remove_by_index_a_o_person(a_o_person, 0);
}
void f_pop_a_o_person(
   A_o_person * a_o_person 
){
   f_remove_by_index_a_o_person(a_o_person, a_o_person->n_length-1);
}
void f_free_a_o_person(
   A_o_person * a_o_person
){
   free(a_o_person->a);
   a_o_person->a = NULL;
   a_o_person->n_capacity = 0;
   a_o_person->n_length = 0;
}


void f_dynamic_a_o_person(){
   int n_i;
   // a_o_person * a_s_cahr = f_a_o_person_new();
   A_o_person a_o_person;
   f_init_a_o_person(&a_o_person);

   O_person o_person1; 
   o_person1.n_id = 1;
   // char * o_person1_s_name = "hans"; 
   // o_person1.s_name = o_person1_s_name;
   strcpy(o_person1.s_name,"hans");
   f_push_a_o_person(&a_o_person,o_person1);

   O_person o_person2;
   o_person2.n_id = 2; 
   // char * o_person2_s_name = "peter"; 
   // o_person2.s_name = o_person2_s_name;
   strcpy(o_person2.s_name,"peter");
   f_push_a_o_person(&a_o_person,o_person2);
   
   n_i = 0; 
   while(n_i < a_o_person.n_length){
      printf("a_o_person.a[%i].n_id: %i\n", n_i, a_o_person.a[n_i].n_id);
      printf("a_o_person.a[%i].s_name: %s\n", n_i, a_o_person.a[n_i].s_name);
      n_i+=1;
   }

   f_remove_by_index_a_o_person(&a_o_person, 0);
   
   
   printf("called f_remove_by_index_a_o_person(&a_o_person, 0);\n");

   n_i = 0; 
   while(n_i < a_o_person.n_length){
      printf("a_o_person.a[%i].n_id: %i\n", n_i, a_o_person.a[n_i].n_id);
      printf("a_o_person.a[%i].s_name: %s\n", n_i, a_o_person.a[n_i].s_name);
      n_i+=1;
   }

   // printf("ptr .a[0]: %p", &a_o_person.a[0]);
   int n_index_of_person2 = f_n_index_a_o_person(&a_o_person, &o_person2);
   printf("n_index_of_person2 %i\n", n_index_of_person2);


   // can we push the same struct multiple times ? 
   char * s_name_random;
   int n_random = rand();  
   n_random = rand();
   s_name_random = f_s_name();
   strncpy(o_person2.s_name,s_name_random, strlen(s_name_random));
   o_person2.n_id = n_random;
   f_push_a_o_person(&a_o_person,o_person2);
   n_random = rand();  
   s_name_random = f_s_name();
   strncpy(o_person2.s_name,s_name_random, strlen(s_name_random));
   o_person2.n_id = n_random;
   f_push_a_o_person(&a_o_person,o_person2);
   n_random = rand();  
   s_name_random = f_s_name();
   strncpy(o_person2.s_name,s_name_random, strlen(s_name_random));
   o_person2.n_id = n_random;
   f_push_a_o_person(&a_o_person,o_person2);
   n_random = rand();  
   s_name_random = f_s_name();
   strncpy(o_person2.s_name,s_name_random, strlen(s_name_random));
   o_person2.n_id = n_random;
   f_push_a_o_person(&a_o_person,o_person2);
   n_random = rand();  
   s_name_random = f_s_name();
   strncpy(o_person2.s_name,s_name_random, strlen(s_name_random));
   o_person2.n_id = n_random;
   f_push_a_o_person(&a_o_person,o_person2);


   
   n_i = 0; 
   while(n_i < a_o_person.n_length){
      printf("a_o_person.a[%i].n_id: %i\n", n_i, a_o_person.a[n_i].n_id);
      printf("a_o_person.a[%i].s_name: %s\n", n_i, a_o_person.a[n_i].s_name);
      n_i+=1;
   }

   // yes.. 
   printf("after shift and pop \n");

   f_shift_a_o_person(&a_o_person);
   f_pop_a_o_person(&a_o_person);

      
   n_i = 0; 
   while(n_i < a_o_person.n_length){
      printf("a_o_person.a[%i].n_id: %i\n", n_i, a_o_person.a[n_i].n_id);
      printf("a_o_person.a[%i].s_name: %s\n", n_i, a_o_person.a[n_i].s_name);
      n_i+=1;
   }

   printf("insert legolas after index 2, insert leonie before index 2\n");
   // insert object before or after a certain index

   // after index 2
   O_person o_person; 
   o_person.n_id = 19;
   strcpy(o_person.s_name,"legolas");
   f_insertafterindex_a_o_person(&a_o_person,o_person, 2);

   // insert before index 2
   o_person.n_id = 43;
   strcpy(o_person.s_name, "leonie");
   f_insertbeforeindex_a_o_person(&a_o_person,o_person, 2);


   n_i = 0; 
   while(n_i < a_o_person.n_length){
      printf("a_o_person.a[%i].n_id: %i\n", n_i, a_o_person.a[n_i].n_id);
      printf("a_o_person.a[%i].s_name: %s\n", n_i, a_o_person.a[n_i].s_name);
      n_i+=1;
   }


}


int main() {
   srand(time(NULL));   // Initialization, should only be called once.

   /* my first program in C */
   printf("main function called\n");

   f_dynamic_a_o_person();
   
   return 0;
}
