
// c file 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int f_char_pointer_test(){
  char * a =  "asdff"; 
  int n_len = strlen(a);
  printf("strlen(char * a = 'asdff'); = %i\n", n_len);

  // segmentation fault
  // char * a2;
  // int n_len2 = strlen(a2);
  // printf("strlen(char * a2;) = %i\n", n_len2);

  char * a3 = malloc(0);
  printf("strlen(char * a3 = malloc(0);) = %li\n", strlen(a3));

  char * a4 = malloc(1);
  printf("strlen(char * a4 = malloc(1);) = %li\n", strlen(a4));

  char * a5 = malloc(99);
  printf("strlen(char * a5 = malloc(99);) = %li\n", strlen(a5));

  a3 = "wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_";
  printf("strlen(a3=\"wtf_wtf_wtf_....\";) = %li\n", strlen(a3));

  a4 = "wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_wtf_";
  printf("strlen(a4=\"wtf_wtf_wtf_....\";) = %li\n", strlen(a4));


  char * s_string = malloc(0);
  s_string = "1234567";
  // s_string[7] = 'a'; // why not working ?...
  s_string = "123456a"; // but this works...
  printf("s_string = %s\n", s_string);
  s_string = "123412341234123412341234"; // does this do a realloc ?

  return 0;

}

char * f_s_ireturncharpointer(){
  char * s_im_the_char_pointer = malloc(0);
  return s_im_the_char_pointer;
}
int main() {
   /* my first program in C */
   printf("main function called");
   f_char_pointer_test();

  char * my_test_string = f_s_ireturncharpointer();
  printf("char pointer is %p\n", my_test_string);
  my_test_string = "adfs";
  printf("char pointer is %p\n", my_test_string);

  printf("printing content of char pointer: %s\n", my_test_string);

  printf("printing first my_test_string[0]: %c\n", my_test_string[0]);
  printf("printing first my_test_string[1]: %c\n", my_test_string[1]);
  printf("printing first my_test_string[2]: %c\n", my_test_string[2]);
  printf("printing first my_test_string[3]: %c\n", my_test_string[3]);
  printf("printing first my_test_string[4]: %c\n", my_test_string[4]);
  printf("printing first my_test_string[5]: %c\n", my_test_string[5]);
   
  return 0;
   
}
