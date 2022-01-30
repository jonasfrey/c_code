
// c file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./../c_helpers/dnd.c"

#define typename(x) _Generic((x),                                      \
                             _Bool                                     \
                             : "_Bool", unsigned char                  \
                             : "unsigned char",                        \
                               char                                    \
                             : "char", signed char                     \
                             : "signed char",                          \
                               short int                               \
                             : "short int", unsigned short int         \
                             : "unsigned short int",                   \
                               int                                     \
                             : "int", unsigned int                     \
                             : "unsigned int",                         \
                               long int                                \
                             : "long int", unsigned long int           \
                             : "unsigned long int",                    \
                               long long int                           \
                             : "long long int", unsigned long long int \
                             : "unsigned long long int",               \
                               float                                   \
                             : "float", double                         \
                             : "double",                               \
                               long double                             \
                             : "long double", char *                   \
                             : "pointer to char",                      \
                               void *                                  \
                             : "pointer to void", int *                \
                             : "pointer to int",                       \
                               default                                 \
                             : "other")

char *substr(const char *src, int n_start, int n_end)
{
   int len = n_end - n_start;

   char *dest = (char *)malloc(sizeof(char) * (len + 1));

   for (int i = n_start; i < n_end && (*(src + i) != '\0'); i++)
   {
      *dest = *(src + i);
      dest++;
   }

   *dest = '\0';

   return dest - len;
}

char *get_string_unitl_first_char(const char *s_string, char s_char)
{

   char *index_of_char = strstr(s_string, (char[2]){(char)s_char, '\0'});
   char *s_all_before_first_equal = substr(s_string, 0, index_of_char - s_string);

   return s_all_before_first_equal;
}

char *get_string_after_first_char(const char *s_string, char s_char)
{

   char *index_of_equal = strstr(s_string, (char[2]){(char)s_char, '\0'});
   char *s_all_after_first_equal = index_of_equal + 1;
   return s_all_after_first_equal;
}

void string_by_index()
{

   char *s_test = "asdf=1=2=3=4";

   char *s_all_before_first_equal = get_string_unitl_first_char(s_test, '=');
   printf("%s\n", s_all_before_first_equal);
   char *s_all_after_first_equal = get_string_after_first_char(s_test, '=');
   printf("%s\n", s_all_after_first_equal);
}

void string_literal_and_modifiable_array(){

   char * this_is_a_string_literal_and_cannot_be_modified = "asdf";
   char this_is_a_char_array_and_can_be_modified[] = "asdf";

   // this_is_a_string_literal_and_cannot_be_modified[0] = 'b'; // segmentation fault
   this_is_a_char_array_and_can_be_modified[0] = 'b';

   printf(" string literal: %s\n", this_is_a_string_literal_and_cannot_be_modified);
   printf(" char array: %s\n", this_is_a_char_array_and_can_be_modified);

}

void strtok_not_working()
{

   char str[] = "asdf=1=2=3"; // this works
   printf("type:  %s\n", typename(str)); // prints 'pointer to char'
   char *token = strtok(str, "=");
   printf("%s\n", token);

   char *str2 = "asdf=1=2=3"; // this wont work
   printf("type:  %s\n", typename(str2)); // prints 'pointer to char'
   printf("%s\n", str2);
   char *token2 = strtok(str2, "="); // segmentation fault
   printf("%s", token2); 

}

void strtok_working()
{

   char str[] = "asdf=1=2=3"; // this works
   // char *str2 = "asdf=1=2=3"; // this wont work

   char *token = strtok(str, "="); // can also call strtok(str, "["); and not use variable deli at all
   printf("%s", token);            // printf("%s", str); will print the same result
}

void pass_char_pointer_to_function(char *s_char_pointer)
{

   char *s_local_string = "asdf";

   s_char_pointer = s_local_string;

   printf("%s\n", s_char_pointer);
}

char *return_a_string(int n_len)
{

   char *s_string = malloc(n_len + 1);
   int i = 0;
   for (i = 0; i < n_len; i++)
   {
      s_string[i] = 'a';
   }
   s_string[i + 1] = '\0';

   return s_string;
}

char *change_the_string(char *s_char_pointer)
{

   s_char_pointer = "asdf";

   return s_char_pointer;
}

