
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f_append_string_to_array(
   char ** a_s_string, 
   char * s_string,
   int * n_length_a_s_string, 
   int n_length_max_s_string
){

    *n_length_a_s_string = *n_length_a_s_string+1;
    a_s_string = realloc(a_s_string, *n_length_a_s_string * sizeof(char*));
    a_s_string[*n_length_a_s_string-1] = malloc(n_length_max_s_string * sizeof(char));
    strcpy(a_s_string[*n_length_a_s_string-1], s_string);


}
void f_with_append(){
   int n_length_menu_options = 0;
   int n_length_max_menu_option_name = 10;
   char ** a_s_menu_option_name = malloc(1);

   f_append_string_to_array(
      a_s_menu_option_name, 
      "hellow you", 
      &n_length_menu_options,
      n_length_max_menu_option_name
   );


   char * s_my_str = "my str";
   f_append_string_to_array(
      a_s_menu_option_name, 
      s_my_str, 
      &n_length_menu_options,
      n_length_max_menu_option_name
   );

   for(int n_i = 0; n_i < n_length_menu_options; n_i++){
      printf("a_s_menu_option_name[%i]:%s\n", n_i, a_s_menu_option_name[n_i]);
   }

}
void f_simple(){
   int n_length_menu_options = 0;
   int n_length_max_menu_option_name = 10;
   char ** a_s_menu_option_name;
    a_s_menu_option_name = malloc(1 * sizeof(char*));
    n_length_menu_options++;
    a_s_menu_option_name = realloc(a_s_menu_option_name, n_length_menu_options * sizeof(char*));
    a_s_menu_option_name[n_length_menu_options-1] = malloc(n_length_max_menu_option_name * sizeof(char));
    char * s_menu_option_name_backlight  =  "lcd backlight:"; 
    strcpy(a_s_menu_option_name[n_length_menu_options-1], s_menu_option_name_backlight);

    printf("a_s_menu_option_name[0]:%s", a_s_menu_option_name[0]);
}
int main() {
   // f_simple();
   f_with_append();
}
