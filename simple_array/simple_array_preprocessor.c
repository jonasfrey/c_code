#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef B_SIMPLE_ARRAY_PREPROCESSOR
#define B_SIMPLE_ARRAY_PREPROCESSOR
#endif



#define fp_create_o_a_o__struct(s_object_name) \
typedef struct O_a_o_##s_object_name{\
   size_t n_length;\
   O_##s_object_name * a_o;\
} O_a_o_##s_object_name;


#define fp_create_f_init__o_a_o_(s_object_name) \
void f_init_o_a_o_##s_object_name(\
   O_a_o_##s_object_name * o\
){\
   o->n_length = 0;\
   o->a_o = malloc(o->n_length * sizeof(O_##s_object_name));\
}

#define fp_create_f_push__o_a_o_(s_object_name) \
void f_push_o_a_o_##s_object_name(\
   O_a_o_##s_object_name * o,\
   O_##s_object_name o_##s_object_name\
){\
   o->n_length = o->n_length+1;\
   o->a_o = realloc(o->a_o, o->n_length * sizeof(O_##s_object_name));\
   o->a_o[o->n_length-1] = o_##s_object_name;\
}


#define fp_create_f_remove__o_a_o_(s_object_name) \
void f_remove_o_a_o_##s_object_name(\
   O_a_o_##s_object_name * o,\
   size_t n_index\
){\
   for(size_t n_idx = n_index; n_idx < o->n_length; n_idx++){\
      o->a_o[n_idx] = o->a_o[n_idx+1];\
   }\
   o->n_length -=1;\
   o->a_o = realloc(o->a_o, o->n_length * sizeof(O_##s_object_name));\
}

#define fp_create_f_free__o_a_o_(s_object_name) \
void f_free_o_a_o_##s_object_name(\
   O_a_o_##s_object_name * o\
){\
   free(o->a_o);\
   o->a_o = NULL;\
   o->n_length = 0;\
}

#define fp_create_o_a_o(s_object_name)\
    fp_create_o_a_o__struct(s_object_name)\
    fp_create_f_init__o_a_o_(s_object_name)\
    fp_create_f_push__o_a_o_(s_object_name)\
    fp_create_f_remove__o_a_o_(s_object_name)\
    fp_create_f_free__o_a_o_(s_object_name)
