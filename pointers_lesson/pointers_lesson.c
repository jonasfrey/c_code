
// c file 
#include <stdio.h>

#include <string.h>
#include "./../c_helpers/dnd.c"
#include "./../c_helpers/typename.c"

void give_me_a_string(char* test){ 

   //    printf("\nyou gave me the string: %s", test); // error: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’ 
   printf("\nyou gave me the string: %s", test); // error: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’ 
}

void give_me_a_int(int test){
   printf("\nyou gave me the int: %i", test); 
}

void passing_to_function(){
/* my first program in C */
   printf("\nmain function called");

   // why can we pass ints? 
   int n_num = 1234;   
   give_me_a_int(n_num); 


   // but not strings 
   char* s_string = "asdf";
   
   printf("\n%%p pointer as hex: %p", s_string);
   printf("\n(int) %%li: pointer %li", (long) s_string);

   give_me_a_string(s_string);

 
}

void what_are_pointers(){

   // imagine there is a HUUUUUUGE Array called RAM 
   // every integer is 8 bit 
   // [
   //    ...
   //    0100'1010, 
   //    0100'1111, 
   //    0100'0101, 
   //    0100'1000, 
   //    1111'1100, 
   //    1100'1110
   //    ...
   // ]
   // now if you want to get a value you would 
   /// my_value = RAM[index_of_the_value]
   //  
   // index_of_the_value is the pointer / address, it is just a simple number!!!!!!
   // 
   // when you would like to store such a value you would 
   // RAM[index_i_want_to_store] = my_value
   //

   // so we can access the ram array by using the star * 
   // RAM[my_index] <=> *my_index
   // 
   // to access the index of a variable we can use &
   // RAM.indexOf(my_value) <=> &my_value
   // 

   // a so called pointer is only a variable containing an index !
   
   // int n_num = 1234; 
   // // n_num is 
   // printf("\n%i", n_num);
   // printf("\n%p", &n_num);
   // printf("\n%li", (long)&n_num); // hexadecimal to decimal 

   // // if we now increse the index 
   // // (&n_num)++; // not working 
   // // (&n_num)+=1; // not working

   // long n_num_index_in_ram = (long) &n_num;
   // // n_num_index_in_ram =(long) &n_num;
   // printf("\n%li", n_num_index_in_ram); // hexadecimal to decimal 
   
   // n_num_index_in_ram++;
   // printf("\n%li", n_num_index_in_ram); // hexadecimal to decimal 

   // n_num = (long) n_num;
   // n_num = (*n_num_index_in_ram);
   // // (&n_num)+=(long) 1;

   // // we should get a completly different value
   // printf("\n%i", n_num);
   // printf("\n%p", &n_num); 
   // printf("\n%li", (long)&n_num); // hexadecimal to decimal 
   

}

// void why_is_this_not_working(){
//    long num = 10;
//    &(num)++;
//    printf("%li", num);
// }

void why_is_this_not_working(){

   long num = 10; 
   long num_address = (long) &num; 
   num_address++; 

   long value_at_num_adress = *((int*)num_address);

   printf("\n%li", value_at_num_adress);

   num_address--;

   value_at_num_adress = *(int*)num_address;

   printf("\n%li", value_at_num_adress);

   // output of the programm above:
   // 0
   // 10
   
}

void are_bytes_in_ram_grouped(){

   long num = 255; // 0000'0000 0000'0000 0000'0011 1111'1111

   long num_address = (long) &num;

   num_address++;

   long value_at_num_adress = *((int*)num_address);

   printf("\n%li", value_at_num_adress);

   num_address--;

   value_at_num_adress = *(int*)num_address;

   printf("\n%li", value_at_num_adress);
   
}


int plus_one(int n_num){
   return n_num+1;
}


int i_increase_the_int_by_one(int * n_int_pointer){
   // int n_num =  *n_int_pointer+1;
   // return n_num;
   *n_int_pointer+=1;
   return *n_int_pointer;
}

