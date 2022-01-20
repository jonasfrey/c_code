// c file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 2048



char f_s_ascii_char_to_upper(char s_char)
{
    int n_char = s_char;
    n_char = ((n_char - 65) % 32) + 65; // ascii A is number 65 // ascii 'a' is 97 = 65+32
    printf("%i", n_char);

    return (char)n_char;
}

char f_s_ascii_char_to_lower(char s_char)
{
    int n_char = s_char;
    n_char = (((n_char - 65) % 32) + 65) + 32; // ascii A is number 65 // ascii 'a' is 97 = 65+32
    return (char)n_char;
}



int main(int argc, char **argv)
{

    int b_sort_descending = 0;

    int n_i = 0;
    for (n_i = 0; n_i < argc; ++n_i)
    {

        // printf("\n printf argv n_i %%c %c", argv[n_i][0]);

        char s_first_letter_of_string = argv[n_i][0];

        if (
            n_i == 0 ||
            s_first_letter_of_string == '-')
        {
            if (f_s_ascii_char_to_lower(argv[n_i][1]) == 'r')
            {
                b_sort_descending = 1;
            }
            continue;
        }

    }


    char a_strings[MAX_STR_SIZE][MAX_STR_SIZE];

    char *str = malloc(MAX_STR_SIZE);     /* (1) */
    int i = 0;
    while(fgets(str, MAX_STR_SIZE, stdin) != NULL){
            strcpy( a_strings[i] ,str);
            //printf("str is %s", str);
        i++;
    }
    free(str);
    int n_number_of_strings = i; 


    char s_tmp[MAX_STR_SIZE];

    // Sort array using the Buuble Sort algorithm
    for (int i = 0; i < n_number_of_strings; i++)
    {
        for (int j = 0; j < n_number_of_strings - 1 - i; j++)
        {

                if (strcmp(a_strings[j], a_strings[j + 1]) > 0)
                {
                    // swap array[j] and array[j+1]
                    strcpy(s_tmp, a_strings[j]);
                    strcpy(a_strings[j], a_strings[j + 1]);
                    strcpy(a_strings[j + 1], s_tmp);
                }
            
        }
    }
    
    //printf("sort descending %i", b_sort_descending);

    if(b_sort_descending){
        for (int n_i = n_number_of_strings-1; n_i >=0; n_i--)
        {
            printf("%s", a_strings[n_i]);

        }
    }else{
        for (int n_i = 0; n_i < n_number_of_strings; n_i++)
        {
            printf("%s", a_strings[n_i]);

        }
    }



    return 0;
}
