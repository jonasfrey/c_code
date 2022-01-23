
// c file 
#include <stdio.h>


#include "./../c_helpers/a_array.c"
#include "./../c_helpers/dnd.c"

#include <string.h>


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

// try to get an array with pointers to ll strings in the argv 
// without first argument and without stuff beginning with dash '-'
// for example 
// command -a buch note -n igel -f raufen nicht -k -d 
//    convert it into an array with pointers to 
//    [ *buch, *note, *igel, *raufen, *nicht ]

int main(int argc, char **argv) {

   int n_max_argument_length = 0; 
   int n_number_of_arguments = 0;
   int n_current_argument_length = 0;

   int n_i = 0; 
   for (n_i = 0; n_i < argc; ++n_i){

      //printf("\n printf argv n_i %%c %c", argv[n_i][0]);

      char s_first_letter_of_string = argv[n_i][0]; 
      
      if(
         n_i == 0 
         ||
         s_first_letter_of_string == '-'
         ){
         continue;
      }
      
      n_number_of_arguments++;

      n_current_argument_length = strlen(argv[n_i]);
      
      if(n_current_argument_length > n_max_argument_length){
         n_max_argument_length = n_current_argument_length;
      }

      dnds("now");
      // printf("\n printf argv n_i %%s %s", argv[n_i][0]);
    
    }

   dnd(n_number_of_arguments);

   char a_filtered_arguments[n_number_of_arguments][n_max_argument_length];

   int n_argument_intex = 0;

   for (n_i = 0; n_i < argc; ++n_i){

      //printf("\n printf argv n_i %%c %c", argv[n_i][0]);

      char s_first_letter_of_string = argv[n_i][0]; 
      
      if(
         n_i == 0 
         ||
         s_first_letter_of_string == '-'
         ){
         continue;
      }
      
      printf("%s", argv[n_i]);

      strcpy(a_filtered_arguments[n_argument_intex], argv[n_i]);
    
      n_argument_intex++;

    }

   for(int n_i = 0; n_i < n_number_of_arguments; n_i++){
      printf("\n string: %%s %s", a_filtered_arguments[n_i]);
   }


   
   return 0;
}