
// c file 
#include <stdio.h>
#include <stdlib.h>
#include "./../c_helpers/dnd.c"


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

   printf("\nthe stringlength is %i", len);

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


void simple_arrays(){

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


   int a_nums[10];

   //    printf("\n printf %%d, a_nums: %d", a_nums); // error: error: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘int *’ 
   printf("\n printf %%p, a_nums: %p", a_nums);

   //    printf("\n printf %%d, &a_nums: %d", &a_nums); // error: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘int (*)[10]’
   printf("\n printf %%d, &a_nums: %p", &a_nums);

   for(int i = 0; i < 10; i++){
      printf("\nprintf %%d, a_nums[i]: %d", a_nums[i]);
   }

   //    int a_nums_pointer = (int)&a_nums; //error: cast from pointer to integer of different size
   long a_nums_pointer = (long)&a_nums; 
   printf("\n printf %%li, a_nums_pointer (&a_nums), %li", a_nums_pointer);

   // printf("\n printf %%d, ")
   calc_string_length_outside_of_scope("test");
   

}


void array_of_strings(){

   int n_items = 4; 
   int n_bytes_to_reserve = n_items * sizeof(char *);

   char ** a_array = malloc(n_bytes_to_reserve); // 3 * 8 = 24

   a_array[0] = "a. 123 so this can be as long as i want, really ? really really ? really really ? really really ? really really ? really really ? really really ? really really ? really really ? really really ? ";
   a_array[1] = "b. 123";
   a_array[2] = "c. 123";
   // a_array[4] = "fourht"; // ? segmentation fault (core dumped)
   // a_array[5] = "fifth";

   // a_array[3] = "asdf";

   // dnds(a_array[0]);
   // dnds(a_array[1]);

   dnds("pointer to start of array");
   dnd(&a_array);

   dnds("pointer to first element in array? ");
   dnd(&a_array[0]);
   
   dnds("first value of first element in array,(formatted as int)");
   dnd(*a_array[0]);
   
   dnds("first value of first element in array,(formatted as char)");
   dndc(*a_array[0]);
   
   dnds("first value of first element in array,(formatted as string)");
   dnds(a_array[0]);
   
   dnd(&a_array[0]);

    int i = 0 ;
    while(a_array[i] != NULL){
       dnd(&a_array[i]);
       dnds(a_array[i]);
       i++;
    }

   // dnd(sizeof(char *)); // is 8

}


void array_of_strings_dynamic(){

   char ** a_array = malloc(3 * sizeof(char*));
   dnds(a_array[0]);
   dnds(a_array[1]);
   dnds(a_array[2]);
   int i = 0 ;
   while(a_array[i] != NULL){
       dnd(&a_array[i]);
       dnds(a_array[i]);
       i++;
   }
   // dnds(a_array[3]); // segmentation fault
}

void simple_malloc(){
   char ** a_array = malloc(3 * sizeof(char*));
   dnds(a_array[0]);
   dnds(a_array[1]);
   dnds(a_array[2]);
   // dnds(a_array[3]); // segmentation fault
}

int main() {
   
   // array_of_strings();

   array_of_strings_dynamic();

   return 0;
}


