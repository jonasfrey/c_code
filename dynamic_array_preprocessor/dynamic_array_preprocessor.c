
// c file 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// now since we dont want to create all those funcitons
// for a dynamic array for every datatype or struct it can hold
// we use the preprocessor which creates all the functions for us

// n_    = number
// s_    = string or char
// a_    = array
// o_    = object or struct
// f_    = function 
// fp_   = function preprocessor

#define fp_create_dynamic_array_typedef_struct(s_typename_array, s_varname_array, s_typename_element, s_varname_element) \
typedef struct s_typename_array{\
   size_t n_capacity;\
   size_t n_length;\
   s_typename_element * a;\
} s_typename_array;

#define fp_create_dynamic_array_f_init(s_typename_array, s_varname_array, s_typename_element, s_varname_element) \
void f_init_##s_varname_array(\
   s_typename_array * s_varname_array\
){\
   s_varname_array->n_capacity = 0;\
   s_varname_array->n_length = 0;\
   s_varname_array->a = malloc(s_varname_array->n_capacity * sizeof(s_typename_element));\
}

#define fp_create_dynamic_array_f_insertafterindex(s_typename_array, s_varname_array, s_typename_element, s_varname_element) \
void f_insertafterindex_##s_varname_array(\
   s_typename_array * s_varname_array,\
   s_typename_element s_varname_element,\
   size_t n_index\
){\
   s_varname_array->n_capacity +=1;\
   s_varname_array->n_length +=1;\
   s_varname_array->a = realloc(s_varname_array->a, s_varname_array->n_length * sizeof(s_typename_element));\
   int n_i_reversed = s_varname_array->n_length -1;\
   while(n_i_reversed > n_index){\
      s_varname_array->a[n_i_reversed] = s_varname_array->a[n_i_reversed-1];\
      n_i_reversed-=1;\
   }\
   s_varname_array->a[n_index] = s_varname_element;\
}

#define fp_create_dynamic_array_f_push(s_typename_array, s_varname_array, s_typename_element, s_varname_element) \
void f_push_ ##s_varname_array(\
   s_typename_array * s_varname_array,\
   s_typename_element s_var_name_element\
){\
   f_insertafterindex_ ##s_varname_array(s_varname_array, s_var_name_element, s_varname_array->n_length);\
}

#define fp_create_dynamic_array_f_insertbeforeindex(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
void f_insertbeforeindex_a_o_person(\
   s_typename_array * s_varname_array,\
   s_typename_element s_var_name_element,\
   size_t n_index\
){\
   f_insertafterindex_ ##s_varname_array(s_varname_array, s_var_name_element, n_index-1);\
}

#define fp_create_dynamic_array_f_remove_by_index(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
void f_remove_by_index_##s_varname_array(\
   s_typename_array * s_varname_array,\
   int n_index\
){\
   while(n_index < s_varname_array->n_length){\
      n_index+=1;\
      s_varname_array->a[n_index-1] = s_varname_array->a[n_index];\
   }\
   s_varname_array->n_capacity -=1;\
   s_varname_array->n_length -=1;\
   s_varname_array->a = realloc(s_varname_array->a, s_varname_array->n_length * sizeof(s_typename_element));\
}

#define fp_create_dynamic_array_f_n_index(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
int f_n_index_##s_varname_array(\
   s_typename_array * s_varname_array,\
   s_typename_element * s_varname_element\
){\
   int n_i = 0;\
   int n_index = -1;\
   while(n_i < s_varname_array->n_length){\
      int n = memcmp(&s_varname_array->a[n_i], s_varname_element, sizeof(s_typename_element));\
      if(n == 0){\
         n_index = n_i;\
         break;\
      }\
      n_i+=1;\
   }\
   return n_index;\
}
#define fp_create_dynamic_array_f_shift(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
void f_shift_##s_varname_array(\
   s_typename_array * s_varname_array\
){\
   f_remove_by_index_##s_varname_array(s_varname_array, 0);\
}
#define fp_create_dynamic_array_f_pop(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
void f_pop_##s_varname_array(\
   s_typename_array * s_varname_array\
){\
   f_remove_by_index_##s_varname_array(s_varname_array, s_varname_array->n_length-1);\
}
#define fp_create_dynamic_array_f_free(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
void f_free_##s_varname_array(\
   s_typename_array * s_varname_array\
){\
   free(s_varname_array->a);\
   s_varname_array->a = NULL;\
   s_varname_array->n_capacity = 0;\
   s_varname_array->n_length = 0;\
}

#define fp_create_dynamic_array(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_typedef_struct(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_init(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_insertafterindex(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_push(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_insertbeforeindex(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_remove_by_index(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_n_index(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_shift(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_pop(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_free(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\



typedef struct O_animal {
   unsigned int n_id; 
   char  s_name[50];
} O_animal;

void f_create_dynamic_array_demo_with_o_animal(){
   int n_i;
   char a_s_name[22][1024] = {
         "Rabbit",
         "Duck",
         "Pig",
         "Bee",
         "Goat",
         "Crab",
         "Fish",
         "Chicken",
         "Horse",
         "Dog",
         "Llamas",
         "Ostriches",
         "Camels",
         "Shrimp",
         "Deer",
         "Turkey",
         "Dove",
         "Sheep",
         "Cat",
         "Geese",
         "Oxen",
         "Reindeer"
   };

   for (int i = 0; i < 22; ++i) {
      printf("%s, \n", a_s_name[i]);

   }
   
   fp_create_dynamic_array(A_o_animal, a_o_animal, O_animal, o_animal); // this will create all needed functions for the array

   A_o_animal a_o_animal;
   O_animal o_animal;
   for(n_i = 0; n_i < 10; n_i++)
   {
      o_animal.n_id = n_i+1;
      strncpy(o_animal.s_name, a_s_name[n_i], sizeof(a_s_name[n_i])); 
      f_push_a_o_animal(&a_o_animal, o_animal);
      // printf("string = %s \t address = %u\n", a_s_name + n_i, a_s_name + n_i);
   }

   printf("len %i", a_o_animal.n_length);
   n_i = 0;
   while(n_i < a_o_animal.n_length){
      printf("a_o_animal.a[%i].n_id: %i\n", n_i, a_o_animal.a[n_i].n_id);
      printf("a_o_animal.a[%i].s_name: %s\n", n_i, a_o_animal.a[n_i].s_name);
      n_i+=1;
   }

   f_shift_a_o_animal(&a_o_animal);
   printf("array after f_shift \n");
   n_i = 0;
   while(n_i < a_o_animal.n_length){
      printf("a_o_animal.a[%i].n_id: %i\n", n_i, a_o_animal.a[n_i].n_id);
      printf("a_o_animal.a[%i].s_name: %s\n", n_i, a_o_animal.a[n_i].s_name);
      n_i+=1;
   }

   f_pop_a_o_animal(&a_o_animal);
   printf("array after f_pop \n");
   n_i = 0;
   while(n_i < a_o_animal.n_length){
      printf("a_o_animal.a[%i].n_id: %i\n", n_i, a_o_animal.a[n_i].n_id);
      printf("a_o_animal.a[%i].s_name: %s\n", n_i, a_o_animal.a[n_i].s_name);
      n_i+=1;
   }
}

int main() {
   /* my first program in C */
   printf("main function called");
   
   f_create_dynamic_array_demo_with_o_animal();
   return 0;
}