int i_increase_the_int_by_one_in_my_scope(int n_num){
   n_num+=1;
   return n_num;
}

void pass_int_pointer_to_function(){
// this function shows, that you can increase the value of an integer
// by passing the pointer of the integer to a function
   int n_num = 1234; 
   printf("\n n_num %i", n_num);

   //this wont increase the number , since the pointer is different in the other scope
   i_increase_the_int_by_one_in_my_scope(n_num);
   printf("\n n_num %i", n_num);

   // this will increase the number, since the real value is read out the ram 
   // RAM[n_int_pointer] += 1
   i_increase_the_int_by_one(&n_num);
   printf("\n n_num %i", n_num);

   int asdf = 1234; 



}


void print_the_pointer_by_pointer(int * n_num_pointer){
   printf(" \n scope: print_the_pointer_by_pointer()");
   // printf(" \n pointer as hexadec: %*p",20, ); // not working ... i start to hate c 
   printf(" \n pointer as hexadec: %*lx",20, (long) n_num_pointer);
   printf(" \n pointer as decimal: %*li",20, (long) n_num_pointer);

}
void print_the_pointer(int n_num){ 

   printf(" \n scope: print_the_pointer()");
   // printf(" \n pointer as hexadec: %*p",20, ); // not working ... i start to hate c 
   printf(" \n pointer as hexadec: %*lx",20, (long) &n_num);
   printf(" \n pointer as decimal: %*li",20, (long) &n_num);

}
void simple_int_pointer(){
// this function shows how the pointer of an integer
// changes in a different scope/function

   int n_num = 1234; 

   // what is the pointer in a different scope / function
   printf("\n scope: simple_int_pointer()");
   // printf(" \n pointer as hexadec: %*p",20, ); // not working ... i start to hate c 
   printf(" \n pointer as hexadec: %*lx",20, (long) &n_num);
   printf(" \n pointer as decimal: %*li",20, (long) &n_num);

   print_the_pointer(n_num);


   printf("\n scope: simple_int_pointer()");
   // printf(" \n pointer as hexadec: %*p",20, ); // not working ... i start to hate c 
   printf(" \n pointer as hexadec: %*lx",20, (long) &n_num);
   printf(" \n pointer as decimal: %*li",20, (long) &n_num);

   print_the_pointer(n_num);

   // now if we pass the pointer to a function it stays the same


   printf("\n scope: simple_int_pointer()");
   // printf(" \n pointer as hexadec: %*p",20, ); // not working ... i start to hate c 
   printf(" \n pointer as hexadec: %*lx",20, (long) &n_num);
   printf(" \n pointer as decimal: %*li",20, (long) &n_num);

   print_the_pointer_by_pointer(&n_num);
}

void printf_of_a_pointer(){
// this function shows that you need %p 
// to format a pointer, although it is only a fcking number
// why the fuck couldnt one simply use %i or %li

   int n_num = 1234; 
   printf("\n value n_num is: %i", n_num);
   
   // note we cannot simply use %i, &n_num, since a pointer is a datatype of its own!!!
   //    printf("\n pointer &n_num is: %i", &n_num); // not working pointer needs %p

   printf("\n pointer &n_num is: %p", &n_num);


   printf("\n  (long) &n_num is: %li", (long) &n_num);
}

