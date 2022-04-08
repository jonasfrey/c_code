
// c file 
#include <stdio.h>

// to have the array size in 
// the parameter is unneccessary since 
//the functions receives only a pointer anyway
// int ar4[4] = {1,2,3,4};
// array_length_in_parameter(ar4);// will work
// int ar1[1] = {1};
// array_length_in_parameter(ar1);// will work
void array_length_in_parameter(int arr[3]){} 
// this is better and does the same
void array_in_parameter(int *arr){}

// void literlas() {

//    // literals 
//    212;         /* Legal */
//    215u;        /* Legal */
//    0xFeeL;      /* Legal (long)4078L */
//    078;         /* Illegal: 8 is not an octal digit */ 
//    032UU;       /* Illegal: cannot repeat a suffix */
//    85;         /* decimal */
//    0213;       /* octal */
//    0x4b;       /* hexadecimal */
//    30;         /* int */
//    30u;        /* unsigned int */
//    30l;        /* long */
//    30ul;       /* unsigned long */
//    0b0001;      // signed int binary
//    0b0001u;      // unsigned int binary 
//    3.14159;       /* Legal */
//    314159E-5L;    /* Legal */
//    510E;          /* Illegal: incomplete exponent */
//    210f;          /* Illegal: no decimal or exponent */
//    .e55;          /* Illegal: missing integer or fraction */
//    // string literals
//    "hello, \   
//    dear";// (char [15])"hello,    dear"
//    "hello, " "d" "ear"; // becomes one string ->"hello, dear"
// //    return 0;

// }

// static in c 
//A static variable inside a function keeps its value between invocations.
//A static global variable or a function is "seen" only in the file it's declared in
void foo(){
   int a = 10;
   static int sa = 10;
   a += 5;
   sa += 5;
   printf("a = %d, sa = %d\n", a, sa);
}
int main(){
   for (int i = 0; i < 5; ++i)
      foo();
   // output is 
   // a = 15, sa = 15
   // a = 15, sa = 20
   // a = 15, sa = 25
   // a = 15, sa = 30
   // a = 15, sa = 35
   
   printf_stuff();
}

int main2(){
   // bitwise_operators();

   // int ar4[4] = {1,2,3,4};
   // array_length_in_parameter(ar4);// will work
   // int ar1[1] = {1};
   // array_length_in_parameter(ar1);// will work
}


int a(){return 1;} int b(){return 2;} int c(){return 3;}
//bitwise operators
void bitwise_operators(){
   printf("%i\n", 0b0101 & 0b1011); // prints 0b0001 <= 1dec
   printf("%i\n", 0b0101 | 0b1011); // prints 0b1111 <= 15dec   
   printf("%i\n", 0b0101 ^ 0b1011); // prints 0b1110 <= 14dec

   //~	Binary One's Complement Operator is unary and 
   // has the effect of 'flipping' bits.
   //	(~A ) = ~(60), i.e,. -0111101
   printf("%i\n", (~0b0101) ); // prints -6dec
   printf("%i\n", (0b0101 << 2)); // prints 0b010100 <= 20dec   
   printf("%i\n", (0b1101 >> 1)); // prints 0b0110 <= 6dec
   
   // comma ',' as an operator in c 
   int i = a(), c(), b(); 
   // a() is evaluated, c() is evaluated, b() is evaluated 
   // and its return value is assigned to int i 
   // if the functions are 
   // int a(){return 1;}; int b(){return 2;}; int c(){return 3;};
   // i is then 2
   int ii = (5, 10);// ii is 10
}

void special_chars_names(){
// ~	Tilde.
// `	Acute, backquote, backtick, grave, grave accent, left quote, open quote, or a push.
// !	Exclamation mark, exclamation point, or bang.
// @	Ampersat, arobase, asperand, at, or at symbol.
// #	Octothorpe, number, pound, sharp, or hash.
// $	Dollar sign or generic currency.
// %	Percent.
// ^	Caret or circumflex.
// &	Ampersand, epershand, or and symbol.
// *	Asterisk, mathematical multiplication symbol, and sometimes referred to as a star.
// (	Open or left parenthesis.
// )	Close or right parenthesis.
// -	Hyphen, minus, or dash.
// _	Underscore.
// +	Plus.
// =	Equal.
// {	Open brace, squiggly brackets, or curly bracket.
// }	Close brace, squiggly brackets, or curly bracket.
// [	Open bracket.
// ]	Closed bracket.
// |	Pipe, or, or vertical bar.
// \	Backslash or reverse solidus.
// /	Forward slash, solidus, virgule, whack, and mathematical division symbol.
// :	Colon.
// ;	Semicolon.
// "	Quote, quotation mark, or inverted commas.
// '	Apostrophe or single quote.
// <	Less than or angle brackets.
// >	Greater than or angle brackets.
// ,	Comma.
// .	Period, dot, or full stop.
// ?	Question mark.
}

void printf_stuff(){
   //Character
   printf("%c\n", 65); //prints 'A' 
   //Character
   printf("%c\n", 'A'); //prints 'A' 
   //%d or %i Signed decimal integer
   printf("%d\n", 10); //prints '10' 
   //%d or %i Signed decimal integer
   printf("%i\n", 10); //prints '10' 
   //long
   printf("%li\n", 10L); //prints '10' 
   //Scientific notation (mantissa/exponent) using e character
   printf("%e\n", 1234.123412341234); //prints '1.234123e+03' 
   //Scientific notation (mantissa/exponent) using E character
   printf("%E\n", 1234.123412341234); //prints '1.234123E+03' 
   //Decimal floating point
   printf("%f\n", 2.21234f); //prints '2.212340' 
   //Uses the shorter of %e or %f
   printf("%g\n", 1234.123412341234); //prints '1234.12' 
   //Uses the shorter of %E or %f
   printf("%G\n", 1234.123412341234); //prints '1234.12' 
   //Signed octal
   printf("%o\n", 8); //prints '10' 
   //String of characters
   printf("%s\n", "hi there"); //prints 'hi there' 
   //Unsigned decimal integer
   printf("%u\n", 1234); //prints '1234' 
   //Unsigned hexadecimal integer
   printf("%x\n", 255); //prints 'ff' 
   //Unsigned hexadecimal integer (capital letters)
   printf("%X\n", 255); //prints 'FF' 
   int i = 10;
   //Pointer address
   printf("%p\n", &i); //prints '0x7ffdb48b9184' 
   //Nothing printed
   printf("%n\n"); //prints '' 
   //Character
   printf("%%\n", 'c'); //prints '%' 
}