
// c file
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "./../c_helpers/dnd.c"

#define N_BUFFERSIZE_TOKEN 64
#define S_SEPERATOR " \t\r\n\a" // ' ' whitespace , \t, horizontal tab, \r carriage return, \a alert(beep, bell)
#define PID_CHILD_PROCESS 0
#define SHELL_WELCOME_STRING "$ "

int n_a_variables_length = 0;

void do_nothing_to_prevent_werror() {}


void print_string_array(char **a_strings)
{
    dnds("print_string_array called");
    int i = 0;
    if(a_strings[0] == NULL){
        dnds("string array empty");
    }
    while (a_strings[i] != NULL)
    {
        printf("%s\n", a_strings[i]);
        // dnd(a_strings[i]);
        i++;
    }
}


char *substr(const char *src, int n_start, int n_end)
{
    int len = n_end - n_start;

    char *dest = (char *)malloc(sizeof(char) * (len + 1));

    for (int i = n_start; i < n_end && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }

    *dest = '\0';

    return dest - len;
}

char *get_string_unitl_first_char(const char *s_string, char s_char)
{

    char *index_of_char = strstr(s_string, (char[2]){(char)s_char, '\0'});
    char *s_all_before_first_equal = substr(s_string, 0, index_of_char - s_string);

    return s_all_before_first_equal;
}

char *get_string_after_first_char(const char *s_string, char s_char)
{

    char *index_of_equal = strstr(s_string, (char[2]){(char)s_char, '\0'});
    char *s_all_after_first_equal = index_of_equal + 1;
    return s_all_after_first_equal;
}

