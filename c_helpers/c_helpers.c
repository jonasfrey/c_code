
// c file 
#include <stdio.h>
#include <string.h>


#include <time.h>
#include <errno.h>    


// struct timespec {
//     time_t tv_sec;        /* seconds */
//     long   tv_nsec;       /* nanoseconds */
// };

/* nanosleep(): Sleep for the requested number of nanosc. */
int nano_sleep(long n_nano_seconds)
{
    struct timespec ts;
    int res;

    if (n_nano_seconds < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = n_nano_seconds / 1000000000;
    ts.tv_nsec = (n_nano_seconds % 1000000000);

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

int micro_sleep(long n_micro_seconds){
   return nano_sleep(n_micro_seconds * 1000);
}
int milli_sleep(long n_milli_seconds){
   return micro_sleep(n_milli_seconds * 1000);
}
struct variable {
   char  *name;
   char  *value;
   char  *type;
};


int main() {
   /* my first program in C */
   printf("main function called");
   
   return 0;
}


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

// #define dd(var)\\"
   
//    struct variable o_var;\\"
   
//    char s_typename = typename(o_var); \\"

//    if(\\"
//       strstr(s_typename, "int")\\"
//       ||\\"
//       strstr(s_typename, "float")\\"
//       ){\\"
//          int length = snprintf( NULL, 0, "%d", var );\\"
//          char* str = malloc( length + 1 );\\"
//          snprintf( str, length + 1, "%d", var );\\"
//          char s_str_var_value[] = str; \\"
//          free(str);\\"
//    }else{\\"
//       char s_str_var_value[] = var; \\"
//    }\\"
   

//    strcpy(o_var.name, #var);\\"
   
//    strcpy(o_var.value, s_str_var_value);\\"

//    strcpy(o_var.type, typename(var));\\"

//    //printf("\\"n %s", struct_to_json(o_var));
//    printf("\\"n %s", o_var.name);\\"
//    printf("\\"n %s", o_var.value);\\"
//    printf("\n %s", o_var.type);

// // void dd(){
// //    _dd();
// // }
