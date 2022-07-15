
// c file 
#include <stdio.h>
#include <stdlib.h>
#include "./../c_helpers/dnd.c"



#define f_s_typename(x) _Generic((x),                                                 \
      _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
   short int: "short int",         unsigned short int: "unsigned short int",     \
         int: "int",                     unsigned int: "unsigned int",           \
   long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
      float: "float",                         double: "double",                 \
long double: "long double",                   char *: "pointer to char",        \
      void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")
      
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

void f_array_length(){
   // so in c a array does not know how big it is / how many elements 
   // it contains 
   // it is the task of the programmer to keep track of the length 
   // thats why we often have to pass the length to a function
   int n_length_a_s_char = 1;
   char * a_s_char = malloc(n_length_a_s_char);

   a_s_char[0] = 'a'; 
   printf("string is %s\n", a_s_char);

   // if we would access the memory 
   // in an area that we didnt 'reserve' with malloc or calloc
   // it is undefined behaviour !!! 
   printf("whats this?: %c\n", a_s_char[33]);

   // this may work but it can also cause segmentation fault 
   for(int n_i = 0; n_i < 100000; n_i++){
      printf("accessing memory which was not allocated at [-%i]: %i\n", n_i,a_s_char[-n_i]);
   }

}
void f_print_array(char * a_s_char,int n_length_a_char){
   for(int n_i = 0; n_i < n_length_a_char; n_i++){
      char s_char = a_s_char[n_i];
      printf("a_s_char[%i](index:%p): %c(as char) %i(as int)\n",n_i, &(a_s_char[n_i]), s_char, s_char);
   }
}
void f_print_every_char(char * a_s_char){
   int n_i = 0;
   int s_char;
#define f_s_typename(x) _Generic((x),                                                 \
      _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
   short int: "short int",         unsigned short int: "unsigned short int",     \
         int: "int",                     unsigned int: "unsigned int",           \
   long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
      float: "float",                         double: "double",                 \
long double: "long double",                   char *: "pointer to char",        \
      void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")
      
   while(s_char){
      s_char = a_s_char[n_i];
      printf("%c", s_char);
      n_i+=1;
   }
   //done
}
void f_array_length2(){
   // so now how do we know that an array is finished?
   // by having the length stored in a variable
   int n_capacity_a_s_char = 20;
   char * a_s_char = malloc(n_capacity_a_s_char);

   a_s_char[0] = '!';
   a_s_char[1] = 'h';
   a_s_char[2] = 'a';
   a_s_char[3] = 'l';
   a_s_char[4] = 'l';
   a_s_char[5] = 'o';
   a_s_char[6] = ' ';
   a_s_char[7] = 'd';
   a_s_char[8] = 'u';
   a_s_char[9] = ' ';
   a_s_char[10] = 'd';
   a_s_char[11] = 'a';
   
   int n_length_a_s_char = 12;

   f_print_array(a_s_char, n_length_a_s_char);

   // now the printf function 
   // with the %s (string) is nothing more than 
   // print every char in the array 
   // as long as it is not 0 / null 
   printf("a_s_char printed as s: %s\n", a_s_char);
   f_print_every_char(a_s_char);
   printf("\n");

   a_s_char[18] = ':';
   a_s_char[19] = '>';

   printf("a_s_char printed as s: %s\n", a_s_char);
   f_print_every_char(a_s_char);
   printf("\n");

   a_s_char[12] = ' ';
   a_s_char[13] = ' ';
   a_s_char[14] = ' ';
   a_s_char[15] = ' ';
   a_s_char[16] = ' ';
   a_s_char[17] = ' ';

   printf("a_s_char printed as s: %s\n", a_s_char);
   f_print_every_char(a_s_char);
   printf("\n");


}

typedef struct{
   size_t n_capacity; 
   size_t n_length; 
   char * a; 
} A_s_char;
void f_a_s_char_init(
   A_s_char * a_s_char
){
   a_s_char->n_capacity = 1; 
   a_s_char->n_length = 1;
   a_s_char->a = malloc(a_s_char->n_capacity * sizeof(char)); 
   // return &a_s_char;
}
void f_a_s_char_push(
   A_s_char * a_s_char, 
   char s_char
){
   if(a_s_char->a == NULL){
      f_a_s_char_init(a_s_char);
   }
   a_s_char->n_capacity = a_s_char->n_length;
   a_s_char->a = realloc(a_s_char->a, a_s_char->n_length * sizeof(char));
   a_s_char->a[a_s_char->n_length-1] = s_char;
   a_s_char->n_length +=1;
   // if(a_s_char->n_capacity < a_s_char->n_length){
   // }
   // a_s_char->
}
void f_a_s_char_free(
   A_s_char * a_s_char
){
   free(a_s_char->a);
   a_s_char->a = NULL;
   a_s_char->n_capacity = 0;
   a_s_char->n_length = 0;
}
void f_dynamic_array(){
   // A_s_char * a_s_cahr = f_a_s_char_new();
   A_s_char a_s_char;

   f_a_s_char_push(&a_s_char,'h');
   f_a_s_char_push(&a_s_char,'a');
   f_a_s_char_push(&a_s_char,'l');
   f_a_s_char_push(&a_s_char,'l');
   f_a_s_char_push(&a_s_char,'o');
   f_a_s_char_push(&a_s_char,'!');

   // printf("s is %s", a_s_char.a);

   f_print_every_char(a_s_char.a);
   printf("\n");
   printf("type of a_s_char.a is :%s\n", f_s_typename(a_s_char.a));

   printf("a_s_char.a[0] %i\n", a_s_char.a[0]);
   printf("a_s_char.a[1] %i\n", a_s_char.a[1]);
   printf("a_s_char.a[2] %i\n", a_s_char.a[2]);
   printf("a_s_char.a[3] %i\n", a_s_char.a[3]);

}

int main() {
   
   // array_of_strings();

   // array_of_strings_dynamic();

   // f_array_length();
   
   // f_array_length2();

   f_dynamic_array();
   return 0;
}