void f_read_out_a_byte(){
   int n_number = 0b11111111000000001111000000001111;
   //               ^&+0    ^&+1    ^&+2   ^&+3    // the real address with real sum 
   //               ^1000   1001    1002   1003    // the real address with real sum 

   int * a_n_number = malloc(4);

   *a_n_number = n_number;

   long n_adress_of_a_n_number = &a_n_number;

   long n_adress_of_second_byte = n_adress_of_a_n_number+1;
   long n_adress_of_third_byte = n_adress_of_a_n_number+2;
   long n_adress_of_fourth_byte = n_adress_of_a_n_number+3;

   printf("the number %u\n", *a_n_number); // %u for unsigned int !

   printf("adress n_adress_of_second_byte %li\n", (char *) n_adress_of_second_byte); //we have to convert the long to a char pointer
   printf("adress n_adress_of_third_byte %li\n", (char *) n_adress_of_third_byte); //we have to convert the long to a char pointer
   printf("adress n_adress_of_fourth_byte %li\n", (char *) n_adress_of_fourth_byte); //we have to convert the long to a char pointer

   printf("value n_adress_of_second_byte %u\n", *(char *) n_adress_of_second_byte); //we have to convert the long to a char pointer
   printf("value n_adress_of_third_byte %u\n", *(char *) n_adress_of_third_byte); //we have to convert the long to a char pointer
   printf("value n_adress_of_fourth_byte %u\n", *(char *) n_adress_of_fourth_byte); //we have to convert the long to a char pointer


}

void print_simple_char(char s_c){
   printf("\n                scope: %*s",20, __func__);
   printf("\n           char value: %*c",20, s_c);
   printf("\n char pointer hexadec: %*lx", 20, (long) &s_c);
   printf("\n char pointer decimal: %*li", 20, (long) &s_c);
}
void print_simple_char_by_pointer(char * s_c_pointer){
   printf("\n                scope: %*s",20, __func__);
   printf("\n           char value: %*c",20, *s_c_pointer);
   printf("\n char pointer hexadec: %*lx", 20, (long) s_c_pointer);
   printf("\n char pointer decimal: %*li", 20, (long) s_c_pointer);
}

void simple_char_pointer(){
// this function shows how a char pointer changes
// when you pass the value of the char to a function
   char s_c = 'X'; 
   printf("\n                scope: %*s",20, __func__);
   printf("\n           char value: %*c",20, s_c);
   printf("\n char pointer hexadec: %*lx", 20, (long) &s_c);
   printf("\n char pointer decimal: %*li", 20, (long) &s_c);

   //pointer value will be different
   print_simple_char(s_c);

   //pointer value will be the same
   print_simple_char_by_pointer(&s_c);

}

char i_will_change_the_char_to_x(char s_char){

   s_char = 'x'; 

   printf("\n                scope: %*s",20, __func__);
   printf("\n           char value: %*c",20, s_char);
   printf("\n char pointer hexadec: %*lx", 20, (long) &s_char);
   printf("\n char pointer decimal: %*li", 20, (long) &s_char);

   return s_char;
}
void change_char_in_function(){
   char s_char = 'A';
   
   printf("\n                scope: %*s",20, __func__);
   printf("\n           char value: %*c",20, s_char);
   printf("\n char pointer hexadec: %*lx", 20, (long) &s_char);
   printf("\n char pointer decimal: %*li", 20, (long) &s_char);

   s_char = i_will_change_the_char_to_x(s_char);
   printf("\n                scope: %*s",20, __func__);
   printf("\n           char value: %*c",20, s_char);
   printf("\n char pointer hexadec: %*lx", 20, (long) &s_char);
   printf("\n char pointer decimal: %*li", 20, (long) &s_char);

}

