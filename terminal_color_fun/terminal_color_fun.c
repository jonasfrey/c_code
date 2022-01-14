#include <stdio.h>
#include <string.h>


#include "./ansi_color_constants.c"

#include <unistd.h>
#include <time.h>

// #include "./../c_helpers/c_helpers"


void clear_screen_ansi_terminals(){
    printf("\e[1;1H\e[2J");
}
void clear_screen_ansi_terminals_with_newlines(){
    int i;
    int n_lines = 10;
    for(i = 0 ; i < n_lines; i++){
        printf("\n");
    }
}


void loop_through_colors()
{

    int n_end = 512;
    int n_start = 10;

    while (n_start < n_end)
    {

        n_start++;

        printf("\\x1b[%im: \x1b[%im quick brown fox jumps over the lazy dog" ANSI_COLOR_RESET "\n", n_start, n_start);
    }
}

void print_text_rainbow(char s_text[], int n_offset){

    int n_string_length = strlen(s_text);
    int n_i = 0;
    int n_color_modulo = 7;
    int n_color_start = 31;
    int n_color_current = n_color_start;

    for (n_i = 0; n_i < n_string_length; n_i++)
    {
        printf("\x1b[%im%c"ANSI_COLOR_RESET, n_color_current, s_text[n_i]);

        n_color_current = n_color_start + ((n_i  + n_offset) % n_color_modulo);
    }

}

void rainbow_animation(char s_text[])
{

    int i;
    for(i = 0; i < 1000; i++){
        
        print_text_rainbow(s_text, i);

        // micro_sleep(1000000*16);
        usleep(1000*16);
        //clear_screen_ansi_terminals();
        clear_screen_ansi_terminals_with_newlines();

    }

}

int main(int argc, char const *argv[])
{

    printf(ANSI_COLOR_RED "This text is RED!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_GREEN "This text is GREEN!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_YELLOW "This text is YELLOW!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_BLUE "This text is BLUE!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_CYAN "This text is CYAN!" ANSI_COLOR_RESET "\n");

    loop_through_colors();

    //rainbow_animation("aaaaaaaaaaaaaaaaaaaaa");
    //rainbow_animation("the quick brown fox jumps over the lazy dog");

    return 0;
}
