
// c file 
#include <stdio.h>


#include "./../c_helpers/a_array.c"
#include "./../c_helpers/dnd.c"

// try to get an array with pointers to ll strings in the argv 
// without first argument and without stuff beginning with dash '-'
// for example 
// command -a buch note -n igel -f raufen nicht -k -d 
//    convert it into an array with pointers to 
//    [ *buch, *note, *igel, *raufen, *nicht ]

int main(int argc, char **argv) {

   A_array a_indexes_to_arguments_without_dash; 


   array_init(&a_indexes_to_arguments_without_dash, 1); 
   
    for (int n_i = 0; n_i < argc; ++n_i){

      printf("\n printf argv n_i %%c %c", argv[n_i][0]);

      char s_first_letter_of_string = argv[n_i][0]; 
      
      if(
         n_i == 0 
         ||
         s_first_letter_of_string == '-'
         ){
         continue;
      }
      
      array_push(&a_indexes_to_arguments_without_dash, n_i);

      dnds("now");
      // printf("\n printf argv n_i %%s %s", argv[n_i][0]);
    
    }



   for(int n_i = 0; n_i <= a_indexes_to_arguments_without_dash.length; n_i++){
      printf("\n string: %%s %s", argv[a_indexes_to_arguments_without_dash.array[n_i]]);
   }
   
   return 0;
}