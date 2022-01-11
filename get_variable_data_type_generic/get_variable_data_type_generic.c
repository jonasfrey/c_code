#include <stdio.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>


#define typename(x) _Generic((x),        /* Get the name of a type */             \
                                                                                  \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                   char *: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")

int main()
{
    int n_int = 20;
    float n_float = 2.2231234;
    char s_string[] = "asdf"; 
    printf("\nn_int %i", n_int);
    printf("\nn_float %f", n_float);
    printf("\ns_string %s", s_string);
    
    char s_n_int[] = typename(n_int);
    char s_n_float[] = typename(n_float);
    char s_s_string[] = typename(s_string);

    printf("\ns_n_int %s", s_n_int);
    printf("\ns_n_float %s", s_n_float);
    printf("\ns_s_string %s", s_s_string);

    return 0;
}