void simple_string(){
   
   int size_null_terminator = 1;
   
   char * s_string_without_size = "abcd";// we do not need a size

   char s_string_with_size[4+1/*(size_null_terminator)*/] = "abcd"; // we need a size and it cannot be variable

   int len = 10;
   // char s_string[len] = "asdfasdfa";

   printf("\n                  scope: %*s",20, __func__);
   printf("\n           string value: %*s",20, s_string_without_size);
   printf("\n string pointer hexadec: %*lx", 20, (long) &s_string_without_size);
   printf("\n string pointer decimal: %*li", 20, (long) &s_string_without_size);
   
   printf("\n                  scope: %*s",20, __func__);
   printf("\n           string value: %*s",20, s_string_with_size);
   printf("\n string pointer hexadec: %*lx", 20, (long) &s_string_with_size);
   printf("\n string pointer decimal: %*li", 20, (long) &s_string_with_size);

   //replace_all_chars_with_x(s_string_with_size);   
}
void char_info(){

   char chr_a = 65;// ascii A
   char chr_b = 'b';
   char chr_c = chr_a+1+1;

   dndc(chr_a); 
   dndc(chr_b);
   dndc(chr_c);

   printf("char dereferenced value      (%%c var)           :%c\n", chr_a);// we dont have to dereference sincei it already is a char
   printf("char dereferencd value as int(%%i var)           :%i\n", chr_a);// we dont have to dereference sincei it already is a char
   printf("pointer hex                  (%%p var)           :%p\n", &chr_a); 
   printf("pointer dec                  (%%li (long) var)   :%li\n", (long) &chr_a);
   // printf("string value                 (%%s var)           :%s\n", chr_a); //segmentation fault
   printf("typename                     (%%s typename(var)) :%s\n", typename(chr_a));
   // printf("pointer of pointer           (%%p &var)          :%p\n", &&chr_a);  // error: label ‘chr_a’ used but not defined
   // printf("pointer of pointer of pointer(%%p &var)          :%p\n", &&&chr_a); // error: expected identifier before ‘&’ token 
    

}
void string_info(){
   char *s_a = "a. first";
   char *s_b = "b. se" /*very funny*/ "cond";
   char *s_c = "a" ". th"  "ir"  "d";
   
   dnds(s_a);
   dnds(s_b);
   dnds(s_c);

   printf("pointer hex                  (%%p var)           :%p\n", s_a);
   printf("pointer dec                  (%%li (long) var)   :%li\n", (long) s_a);
   printf("string                       (%%s var)           :%s\n", s_a);
   printf("typename                     (%%s typename(var)) :%s\n", typename(s_a));
   printf("char dereferenced value      (%%c *var)          :%c\n", *s_a);
   printf("char pointer value           (%%x var)           :%x\n", s_a);
   printf("pointer of pointer           (%%p &var)          :%p\n", &s_a);


}

void ways_to_init_a_string(){
   
   char *s_a = "asdf";                       // working

   char s_b[5] = "asdf" ;                    // working
   dnds(s_b);
   char s_c[5] = {'a', 's', 'd', 'f', '\0'}; // working 
   dnds(s_c);
   int n_len = 5;
   char s_d[n_len];                            // working

   //       s_d = "asdf";                       // not working
                                                // error: assignment to expression with array type

   strcpy(s_d, "asdf");          // should work, didnttest yet
   
   dnds(s_d);

   //    s_d = {'a', 's', 'd', 'f', '\0'};      // not working
                                                // error: expected expression before ‘{’ token
   int n_len_b = 5;
   //    char s_e[n_len_b] = "asdf";         // not working
                                             // error: variable-sized object may not be initialized


   s_d[0] = 'a';
   s_d[1] = 's';
   s_d[2] = 'd';
   s_d[3] = 'f';
   s_d[4] = '\0';                               // working
}

