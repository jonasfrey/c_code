
// c file 
#include <stdio.h>

void print_with_newline_prefix(char s_text[]){

   //note we can 'concatenate' a string by separating with simple spaces 
   // like this 
   // "string start" variable_or_const "string end"
   printf("\n" "");
}
void calc_string_length_outside_of_scope_not_possible(char s_text[]){
   //here we cannot use 

   //    int n_text_length = sizeof(s_text) / sizeof(s_text[0]); 
   // :( to bad
}

void a_bad_workaround(char s_text[], int n_text_length){
   //we have to pass the text length as argument to have access
   // no one wants to always pass the string length wtf is this workaround 
}

void calc_string_length_outside_of_scope(char s_text[]){

   // luckly there is the string.h and strlen function
   #include <string.h>
   int len = strlen(s_text);

   printf("the stringlength is %i", len);

}

void why_the_fuck_doesnt_this_work(char s_text[]){

   int num = 177;
   printf("%c", num);
   printf("%s",s_text);
   printf("%c", num);
   // char ch = "▒"; 
   //char ch = '▒';
   char chars[] = "▒"; 
   char ch = chars[0]; 
   printf("\n The ascii value of the ch variable is : %d", ch);
   //this wont print "▒" 
   printf("%c", ch);
   // but this will print "▒"
   printf("%s", chars);

}

int main() {
   
   // arrays are defined as follows 

   // type arrayName [ arraySize ];
   
   int a_natural_numbers [10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

   // to print the array we have to loop over it
   // to do so we have to find out the length of it 

   // the sized of the complete array in bytes
   int a_natural_numbers_size_in_bytes = sizeof(a_natural_numbers);

   // the size of any element of the array in bytes

   int a_natural_numbers_first_element_in_bytes = sizeof(a_natural_numbers[0]); 

   // now to get the numbers of elements / the length of the array 
   // we have to devide the whole size / the size of a single element 

   int a_natural_numbers_length = a_natural_numbers_size_in_bytes / a_natural_numbers_first_element_in_bytes; 

   // since c has no var_dump or console.log or print() or Console.WriteLine
   // we have to loop over the array to print every item 
   for(int i = 0; i < a_natural_numbers_length; i++){
      printf("\n index: %i ", i); 
      printf("\n value: %i", i);
   }
   

   // strings 
   // since a string is noting more than an array of chars we can create strings like so 

   char s_this_is_a_string [16] = "this is a string";

   printf("\nstring is: %s", s_this_is_a_string);

   printf("\nstring[8] is: %c", s_this_is_a_string[8]);

   // dynamic sized array ??? 

   // we cant even initialize an array with the size as a variable !, wtf 

   //    int n_array_size = 10; 
   //    int n_nat_nums [n_array_size] = {1,2,3,4,5,6,7,8,9,0}; 


   
   calc_string_length_outside_of_scope("test");
   
   return 0;


}