int fork_process(char **args)
{
    pid_t n_process_id;
    pid_t n_wait_process_id;

    int status;

    n_process_id = fork(); // 

    if (n_process_id == PID_CHILD_PROCESS)
    {
        if (execvp(args[0], args) == -1)
        {
            printf("error in execvp");

            // perror("lsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (n_process_id < PID_CHILD_PROCESS)
    {
        // error
        printf("there was an error with the fork() function");
    }
    else
    {
        // Parent process
        // while (
        //     !WIFEXITED(status) &&
        //     !WIFSIGNALED(status))
        // {
            n_wait_process_id = waitpid(n_process_id, &status, WUNTRACED);
        // }
    }

    if (n_wait_process_id)
    {
        do_nothing_to_prevent_werror();
    }

    return 1;
}

int execute_command(char **args)
{

    if (args[0] == NULL)
    {
        printf("no binary nor arguments are present");
        return 1;
    }

    return fork_process(args);
}

void split_line_at_whitespaces(char *s_string, char **a_arguments, char **a_variables)
{
    int n_buffer_size = N_BUFFERSIZE_TOKEN;
    int n_a_arguments_length = 0;
    char *s_part;
    char *n_index_of_equal_symbol;

    if (!a_arguments)
    {
        fprintf(stderr, "error in allocation\n");
        exit(EXIT_FAILURE);
    }
    // a=2 b=3 c=5

    // get the first part like s_string.split().shift()
    s_part = strtok(s_string, S_SEPERATOR);

    while (s_part != NULL)
    {
        n_index_of_equal_symbol = strstr(s_part, "=");
        

        if (n_index_of_equal_symbol)
        {
            
            // print_string_array(a_variables);
            
            a_variables[n_a_variables_length] = s_part;

            n_a_variables_length++;

            //dnd(n_a_variables_length);  

        }
        else
        {
            // a_token[n_a_arguments_length] = s_part;
            a_arguments[n_a_arguments_length] = s_part;
            n_a_arguments_length++;
        }

        // printf("\nindex is %i", n_a_arguments_length);

        if (n_a_arguments_length >= n_buffer_size)
        {
            n_buffer_size += N_BUFFERSIZE_TOKEN;
            a_arguments = realloc(a_arguments, n_buffer_size * sizeof(char *));
            if (!a_arguments)
            {
                fprintf(stderr, "error in allocation \n");
                exit(EXIT_FAILURE);
            }
        }

        // get the next part
        // Alternativelly, a strtok(NULL,... null pointer may be specified as first argument,
        // in which case the function continues scanning where a previous successful call to the function ended.
        s_part = strtok(NULL, S_SEPERATOR);
    }

    a_arguments[n_a_arguments_length] = NULL;

    a_variables[n_a_variables_length] = NULL;
}

char *replaceWord(const char *s, const char *oldW,const char *newW)
{
    char *result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], oldW) == &s[i])
        {
            cnt++;

            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }

    // Making new string of enough length
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);

    i = 0;
    while (*s)
    {
        // compare the substring with the result
        if (strstr(s, oldW) == s)
        {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
}

void replace_variables_in_arguments(char **a_arguments, char **a_variables)
{
    int n_a_arguments_index = 0;
    char *n_index_of_dollar;

    char *n_index_of_variable_in_argument;
    while (a_arguments[n_a_arguments_index] != NULL)
    {

        n_index_of_dollar = strstr(a_arguments[n_a_arguments_index], "$");
        if (n_index_of_dollar)
        {
            int n_a_variables_index = 0;
            while (a_variables[n_a_variables_index] != NULL)
            {

                char *s_variable_name = get_string_unitl_first_char(a_variables[n_a_variables_index], '=');
                char *s_variable_value = get_string_after_first_char(a_variables[n_a_variables_index], '=');
                printf("variable_name: %s\n", s_variable_name);
                printf("variable_value: %s\n", s_variable_value);
                n_index_of_variable_in_argument = strstr(a_arguments[n_a_arguments_index], s_variable_name);

                if (n_index_of_variable_in_argument)
                {
                    // replaceWord(a_arguments[n_a_arguments_index], s_variable_name, s_variable_value)
                }

                n_a_variables_index++;
            }
        }

        n_a_arguments_index++;
    }
}

//read line new
char *read_line(){
    int n_max_chars =1024;
    char *s_fgets_return;
    char *s_line = malloc(n_max_chars+1);
    
    s_fgets_return =fgets(s_line, n_max_chars, stdin);
    while(s_fgets_return != NULL){
        return s_line;
        // printf("%s\n", s_line); 
        // s_fgets_return = fgets(s_line, n_max_chars, stdin);

    }
    return s_line;
}
char *read_line_old()
{

    int n_buffer_size = 4096;
    int n_buffer_index = 0;
    char *i_buffer_pointer = malloc(sizeof(char) * n_buffer_size);
    int c;

    while (1)
    {
        // Read a character
        c = getchar();

        // If we hit EOF, replace it with a null character and return.
        if (c == EOF || c == '\n')
        {
            i_buffer_pointer[n_buffer_index] = '\0';
            return i_buffer_pointer;
        }
        else
        {
            i_buffer_pointer[n_buffer_index] = c;
        }
        n_buffer_index++;
    }
}



int main()
{
    int n_max_chars =1024;

    char *s_string_pointer = malloc(n_max_chars);
    char *s_fgets_ret = malloc(n_max_chars);

    char **a_variables = malloc(64 * sizeof(char *));


    char **a_arguments = malloc(64 * sizeof(char *));


    int n_command_return_value = 1;
    int n_command_return_value_last;

    while (n_command_return_value)
    {

        printf(SHELL_WELCOME_STRING);
        // fflush(stdout);

        // s_string_pointer = read_line();
        s_fgets_ret = fgets(s_string_pointer, n_max_chars, stdin);
        if(s_fgets_ret == NULL){
            return 0;
        }


        if(s_string_pointer == NULL){
            return 0;
        }

        split_line_at_whitespaces(s_string_pointer, a_arguments, a_variables);
        
        //print_string_array(a_variables);
        
        // dnds(a_variables[2]);
        // dnds(a_variables[n_a_variables_length]);
        
        if (a_arguments[0] != NULL)
        {
            n_command_return_value = execute_command(a_arguments);
        } // else a_arguments is empty

        if (n_command_return_value)
        {
            do_nothing_to_prevent_werror();
        }

        //printf("n_command_return_value: %i", n_command_return_value);

        n_command_return_value_last = n_command_return_value;

        if (a_arguments[0] != NULL)
        {
            free(a_arguments);
        } // else a_arguments is empty

        //free(s_string_pointer);
    }

    if (n_command_return_value_last)
    {
        do_nothing_to_prevent_werror();
    }

    // printf("\nsizeof(a_args) %li", sizeof(a_args));
    // printf("\nsizeof(&a_args) %li", sizeof(&a_args));

    // printf("\nsizeof(a_args[0]) %li", sizeof(a_args[0]));
    // printf("\nsizeof(&a_args[0]) %li", sizeof(&a_args[0]));

    // for(int i = 0; i < (sizeof(&a_args)/sizeof(a_args[0])); i++){
    //    printf("\narg is %s", a_args[i]);
    // }

    // int i = 0;
    // while(a_args[i] != NULL){
    //    i++;
    //    printf("\narg is %s", a_args[i]);
    // }

    return 0;
}