void dynamically_create_string(){

   // int n_len = 5; 

   // //char s_string[n_len]; 

   // char s_string = malloc(n_len);  // error: expression must be a modifiable lvalue

   // s_string[0] = "a";
   // dnds(s_string);
   // s_string = "asdf"; 


}
void get_value_of_random_address(){

   //    can we get some random value ?
   //    no 
   // dnd(*(int *)123123123); // segmentation fault

   // int a = 11235; 
   // dnd(&a); // that pointer value was 140'734'676'758'836
   //    can we now get the value at that pointer ? 
   //    no
   // dnd(*(int *)140734676758836); // segmentation fault

   int a = 11235; 
   int * int_pointer_adress_of_a =  &a; 
   int p_adress_of_a = &a; // this will corrupt the pointer value if not sizeof(int*) != sizeof(int)
   dnd(sizeof(int*));
   dnd(sizeof(int));
   long li_adress_of_a = (long) &a;

   printf("%p\n", int_pointer_adress_of_a);
   printf("%p\n", p_adress_of_a);
   printf("%li\n", li_adress_of_a);
   
   int value_at_address_of_a = *int_pointer_adress_of_a;
   printf("%i\n", value_at_address_of_a);

   int value_at_address_of_a2 = *(int *)li_adress_of_a; // to readout a adress by a long we have to convert the long to an int pointer (int *) and then derefence it by adding * in front 
   printf("%i\n", value_at_address_of_a);
  
   //    can we change the value by the pointer long 
   *(int *)li_adress_of_a = 8888;
   dnd(a);
   //    yes !!
   *int_pointer_adress_of_a = 9999;
   dnd(a);


   //    can we manually assign a address ? 

   long long_address_of_pointer = 150000000000000;
   int * int_pointer_data_type_adress = (int *) long_address_of_pointer;
   printf("%p", int_pointer_adress_of_a);
   
   dnd(*(int*)long_address_of_pointer); // segmentation fault , we cannot just read out a value at a random address

   //    can we assign a value at a random address? 
   *(int*)long_address_of_pointer = 1234; // segmentation fault, we cannot just change a value at a random address

}

void printing_pointer_as_long(){
   // int a = 1234; 
   // printf("%li\n", (long)&a);
   // printf("%li\n", (long)(&a));

   int b = 4312; 
   int address_of_b = (long) &b;
   int second_address_of_b = (long) (&b);
   printf("%li\n", address_of_b);
   printf("%li\n", second_address_of_b);


}

void f_pointer_arithmetic(){
   // since there is no uint8 type in c we need to use a char !!!
   char n_number = 188;

   // now assume this
   // |8 bits(one byte) |address/index    |
   // |---              |---              |
   // |.... ....        |4999             |
   // |1010 1110        |5000             |
   // |1111 0101        |5001             |
   // |1010 1000        |5002             |
   // |0001 1100        |5003             |
   // |1010 0011        |5004             |
   // |0101 1001        |5005             |
   // |1011 1111        |5006             |
   // |.... ....        |4999             |

   // so if we allocate memory for two bytes / two chars
   char * array_for_two_chars = malloc(2 * sizeof(char)); // malloc does take number of bytes as argument
   

   // the first adress should be a number 
   // the second adress should be a number + 1
   printf("address/index of array_for_two_chars    : %p\n", array_for_two_chars);      // 0x55f5be7a52a0
   printf("address/index of array_for_two_chars+1  : %p\n",  array_for_two_chars+1);   // 0x55f5be7a52a1
                                                                                       //              ^ indeed + 1
                                                                                       
   // now if we do the same for an int which is 4 bytes, the second address should be offset by 4!!!
   int * array_of_two_ints = malloc(2 * sizeof(int)); 
   printf("address/index of array_of_two_ints   : %p\n", array_of_two_ints);     // 0x55f5be7a56d0
   printf("address/index of array_of_two_ints+1 : %p\n", array_of_two_ints+1);   // 0x55f5be7a56d4
                                                                                 //              ^ indeed + 4
   

   // so there we go!!! this is fucking stupid as fuck i swear 
   // ohni scheiss ey... 
}

