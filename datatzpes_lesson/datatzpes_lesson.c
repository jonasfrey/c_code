
// c file 
#include <stdio.h>

int main() {
   /* my first program in C */
   printf("main function called");
   
   //cast to int 
   // does it get rounded  up or down?
   printf("\n(int) 1.2: %i", (int) 1.2); // round down to 1?
   printf("\n(int) 1.8:  %i", (int) 1.8); // round up to 2?
   // no always rounded down 


   //cast to float 
   // does it get rounded  up?
   printf("\n(float) 1.2123468: %f", (float) 1.2123468);
   //                       ^   gets rounded up to 7 
   printf("\n(float) 1.2123463: %f", (float) 1.2123463);
   //                       ^   gets rounded down to 6 

   printf("\n(float) 1.2123465: %f", (float) 1.2123465);
   //                       ^   gets rounded down to 7 
   //yes!

   // a simple string ? 
   

   // well we forgot the null terminator !!!
   char s_string_without_null_terminator[5];
   s_string_without_null_terminator[0]='h';
   s_string_without_null_terminator[1]='e';
   s_string_without_null_terminator[2]='l';
   s_string_without_null_terminator[3]='l';
   s_string_without_null_terminator[4]='o';

   // well we forgot the null terminator !!!
   printf("\nstring wihtout null terminator is looking weird, isnt it?  : %s", s_string_without_null_terminator);

   printf("\nchar at str[0] %c", s_string_without_null_terminator[0]);
   printf("\nchar at str[1] %c", s_string_without_null_terminator[1]);
   printf("\nchar at str[2] %c", s_string_without_null_terminator[2]);
   printf("\nchar at str[3] %c", s_string_without_null_terminator[3]);
   printf("\nchar at str[4] %c", s_string_without_null_terminator[4]);
   printf("\nchar at str[5] %c", s_string_without_null_terminator[5]);
   printf("\nchar at str[6] %c", s_string_without_null_terminator[6]);
   
   printf("\n ? is char at (str[5] == '\\0') result: %i", s_string_without_null_terminator[5] == '\0');


   char s_string[5+1];
   s_string[0]='h';
   s_string[1]='e';
   s_string[2]='l';
   s_string[3]='l';
   s_string[4]='o';
   // s_string[5]= NULL; // not working , why? 
   s_string[5]= '\0';
   
   printf("\nstring wiht null terminator is looking fully ok , right?  : %s", s_string);
   

   printf("\nchar at str[0] %c", s_string[0]);
   printf("\nchar at str[1] %c", s_string[1]);
   printf("\nchar at str[2] %c", s_string[2]);
   printf("\nchar at str[3] %c", s_string[3]);
   printf("\nchar at str[4] %c", s_string[4]);
   printf("\nchar at str[5] %c", s_string[5]);
   printf("\nchar at str[6] %c", s_string[6]);

   printf("\n ? is char at (str[5] == '\\0') result: %i", s_string[5] == '\0');

   printf("\n(float) 1.8:  %f", (float) 1.8);

   return 0;

}
