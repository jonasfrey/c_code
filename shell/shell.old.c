
// c file
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N_BUFFERSIZE_TOKEN 64
#define S_SEPERATOR " \t\r\n\a" // ' ' whitespace , \t, horizontal tab, \r carriage return, \a alert(beep, bell)
#define PID_CHILD_PROCESS 0
#define SHELL_WELCOME_STRING "$ "

void do_nothing_to_prevent_werror() {}

int fork_process(char **args)
{
    pid_t n_process_id;
    pid_t n_wait_process_id;

    int status;

    n_process_id = fork();

    if (n_process_id == PID_CHILD_PROCESS)
    {
        int n_executed_command_return = execvp(args[0], args);
        if (n_executed_command_return == -1)
        {
            printf("error in execvp");
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
        // printf("waitpid called");
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

void split_line_at_whitespaces(char *s_string, char **a_args, char **a_vars)
{
    int n_buffer_size = N_BUFFERSIZE_TOKEN;
    int n_buffer_index = 0;
    int n_buffer_index_vars = 0;

    char **a_token = malloc(n_buffer_size * sizeof(char *));

    char **a_args_tmp = malloc(512 * sizeof(char *));
    char **a_vars_tmp = malloc(512 * sizeof(char *));

    char *index_of_equal;

    char *s_part;

    if (!a_token)
    {
        fprintf(stderr, "error in allocation\n");
        exit(EXIT_FAILURE);
    }

    // get the first part like s_string.split().shift()
    s_part = strtok(s_string, S_SEPERATOR);

    while (s_part != NULL)
    {
        index_of_equal = strstr(s_part, "=");

        if (index_of_equal)
        {
            // a_token[n_buffer_index] = s_part;
            a_args_tmp[n_buffer_index] = s_part;
            n_buffer_index++;
        }
        else
        {
            a_vars_tmp[n_buffer_index_vars] = s_part;
            n_buffer_index_vars++;
        }

        // printf("\nindex is %i", n_buffer_index);

        // if (n_buffer_index >= n_buffer_size)
        // {
        //     n_buffer_size += N_BUFFERSIZE_TOKEN;
        //     a_token = realloc(a_token, n_buffer_size * sizeof(char *));
        //     if (!a_token)
        //     {
        //         fprintf(stderr, "error in allocation \n");
        //         exit(EXIT_FAILURE);
        //     }
        // }

        // get the next part
        // Alternativelly, a strtok(NULL,... null pointer may be specified as first argument,
        // in which case the function continues scanning where a previous successful call to the function ended.
        s_part = strtok(NULL, S_SEPERATOR);
    }

    // a_token[n_buffer_index] = NULL;
    a_args_tmp[n_buffer_index] = NULL;
    a_vars_tmp[n_buffer_index_vars] = NULL;

    a_args = a_args_tmp;
    a_vars = a_vars_tmp;
    // return a_token;
}

char *read_line()
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
    char *s_string_pointer;
    char **a_args;
    char **a_vars;

    int n_command_return_value = 1;
    int n_command_return_value_last;

    while (n_command_return_value)
    {

        printf(SHELL_WELCOME_STRING);

        s_string_pointer = read_line();
        // printf("\n read line is: %s", s_string_pointer);

        split_line_at_whitespaces(s_string_pointer, a_args, a_vars);

        // replace_variables_in_a_args();

        n_command_return_value = execute_command(a_args);

        if (n_command_return_value)
        {
            do_nothing_to_prevent_werror();
        }

        // printf("n_command_return_value: %i" , n_command_return_value);

        n_command_return_value_last = n_command_return_value;

        free(s_string_pointer);
        free(a_args);
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
