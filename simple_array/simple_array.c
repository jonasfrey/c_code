
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// this is our object 
// which we want to have an array of 
typedef struct {
   int n_id;
   char s_name[100];
} O_person;


// this is the object 
// which handles the dynamic array
typedef struct
{
   O_person *a;
   size_t n_length;
} O_a_o_person;

void f_init_o_a_o_person(O_a_o_person *o, size_t n_length)
{
   o->a = malloc(n_length * sizeof(O_person));
   o->n_length = n_length;
}

void f_push_o_a_o_person(O_a_o_person *o, O_person *o_person)
{
   o->n_length = o->n_length+1;
   o->a = realloc(o->a, o->n_length * sizeof(O_person));
   o->a[o->n_length-1] = *o_person;

}

void f_remove_o_a_o_person(O_a_o_person *o, size_t n_index)
{
   
   for(size_t n_idx = n_index; n_idx < o->n_length; n_idx++){
      o->a[n_idx] = o->a[n_idx+1];
   }
   o->n_length -=1;
   o->a = realloc(o->a, o->n_length * sizeof(O_person));
}

void f_free_o_a_o_person(O_a_o_person *o)
{
   free(o->a);
   o->a = NULL;
   o->n_length = 0;
}


int main() {
   // in c we need a custom object which acts as an array to be able to have an array of objects

   O_a_o_person o_a_o_person;
   f_init_o_a_o_person(&o_a_o_person, 0);

  O_person o_person__1;
  strcpy(o_person__1.s_name, "Hans Peter");
  o_person__1.n_id = 1; 
  f_push_o_a_o_person(&o_a_o_person, &o_person__1);

  O_person o_person__2;
  strcpy(o_person__2.s_name, "Anina Benene");
  o_person__2.n_id = 2; 
  f_push_o_a_o_person(&o_a_o_person, &o_person__2);

  O_person o_person__3;
  strcpy(o_person__3.s_name, "Carlos caranga");
  o_person__3.n_id = 3; 
  f_push_o_a_o_person(&o_a_o_person, &o_person__3);

  O_person o_person__4;
  strcpy(o_person__4.s_name, "Deline delene");
  o_person__4.n_id = 4; 
  f_push_o_a_o_person(&o_a_o_person, &o_person__4);

  O_person o_person__5;
  strcpy(o_person__5.s_name, "Eugen eugustus");
  o_person__5.n_id = 5; 
  f_push_o_a_o_person(&o_a_o_person, &o_person__5);

   for(size_t n = 0; n < o_a_o_person.n_length; n+=1){
      O_person o_person = o_a_o_person.a[n];
      printf("o_a_o_person->a[%lu]\n: ", n);
      printf("n_id: %d\n", o_person.n_id);
      printf("s_name: %s\n", o_person.s_name);
      printf("---\n");
   }
   f_free_o_a_o_person(&o_a_o_person);

printf("done");

}
