
// c file 
#include <stdio.h>
typedef struct{
   size_t n_capacity; 
   size_t n_length; 
   char * a; 
} A_o_person;
void f_init_a_o_person(
   A_o_person * a_o_person
){
   a_o_person->n_capacity = 0; 
   a_o_person->n_length = 0;
   a_o_person->a = malloc(a_o_person->n_capacity * sizeof(char)); 
   // return &a_o_person;
}
void f_push_a_o_person(
   A_o_person * a_o_person, 
   char s_char
){
   a_o_person->n_capacity +=1;
   a_o_person->n_length +=1;
   a_o_person->a = realloc(a_o_person->a, a_o_person->n_length * sizeof(char));
   a_o_person->a[a_o_person->n_length-1] = s_char;
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
   a_o_person->a = realloc(a_o_person->a, a_o_person->n_length * sizeof(char));
}
int f_n_index_a_o_person(
   A_o_person * a_o_person, 
   char s_char 
){
   int n_i = 0;
   int n_index = -1; 
   while(n_i < a_o_person->n_length){
      if(a_o_person->a[n_i] == s_char){
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

typedef struct O_person{
   int n_id;
   char s_name[50]; 
}

void f_dynamic_a_o_person(){
   int n_i;
   // a_o_person * a_s_cahr = f_a_o_person_new();
   A_o_person a_o_person;
   f_init_a_o_person(&a_o_person);
   O_person o_person1; 
   o_person1.n_id = 1; 
   o_person1.s_name = "hans"; 
   f_push_a_o_person(&a_o_person,o_person1);

   o_person2.n_id = 2; 
   o_person2.s_name = "peter"; 
   f_push_a_o_person(&a_o_person,o_person2);

   n_i = 0; 
   while(n_i < a_o_person.n_length){
      printf("a_o_person.a[%i].n_id: %i\n", n_i, a_o_person.a[n_i].n_id);
      printf("a_o_person.a[%i].s_name: %s\n", n_i, a_o_person.a[n_i].s_name);
      n_i+=1;
   }

   f_remove_by_index_a_o_person(&a_o_person, 0);

   n_i = 0; 
   while(n_i < a_o_person.n_length){
      printf("a_o_person.a[%i].n_id: %i\n", n_i, a_o_person.a[n_i].n_id);
      printf("a_o_person.a[%i].s_name: %s\n", n_i, a_o_person.a[n_i].s_name);
      n_i+=1;
   }

   printf("\n");

   printf("a_o_person.a[0] %i\n", a_o_person.a[0]);
   printf("a_o_person.a[1] %i\n", a_o_person.a[1]);
   printf("a_o_person.a[2] %i\n", a_o_person.a[2]);
   printf("a_o_person.a[3] %i\n", a_o_person.a[3]);
   printf("a_o_person printed as string (printf %%s): %s\n", a_o_person.a);

   int n_index_of_question_mark = f_n_index_a_o_person(&a_o_person, '?');
   printf("index of '?' is : %i\n", n_index_of_question_mark);

   int n_index_of_nonexisting_char = f_n_index_a_o_person(&a_o_person, 'q');
   printf("index of 'q' is : %i\n", n_index_of_nonexisting_char);

   f_shift_a_o_person(&a_o_person);
   f_pop_a_o_person(&a_o_person);
   printf("a_o_person printed as string (printf %%s): %s\n", a_o_person.a);

}


int main() {
   /* my first program in C */
   printf("main function called");
   
   return 0;
}
