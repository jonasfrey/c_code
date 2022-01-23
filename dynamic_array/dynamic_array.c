#include <stdio.h>
#include "./../c_helpers/dnd.c"

#include <stdlib.h>

// original code 
// credits: https://stackoverflow.com/questions/3536153/c-dynamically-growing-array

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}
int getArraySize(Array a){
   
   dndli(sizeof(a.array));
   dndli(sizeof(a.array[0]));
   dndli(sizeof(a));
   dndli(a.size);
   return sizeof(a) / sizeof(a.array[0]);
   
}


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
   a->length = a->length;
}

void array_free(A_array *a) {
  free(a->array);
  a->array = NULL;
  a->length = a->full_size = 0;
}

void test_original_code(){

   Array a_dynamic_array; 

   initArray(&a_dynamic_array, 1);

   // not working
   //a_dynamic_array[0] = 10;
   //a_dynamic_array[1] = 22;
   //a_dynamic_array[2] = 33;

   // working
   a_dynamic_array.array[0] = 10;
   a_dynamic_array.array[1] = 22;
   a_dynamic_array.array[2] = 33;

   // insertArray(&a_dynamic_array, 10);  
   // insertArray(&a_dynamic_array, 22);  
   // insertArray(&a_dynamic_array, 33);
     
   int n_i = 0;

   dnd(getArraySize(a_dynamic_array))
   dndli(a_dynamic_array.used); // this is wrongly 0

   
   dnd(a_dynamic_array.array[2]);

   for(n_i = 0; n_i < sizeof(a_dynamic_array.array); n_i++){
      dnd(a_dynamic_array.array[n_i]);
   }


   Array a_dynamic_array_using_push; 

   initArray(&a_dynamic_array_using_push, 1);

   // working
   insertArray(&a_dynamic_array_using_push, 10);
   insertArray(&a_dynamic_array_using_push, 22);
   insertArray(&a_dynamic_array_using_push, 33);

   n_i = 0;

   dnd(getArraySize(a_dynamic_array_using_push))
   dndli(a_dynamic_array_using_push.used) // this is correctly 3 
   
   dnd(a_dynamic_array_using_push.array[2]);


   for(n_i = 0; n_i < sizeof(a_dynamic_array_using_push.array); n_i++){
      dnd(a_dynamic_array_using_push.array[n_i]);
   }

}

void test_my_code(){

   A_array a_test; 
   array_init(&a_test, 0);
   array_push(&a_test, 1); 

   dnd(a_test.length);

   array_push(&a_test, 11234); 
   dnd(a_test.length); 

   array_push(&a_test, 1); 
   array_push(&a_test, 1); 
   array_push(&a_test, 2); 
   array_push(&a_test, 3); 
   array_push(&a_test, 5); 
   array_push(&a_test, 8);

   array_remove(a_test); 

}
int main() {

   test_original_code();


   test_my_code();

   return 0;
}
