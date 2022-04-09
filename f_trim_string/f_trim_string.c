
// c file 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void f_trim_string_end(char *s_input){
    // printf("sinput %s", s_input);
    char * s_new_string = malloc(strlen(s_input));
    int n_end_index = strlen(s_input)-1;
    while(isspace(s_input[n_end_index])){
        n_end_index--;
    }
    int n_i = 0; 
    while(n_i <= n_end_index){
        s_new_string[n_i] = s_input[n_i];
        n_i++;
    }
    // printf("s_input %s\n", s_input);
    // printf("s_new_string %s\n", s_new_string);
    // printf("n_end_index %i\n", n_end_index);
    
    strcpy(s_input, s_new_string);
}
void f_trim_string_start(char *s_input){
    // printf("sinput %s", s_input);
    char * s_new_string = malloc(strlen(s_input)+1);
    int n_start_index = 0;
    int n_end_index = strlen(s_input)-1;
    while(isspace(s_input[n_start_index])){
        n_start_index++;
    }
    int n_i = n_start_index;
    int n_i2 = 0; 
    while(n_i <= n_end_index){
        s_new_string[n_i2] = s_input[n_i];
        n_i++;
        n_i2++;
    }
    // printf("s_input %s\n", s_input);
    // printf("s_new_string %s\n", s_new_string);
    // printf("n_start_index %i\n", n_start_index);
    // printf("n_end_index %i\n", n_end_index);
    
    strcpy(s_input, s_new_string);
    
}
void f_trim_string(char *s_input)
{
    f_trim_string_start(s_input);
    f_trim_string_end(s_input);
}

int main() {

    //    char * s_test1 = "     s_my_super_string       x   "; // this is read only
    char s_test1[] = "     s_my_super_string       x   "; // this is not read only
    //    char s_test1[100] = "     s_my_super_string       x   ";
    f_trim_string(s_test1);

    char s_test2[] = "  lol ooool    ";
    char s_test3[] = "_a_";
    char s_test4[] = "  ---a";
    char s_test5[] = "---a  ";

    f_trim_string(s_test1); 
    f_trim_string(s_test2); 
    f_trim_string(s_test3); 
    f_trim_string(s_test4); 
    f_trim_string(s_test5); 

    printf("s_test1 trimmed:%s\n", s_test1); 
    printf("s_test2 trimmed:%s\n", s_test2); 
    printf("s_test3 trimmed:%s\n", s_test3); 
    printf("s_test4 trimmed:%s\n", s_test4); 
    printf("s_test5 trimmed:%s\n", s_test5); 

    return 0;
}
