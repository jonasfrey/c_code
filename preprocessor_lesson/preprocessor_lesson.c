
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fp_create_function_with_prefix(s_type) \
void s_type##asdf() \
{ \
   printf("function called!!\n"); \
}


#define fp_create_function_with_suffix(s_suffix) \
void trololol_## s_suffix() \
{ \
   printf("trololol_" #s_suffix " called!!\n"); \
}

#define s_space ' '



// now if we want arrays of different types we would have to create the whole struct 
// multiple times foreach type
// struct A_s_char...   -> char => 8bit 
// struct A_n_short...  -> char => 16bit 
// struct A_n_int...    -> char => 32bit  
// that is why we use the preprocessor !!!
#define fp_create_dynamic_array_struct(s_struct_name, s_type) \
typedef struct s_struct_name{ \
   size_t n_capacity; \
   size_t n_length; \
   s_type * a; \
}  s_struct_name

#define fp_create_dynamic_array_f_init(s_struct_name, s_var_name_array, s_type) \
void f_ ##s_var_name_array## _init( \
   s_struct_name * s_var_name_array \
){ \
   s_var_name_array->n_capacity = 1; \
   s_var_name_array->n_length = 0; \
   s_var_name_array->a = malloc( s_var_name_array->n_capacity * sizeof(s_type)); \
}
#define fp_create_dynamic_array_f_push(s_struct_name, s_var_name_array, s_var_name_element, s_type)\
void f_ ##s_var_name_array ##_push(\
   s_struct_name * s_var_name_array,\
   s_type s_var_name_element\
){\
   s_var_name_array->n_length +=1;\
   s_var_name_array->a = realloc( s_var_name_array->a, s_var_name_array->n_length * sizeof(s_type));\
   s_var_name_array->a[s_var_name_array->n_length-1] = s_var_name_element;\
   s_var_name_array->n_capacity = s_var_name_array->n_length;\
}
#define fp_create_dynamic_array_f_free(s_struct_name, s_var_name_array, s_var_name_element, s_type)\
void f_ ##s_var_name_array ##_free(\
   s_struct_name * s_var_name_array\
){\
   free(s_var_name_array->a);\
   s_var_name_array->a = NULL;\
   s_var_name_array->n_capacity = 0;\
   s_var_name_array->n_length = 0;\
}

#define fp_create_dynamic_array(s_struct_name, s_var_name_array, s_var_name_element, s_type)\
   fp_create_dynamic_array_struct(s_struct_name, s_type);\
   fp_create_dynamic_array_f_init(s_struct_name, s_var_name_array, s_type);\
   fp_create_dynamic_array_f_push(s_struct_name, s_var_name_array, s_var_name_element, s_type);\
   fp_create_dynamic_array_f_free(s_struct_name, s_var_name_array, s_var_name_element, s_type);


typedef struct O_person {
  int n_id;
//   char * s_name;
  char s_name[50];
} O_person;

int main() {
   /* my first program in C */
   // printf("main function called");

   fp_create_function_with_prefix(int); 
   intasdf();

   fp_create_function_with_prefix(lol);
   lolasdf(); 

   fp_create_function_with_suffix(wtf_is_this);
   trololol_wtf_is_this();

   fp_create_dynamic_array(A_s_char, a_s_char, s_char, char);
   A_s_char a_s_char;
   f_a_s_char_init(&a_s_char);
   printf(".n_capacity %i \n", a_s_char.n_capacity);
   f_a_s_char_push(&a_s_char, 'e');
   // f_a_s_char_push(&a_s_char, 'l');
   // f_a_s_char_push(&a_s_char, 'l');
   // f_a_s_char_push(&a_s_char, '0');

   printf("a_s_char.a[0] %i\n", a_s_char.a[0]);
   // printf("a_s_char.a[1] %i\n", a_s_char.a[1]);
   // printf("a_s_char.a[2] %i\n", a_s_char.a[2]);
   // printf("a_s_char.a[3] %i\n", a_s_char.a[3]);
   
   f_a_s_char_free(&a_s_char);


   // for example an array of O_person
   fp_create_dynamic_array(A_o_person, a_o_person, o_person, O_person);
   A_o_person a_o_person;
   f_a_o_person_init(&a_o_person);

   O_person o_person_1;
   o_person_1.n_id = 321;
   strcpy(o_person_1.s_name, "Mister Mud");
   f_a_o_person_push(&a_o_person, o_person_1);
   printf("a_o_person.a[0].n_id %i\n", a_o_person.a[0].n_id);

   return 0;


}
