
// c file 
#include <stdio.h>

// 
// to define constants we can use 

// #define NAME value 
//         NAME is also called macro 
// 
// NAME will be replaced with value by preprocessor (not compiler) 
// you can have a look at the preprocessed file by 
// using gcc -E input_file.c > outputfile.c

#define TAU 6.282
// can a #define depend on a previous #define ?
#define PI TAU / 2


// we can use NAME also as macros 

#define add(x, y) x+y

// we even can use new line with the backslash '\' character

#define printf_bigger_number(a,b) \
   if(a > b){ \
      printf("\nthe bigger number is a(%i)", a);\
   }else{\
      printf("\nthe bigger number is b(%i)", b);\
   }\
// const keyword  


// some standard macros are: 
//    __DATE__
//    __TIME__


// the #var directive can be used as value and evaluates the passed variable to its variable name 

#define dump_string(var) \
   printf("\n var_name is : %s", #var); \
   printf("\n value is    : %s", var); \

int main() {
   /* my first program in C */
   printf("main function called");
   
   printf("\nvalue of '#define TAU l6.282': %f", TAU);

   printf("\nvalue of '#define PI TAU / 2': %f", PI);

   printf("\n the sum of 2(x) and 5(y) is %i", add(2, 5));

   // does it still work if we make some whitespace mistake ? 

   printf("\n again, the sum of 2(x) and 5(y) is %i", add( 2,    5));

   printf_bigger_number(12,20);


   printf("\nthe value of the standard macro __DATE__ : %s", __DATE__);
   printf("\nthe value of the standard macro __TIME__ : %s", __TIME__);


   char animal[5] = "dogg!";

   dump_string(animal); 

   printf("\n wtf : %s", (animal)); 


   char animal_two[] = "firefish";

   dump_string(animal_two); 

   return 0;
}
