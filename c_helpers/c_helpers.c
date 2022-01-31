
// c file 
#include <stdio.h>
#include <string.h>


#include <time.h>
#include <errno.h>    

#include "./int_to_string.c"


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


void int_to_string_test(){
   int i; 
   char * str; 
   i = 12341234; 
   str = int_to_string(i); 
   printf("%s\n", str);

   i = 117300; 
   str = int_to_string(i); 
   printf("%s\n", str);

   str = int_to_string(8446744073709551616Lu); 
   printf("%s\n", str);

   str = int_to_string(-8446744073709551616L); 
   printf("%s\n", str);
   
   long long n_i = 2;
   int n_exponent = 1;
   
   while(n_i < powl(2, 62)){
      n_exponent++;

      n_i = n_i*2;
      str = int_to_string(n_i); 
      printf("%25s: 2^%2i : %2i bit \n", str, n_exponent, n_exponent+1);
      // printf("%li\n", i);
   }
}
int main() {
   /* my first program in C */
   int_to_string_test();

   return 0;
}



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
