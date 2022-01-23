// c file 
#include <stdio.h>


char f_s_ascii_char_to_upper(char s_char){
   int n_char = s_char;
   n_char = ((n_char-65) % 32)+65; // ascii A is number 65 // ascii 'a' is 97 = 65+32
   printf("%i",n_char); 

   return (char) n_char;
}

char f_s_ascii_char_to_lower(char s_char){
   int n_char = s_char; 
   n_char = (((n_char-65) % 32) +65)+32; // ascii A is number 65 // ascii 'a' is 97 = 65+32
   return (char) n_char;
}

void test_f_s_ascii_char(){
   printf("f to F: %c", f_s_ascii_char_to_upper('f'));
   printf("A to A: %c", f_s_ascii_char_to_upper('A'));
   printf("F to f: %c", f_s_ascii_char_to_upper('F'));
   printf("a to a: %c", f_s_ascii_char_to_upper('a'));
}

int f_b_did_i_pass_the_module(
   int b_deadline_missed, 
   int b_second_chance_requested,
   int b_second_chance_already_used
   ){

   int b_module_passed; 
   int b_second_chance_can_be_requested; 

   if(b_deadline_missed){

      if(b_second_chance_already_used){
         b_second_chance_can_be_requested = 0;
         b_module_passed = 0;
         printf("you really fucked up, you better try at another university...");
      }

      if(
         b_second_chance_can_be_requested 
         &&
         b_second_chance_requested
         ){
         
         if(b_second_chance_already_used == 0){
            printf("extension of deadline by 1 week!");
         }
      }
      else{
         printf("please request a second chance!");
      }
   }

   if(!b_deadline_missed){
      b_module_passed = 1; 
   }
   
   return b_module_passed; 

}
 

int main() {
   /* my first program in C */
   //test_f_s_ascii_char();


   int b_deadline_missed;
   int b_second_chance_requested;
   int b_second_chance_already_used;

   int b_module_passed = 0;

   int s_input_char;
   printf( "Did you miss the deadline? (y/n):");
   s_input_char = getchar( );
   b_deadline_missed = f_s_ascii_char_to_lower(s_input_char == 'y'); 

   printf( "Did request a second chance within 24 hours of the deadline? (y/n):");
   s_input_char = getchar( );
   b_second_chance_requested = f_s_ascii_char_to_lower(s_input_char == 'y');

   printf( "Did you already requested a second chance once? (y/n):");
   s_input_char = getchar( );
   b_second_chance_already_used = f_s_ascii_char_to_lower(s_input_char == 'y');

   b_module_passed = f_b_did_i_pass_the_module(
         b_deadline_missed, 
         b_second_chance_requested,
         b_second_chance_already_used
   );

   if(b_module_passed){
      printf("congrats! you passed the module");
   }

   return 0;

}
