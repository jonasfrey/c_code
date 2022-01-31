#include <stdlib.h>

typedef struct {
  int *array;
  size_t length;
  size_t full_size;
} A_array;

void array_init(A_array *a, size_t   n_initial_length) {
  a->array = malloc(n_initial_length * sizeof(int));
  a->length = n_initial_length; // only the size/length of the actual used elements
  a->full_size = n_initial_length; // the real size of the array, can contain empty elements
}

void array_push(A_array *a, int element) {
  // a->length is the number of length entries, because a->array[a->length++] updates a->length only *after* the array has been accessed.
  // Therefore a->length can go up to a->size 
  if (a->length == a->full_size) {
    a->full_size *= 2; // 'reserve' more space for incoming elmeents
    a->array = realloc(a->array, a->full_size * sizeof(int));
  }
  int n_new_length = a->length + 1;
  a->length = n_new_length; 
  a->array[ a->length ] = element; //insert the element  

}
// removes last from array
void array_pop(A_array *a){
   a->length = a->length-1;
}

void array_free(A_array *a) {
  free(a->array);
  a->array = NULL;
  a->length = a->full_size = 0;
}

