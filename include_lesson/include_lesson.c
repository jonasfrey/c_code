

# include <stdio.h>
// this include <...> searches in the standard locations 
// such as  /usr/include, /usr/local/include

# include "my_file.c"
// include "..." searches in the current folder 


int main() {
   /* my first program in C */
   //printf("main function called");
   
   // n_from_my_file is initialized in my_file.c
   printf("this is the variable from the included file my_file.c, it is called n_from_my_file and its \n value is : %i", n_from_my_file);
   

   // we can also include files at any line in the code
   
   // since we did not yet include the file which defines other_var_five , it wont be available here
   //    
   //    printf("other var %i", other_var_five);
   
   # include "other_var_five.c"
   printf("\n other_var_five: %i", other_var_five);
   


   //does a double include file throw any errors ? 

   # include "i_will_include_superfunction.c"

   // superfunction is now included 
   superfunction();

   // but we include it again
   //    # include "superfunction.c"
   // this will throw error
   // error: redefinition of ‘superfunction’

   
   // can a included file change variables from other includes ? 

   # include "i_will_change_the_variable_other_var_five_to_seven.c"

   // yes !! 

   printf("\n other_var_five : %i", other_var_five);
   


   return 0;

}
