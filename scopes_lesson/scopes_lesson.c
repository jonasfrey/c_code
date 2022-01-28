
// c file 
#include <stdio.h>
#include <string.h>


const char * i_will_modify_the_string(char * s_param){


   for(int i = strlen(s_param); i >= 0; i++){
      s_param[i] = 65 + (i%2==0) * 32; // AaAaAa...
   }

   return s_param;
}

char * i_dont_do_anything_to_the_string(char * s_param){
   
   printf("\n%li", strlen(s_param));

   printf("\n%li", s_param);// s_param is the index/pointer/address
   printf("\n%c", s_param[0]); // s_param[0] is the value 
   printf("\n%li", &s_param[0]); // &s_param[0] is the index/pointer/address of the first value
   printf("\n%li", &s_param[1]); // &s_param[1] is the index/pointer/address of the second value
   printf("\n%li", &s_param[2]); // &s_param[2] is the index/pointer/address of the thrid value
   printf("\n%li", &s_param[3]); // &s_param[3] is the index/pointer/address of the fourth value

   return (char *)s_param;

   // return (char *)"asdf";
}

int main() {
   /* my first program in C */
   printf("main function called");
   
   char *im_a_string = "asdfasdf"; 

   printf("\n%s",  im_a_string);
   im_a_string = (i_dont_do_anything_to_the_string(im_a_string));
   // im_a_string = (i_will_modify_the_string(im_a_string));
   printf("\n%s",  im_a_string);

   return 0;
}
