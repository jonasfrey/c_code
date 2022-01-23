#include <stdio.h>

#include <limits.h> // INT_MIN and INT_MAX

#include <math.h> // dont forget gcc -lm link math
#include "./dnd.c"

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
    if(n_long<1000000000000000000) return 18;
    return 0;
}


long f_n_decimal_places_in_integer_logarithmic(long n_long){

    int n_exponent = log10(n_long);
    
    return (n_exponent+1);

}

long f_n_decimal_places_in_integer(long n_long){
    return f_n_decimal_places_in_integer_static(n_long);
}


const char* int_to_string(long n_int){ 
    
    //dndli(n_int);

    int n_decimal_places = f_n_decimal_places_in_integer_logarithmic(n_int);
    int n_single_quotes = ((((float) n_decimal_places) / 3) -1) + (((int)(n_decimal_places%3)>0)*(1));

    //dnd(n_decimal_places);
    //dnd(n_single_quotes);

    int n_number_as_string_length = n_decimal_places;
    int n_number_as_string_length_with_null_terminator = n_number_as_string_length + 1; 
    char s_number_as_string[n_number_as_string_length_with_null_terminator];

    sprintf(s_number_as_string, "%li",n_int);
    if(n_single_quotes == 0){
        return s_number_as_string;
    }
    //dnds(s_number_as_string);

    int n_number_as_string_with_single_quotes_length = n_decimal_places+n_single_quotes;
    int n_number_as_string_with_single_quotes_length_with_null_terminator = n_number_as_string_with_single_quotes_length + 1; 
    
    char s_number_as_string_with_single_quotes[n_number_as_string_with_single_quotes_length_with_null_terminator];
    s_number_as_string_with_single_quotes[n_number_as_string_with_single_quotes_length_with_null_terminator-1] = '\0';
    

    int n_number_as_string_decimal_place_index = n_number_as_string_length-1;// strlen(s_number_as_string)
    int counter = 1; 
    for(int i = n_number_as_string_with_single_quotes_length-1; i>=0; i--){
        if(counter%4 == 0){ 
            s_number_as_string_with_single_quotes[i] = '\'';
        }else{

            s_number_as_string_with_single_quotes[i] = s_number_as_string[n_number_as_string_decimal_place_index];//
            n_number_as_string_decimal_place_index--; 
        }
        counter++;

    }
    //dnd(n_number_as_string_length);
    //dnds(s_number_as_string_with_single_quotes)

    return s_number_as_string_with_single_quotes;
    //return s_number_as_string_with_single_quotes;
    //char str[ENOUGH];
    //sprintf(str, "%d", 42);
}


void f_test_f_n_decimal_places_in_integer_logarithmic(){

    long n_input = 1;
    printf("digits in %li:%li",n_input, f_n_decimal_places_in_integer_logarithmic( n_input));
    
    n_input = 123;
    printf("digits in %li:%li",n_input, f_n_decimal_places_in_integer_logarithmic( n_input));
    
    n_input = pow(2,32);
    printf("digits in %li:%li",n_input, f_n_decimal_places_in_integer_logarithmic( n_input));
    
    n_input = 18000000Lu;
    printf("digits in %li:%li",n_input, f_n_decimal_places_in_integer_logarithmic( n_input));
    
    n_input = -1;
    printf("digits in %li:%li",n_input, f_n_decimal_places_in_integer_logarithmic( n_input));
    
    n_input = -123;
    printf("digits in %li:%li",n_input, f_n_decimal_places_in_integer_logarithmic( n_input));
    
    n_input = -pow(2,32);
    printf("digits in %li:%li",n_input, f_n_decimal_places_in_integer_logarithmic( n_input));
    
    n_input = -18000000Lu;
    printf("digits in %li:%li",n_input, f_n_decimal_places_in_integer_logarithmic( n_input));
    
    //return 0; 
    
}
int main(){

    // f_test_decimal_places_in_integer_logarhitmic();
    int n = (123123);
    char s = int_to_string(n);
    dnd(n);
    dnds(*s); // 123'123
    n = (123123123);
    s = int_to_string(n);
    dnd(n);
    dnds(*s); // 123'123'123
    n = (12312312312);
    s = int_to_string(n);
    dnd(n);
    dnds(*s); // 12'312'312'312
    n = (1);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    n = (123);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    n = (1234);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    n = (12345);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    n = (123456);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    n = (1234567);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    n = (12345678);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    n = (123456789);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    n = (1234567891);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    n = (12345678912);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    n = (123456789123);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    n = (1234567891234);
    s = int_to_string(n);
    dnd(n);
    dnds(*s );
    
    return 0; 
}