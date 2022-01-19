#include <stdio.h>

#include <limits.h> // INT_MIN and INT_MAX

#include <math.h> // dont forget gcc -lm link math

long f_n_decimal_places_in_integer_static(long n_long){

    // if(n_long<0) n_long = (n_long == LONG_MIN) ? LONG_MAX : -n_long;
    if(n_long<0) n_long *= -1;
    if(n_long<10) return 1;
    if(n_long<100) return 2;
    if(n_long<1000) return 3;
    if(n_long<10000) return 4;
    if(n_long<100000) return 5;
    if(n_long<1000000) return 6;
    if(n_long<10000000) return 7;
    if(n_long<100000000) return 8;
    if(n_long<1000000000) return 9;
    if(n_long<10000000000) return 10;
    if(n_long<100000000000) return 11;
    if(n_long<1000000000000) return 12;
    if(n_long<10000000000000) return 13;
    if(n_long<100000000000000) return 14;
    if(n_long<1000000000000000) return 15;
    if(n_long<10000000000000000) return 16;
    if(n_long<100000000000000000) return 17;
    
}


int f_n_decimal_places_in_integer_logarhitmic(long n_long){

    int n_exponent = log10(n_long);
    
    return (n_exponent+1);

}

long f_n_decimal_places_in_integer(long n_long){
    return f_n_decimal_places_in_integer_static(n_long);
}

const char * int_to_string(int n_int){ 
    
    //int n_decimal_places = 
    //char str[ENOUGH];
    //sprintf(str, "%d", 42);
}



void f_test_decimal_places_in_integer_logarhitmic(){

    int n_input = 1;
    printf("digits in %i:%i",n_input, f_n_decimal_places_in_integer_logarhitmic(n_input));
    
    int n_input = 123;
    printf("digits in %i:%i",n_input, f_n_decimal_places_in_integer_logarhitmic(n_input));
    
    long n_input = pow(2,32);
    printf("digits in %li:%li",n_input, f_n_decimal_places_in_integer_logarhitmic(n_input));
    
    int n_input = 18000000Lu;
    printf("digits in %i:%i",n_input, f_n_decimal_places_in_integer_logarhitmic(n_input));
    
    int n_input = 1;
    printf("digits in %i:%i",n_input, f_n_decimal_places_in_integer_logarhitmic(n_input));
    
}
int main(){

    f_test_decimal_places_in_integer_logarhitmic();
    return 0; 
}