void init_a_string()
{

   char s_test_brackets[] = "this is also a literal";
   printf("%s\n", s_test_brackets);

   char *s_test_asteriks = "this is a literal but strtok wont work with it";
   printf("%s\n", s_test_asteriks);

   int len = 5;
   char *s_pointer = malloc(len + 1);
   int i = 0;
   for (i = 0; i < len; i++)
   {
      s_pointer[i] = 65 + i;
   }
   s_pointer[i + 1] = '\0';

   printf("%s\n", s_pointer);

   s_pointer[0] = 'a';
   s_pointer[1] = 'b';
   s_pointer[2] = 'c';
   s_pointer[3] = 'd';
   s_pointer[4] = 'e';
   s_pointer[5] = '\0';
   printf("%s\n", s_pointer);

   int len2 = 5;
   char s_pointer_2[len2 + 1];
   int i2 = 0;
   for (i2 = 0; i2 < len2; i2++)
   {
      //    s_pointer_2[i2] = 65+32+i2; //  error: assignment to ‘char *’ from ‘int’ makes pointer from integer without a cast [-Werror=int-conversion]
      s_pointer_2[i2] = 65 + 32 + i2;
   }
   s_pointer_2[i2 + 1] = '\0';

   printf("%s\n", s_pointer_2);

   s_pointer_2[0] = 'A';
   s_pointer_2[1] = 'b';
   s_pointer_2[2] = 'C';
   s_pointer_2[3] = 'D';
   s_pointer_2[4] = 'E';
   s_pointer_2[5] = '\0';

   printf("%s\n", s_pointer_2);
}

void difference_of_malloc_and_brackets()
{
}
void strings_and_functions()
{

   char *s_mystring = "test";

   // pass_char_pointer_to_function(s_mystring);
   printf("%s \n", s_mystring);

   s_mystring = change_the_string(s_mystring);
   printf("%s \n", s_mystring);

   int n_number_of_chars = 5;

   char *s_string = return_a_string(n_number_of_chars);

   printf("%s \n", s_string);
}
void simple_malloc_and_realloc_tutorialspoint()
{
   char *str;

   /* Initial memory allocation */
   str = (char *)malloc(15);
   strcpy(str, "tutorialspoint");
   printf("String = %s,  Address = %p\n", str, str);

   /* Reallocating memory */
   str = (char *)realloc(str, 25);
   strcat(str, ".com");
   printf("String = %s,  Address = %p\n", str, str);

   free(str);
}
void simple_malloc_and_realloc()
{

   // char * s_string;
   // s_string = (char*)malloc(3);
   // s_string = "hi";

   // s_string = (char *)realloc(s_string, 5);
   // // s_string = "hi ho";

   // printf("%s \n", s_string);

   // free(s_string);

   char *str;

   /* Initial memory allocation */
   str = (char *)malloc(3);
   strcpy(str, "hi");
   // str = "hi";

   printf("%s, \n", typename(str));

   /* Reallocating memory */
   // str = (char *) realloc(str, 5);
   //  strcpy(str, "hi ho");
   // str = "hi ho";

   free(str);

   // return(0);
}
void wtf()
{

   char *str_strcpy;
   str_strcpy = (char *)malloc(3);
   strcpy(str_strcpy, "hi");
   printf("%s\n", str_strcpy);
   printf("%s, \n", typename(str_strcpy));
   free(str_strcpy);

   char *str_equal;
   str_equal = (char *)malloc(3);
   str_equal = "hi";
   printf("%s\n", str_equal);
   printf("%s, \n", typename(str_equal));

   free(str_equal);
}

void wtf2()
{

   char *str1;
   str1 = (char *)malloc(3);
   strcpy(str1, "hi");
   printf("%s\n", str1);

   str1 = realloc(str1, 5);
   strcpy(str1, "hi ho");
   printf("%s\n", str1);

   char *str2;
   str2 = (char *)malloc(3);
   str2 = "hi"; // not using strcpy
   printf("%s\n", str2);

   str2 = realloc(str2, 5);
   str2 = "hi ho"; // not using strcpy
   printf("%s\n", str2);

   free(str1);
   free(str2);
}
int main()
{

   // wtf();
   // wtf2();

   // dnd(100101001101);

   // init_a_string();
   // simple_malloc_and_realloc();
   // string_by_index();
   // strings_and_functions();

   // strtok_working();
   // strtok_not_working();

   string_literal_and_modifiable_array();
   return 0;
}