void f_pointer_arithmetic_simple(){

   // ok i am willing to go that far 
   // n_ = number
   // o_ = object
   // a_ = array 
   // s_ = string
   // i_ = index
   // f_ = function

   char * i_char_single = malloc(1); // allocate 1 byte (returns a pointer/index)
   long n_index_char_single = (long) i_char_single;

   printf("adress %li\n", n_index_char_single);

   char * i_char_array = malloc(10); // now we get 10 bytes
   long n_index_char_array = (long) i_char_array;

   printf("adress %li\n", n_index_char_array);

   printf("since it is a datatype char(1 byte)\n");
   printf("as we can see the index/adress increments always by +1=>(+1)\n");

   printf("index/address   %p\n", i_char_array);
   printf("index/address+1 %p\n", i_char_array+1);
   printf("index/address+2 %p\n", i_char_array+2);
   printf("index/address+3 %p\n", i_char_array+3);
   printf("index/address+4 %p\n", i_char_array+4);
   printf("index/address+5 %p\n", i_char_array+5);
   printf("index/address+6 %p\n", i_char_array+6);
   printf("index/address+7 %p\n", i_char_array+7);
   printf("index/address+8 %p\n", i_char_array+8);
   printf("index/address+9 %p\n", i_char_array+9);


   printf("but ! , if we convert the index to a short index\n");
   printf("since it is a datatype short(2 byte)\n");
   printf("as we can see the index/adress increments always by +1=>(+2)\n");


   short * i_char_array_short = i_char_array;
   printf("index/address   %p\n", i_char_array_short);
   printf("index/address+1 %p\n", i_char_array_short+1);
   printf("index/address+2 %p\n", i_char_array_short+2);
   printf("index/address+3 %p\n", i_char_array_short+3);

   // i würd mau sägä d pointer arithmetik isch ja mau z dümmste wome het chönne mache ohni scheiss!
   // wrum zum fick würdme mathematischi reglä bräche ohni witz, das isch huere behinderet
   // me het sicher gmeint es machts am programmierer eifacher, aber dasser z ganze memory management mit "malloc" , "calloc" und "free" mues mache
   // das isch de nid kompliziert... 
   // wele hueresohn het das erfunde 

   printf("so we can conclude\n");
   printf("|bits             |index/address       |char index    |short index   |int index  |long index |\n");     
   printf("|---              |---                 |---           |---           |---        |---        |\n");
   printf("|1010 1110        |5000                |(char*)+ 0    |(short*)+0    |(int*)+0   |(long*)+0  |\n");
   printf("|1111 0101        |5001                |(char*)+ 1    |              |           |           |\n");
   printf("|1010 1000        |5002                |(char*)+ 2    |(short*)+1    |           |           |\n");   
   printf("|0001 1100        |5003                |(char*)+ 3    |              |           |           |\n");
   printf("|1010 0011        |5004                |(char*)+ 4    |(short*)+2    |(int*)+1   |           |\n");
   printf("|0101 1001        |5005                |(char*)+ 5    |              |           |           |\n");
   printf("|1011 1111        |5006                |(char*)+ 6    |(short*)+3    |           |           |\n");
   printf("|0111 0101        |5007                |(char*)+ 7    |              |           |           |\n");
   printf("|1110 1000        |5008                |(char*)+ 8    |(short*)+4    |(int*)+2   |(long*)+1  |\n");
   printf("|0000 0101        |5009                |(char*)+ 9    |              |           |           |\n");
   printf("|0101 1100        |5010                |(char*)+10    |(short*)+5    |           |           |\n");
   printf("|1110 1110        |5011                |(char*)+11    |              |           |           |\n");
   printf("|0001 0011        |5012                |(char*)+12    |(short*)+6    |(int*)+3   |           |\n");
}
int main() {
   
   //why_is_this_not_working();
   // passing_to_function();

   // what_are_pointers();

   //are_bytes_in_ram_grouped();

   // simple_int_pointer();

   // pass_int_pointer_to_function();
   
   // simple_char_pointer();

   // change_char_in_function();

   //initializing_string_problems();

   //dynamically_create_string();
   
   // get_value_of_random_address();

   // f_pointer_arithmetic();

   f_pointer_arithmetic_simple();

   f_read_out_a_byte();
   
   // printing_pointer_as_long();
   //  char_info();
   //string_info();
   return 0;
}
