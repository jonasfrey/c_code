// int main(int argc, char **argv) {

//     return 0;
// }

/*
 * This program displays the names of all files in the current directory.
 */

#include <dirent.h> 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
// #include "./../c_helpers/dnd.c"


#define MAX_FILENAME_LENGTH 255

#define S_CHAR_SYMLINK  '@'
#define S_CHAR_DIRECTORY  '/'
#define S_CHAR_EXECUTABLE '*'
#define S_CHAR_DEFAULT ' '


void print_chars_of_string(char * s_input){
    for(int i = 0; i< strlen(s_input); i++){
        if(i == 0){
            printf("\n print_chars_of_string first char");
        }
        printf("\nprint_chars_of_string[%i] : %c", i, s_input[i]);

        if(i == strlen(s_input)-1){
            printf("\n print_chars_of_string last char");
        }
    }

}
char * merge_strings(char* s_1, char*s_2){
    // int n_length_s_1 = strlen(s_1);
    // int n_length_s_2 = strlen(s_2);
    // char s_placeholder[n_length_s_1 + n_length_s_2+ 1];
    
    // strcpy(s_placeholder, s_1); 
    // strcpy(s_placeholder, s_2);

    //char * tmp_string = ""; 
    // strcpy(tmp_string, s_1);
    // strcat(tmp_string,s_2);
    
    
    strcat(s_1,s_2);
    return s_1;
}

char get_suffix_char_for_file_detect_filetype(char* file_name){ 

   struct stat path_stat;
   
   //dnds(file_name);

   struct stat buf;


   lstat (file_name, &buf);
   
   // if (S_ISLNK(buf.st_mode)) printf ("\n lstat says link\n");
   // if (S_ISREG(buf.st_mode)) printf ("\n lstat says file\n");

   //check with lstat if it is symlink
   // if we would follow symlinks we could skip lstat and directly use stat
   int b_is_symlink = S_ISLNK(buf.st_mode); 
   int b_follow_symlinks = 0; 

   if(!b_follow_symlinks && b_is_symlink ){
      return S_CHAR_SYMLINK;
   }

   int b_is_executable = 0;

   if (stat(file_name, &path_stat) == 0 && path_stat.st_mode & S_IXUSR) 
      /* executable */
      b_is_executable = 1;
   else  
      b_is_executable = 0;

   // dnd(b_is_executable);
      /* non-executable */

   int b_is_regular_file = S_ISREG(path_stat.st_mode);
   // dnd(b_is_regular_file);

   // int b_is_dir = S_ISDIR(path_stat.st_mode);
   int b_is_dir = !b_is_regular_file;
   // dnd(b_is_dir);


   if(b_is_dir){
      return S_CHAR_DIRECTORY;
   }
   if(b_is_executable){
      return S_CHAR_EXECUTABLE;
   }
   if(b_is_regular_file){
      return S_CHAR_DEFAULT;
   }

   return S_CHAR_DEFAULT;
}

int s_is_hidden_file(char s_path_or_file[]){
    
    // if a hidden file would start with a prefix more than one character
    //      char s_hidden_file_indicator[] = ".";
    //      int is_hidden = strncmp(s_path_or_file, s_hidden_file_indicator, strlen(s_hidden_file_indicator)) == 0;
    
    int is_hidden = s_path_or_file[0] == '.';
    //printf("\n is %s hidden file: %i",s_path_or_file, is_hidden);
    return is_hidden;

}

int main(int argc, char **argv) {

    //-F, --classify
    //      append indicator (one of */=>@|) to entries
    // ls -F appends symbols to filenames. These symbols show useful information about files.

    // @ means symbolic link (or that the file has extended attributes).
    // * means executable.
    // = means socket.
    // | means named pipe.
    // > means door.
    // / means directory.

    //-1     list one file per line.  Avoid '\n' with -q or -b
   
    int b_we_have_to_sort_aswell = 0; 

    // handle the arguments 
    int b_one_file_per_line = 0;
    int b_add_indicator = 0;
    b_one_file_per_line++;
    b_one_file_per_line--;
    b_add_indicator++;
    b_add_indicator--;
    // prevent warning error -Werror
    // ¯\_(ツ)_/¯

    char s_path_or_filename[MAX_FILENAME_LENGTH];
    s_path_or_filename[0] = '.';

    for (int n_i = 0; n_i < argc; ++n_i)
    {   
        // strcmp returns 0 if equal
        if(strcmp(argv[n_i], "-F") == 0){
            b_add_indicator = 1;
            continue;
        }

        if(strcmp(argv[n_i], "-1") == 0){
            b_one_file_per_line = 1;
            continue;
        }

        if(n_i == 0){ 
            continue;
        }

        //printf("test");
        // argument was not -F nor -1 and is treated as file or path
        //s_path_or_filename = argv[n_i];
        strcpy(s_path_or_filename, argv[n_i]);

    }
    
    // printf("%s", s_path_or_filename);
    
    if( access( s_path_or_filename, F_OK ) == 0 ) {
        // file exists
        if(get_suffix_char_for_file_detect_filetype(s_path_or_filename) != S_CHAR_DIRECTORY){
            
            if(b_one_file_per_line){
                printf("\n");
            }
            
            printf("%s",s_path_or_filename);

            if(b_add_indicator){
                char s_suffix = get_suffix_char_for_file_detect_filetype(s_path_or_filename); 
                if(s_suffix != S_CHAR_DEFAULT){
                    printf("%c", s_suffix);
                }
            }

            return 0;
        }

    } else {
        // file doesn't exist
        printf("no such file or directory  %s", s_path_or_filename); 
        return(0);
    }

    int s_path_or_filename_length = strlen(s_path_or_filename);
    char s_path_or_filename_last_char = s_path_or_filename[s_path_or_filename_length-1];
    //print_chars_of_string(s_path_or_filename);  
    char * s_path;
    if(s_path_or_filename_last_char != '/'){
        s_path = merge_strings(s_path_or_filename, "/");
    }else{
        s_path = s_path_or_filename;
    }

    // print_chars_of_string(s_path);

    

    DIR *d;
    struct dirent *dir;
    d = opendir(s_path);
    int n_items_length = 0;

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if(s_is_hidden_file(dir->d_name)){
                continue;
            }

            n_items_length ++;
        }

        closedir(d);
    }
    //printf("NITEMSLEN%i", n_items_length);
    char a_items[n_items_length][MAX_FILENAME_LENGTH*2+1];
    char a_item_string[MAX_FILENAME_LENGTH*2];

    d = opendir(s_path);
    char tmp_string[MAX_FILENAME_LENGTH];
    char * s_full_path_filename;
    int n_counter = 0; 

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if(s_is_hidden_file(dir->d_name)){
                continue;
            }
            if(!b_we_have_to_sort_aswell){

                strcpy(tmp_string, s_path);

                s_full_path_filename = merge_strings(tmp_string, dir->d_name);
                // print_chars_of_string(s_full_path_filename);
                //printf("\n%s", s_full_path_filename);

                if(n_counter > 0){

                    if(b_one_file_per_line){
                        printf("\n");
                    }else{
                            printf(" ");
                    }
                }
                
                printf("%s",dir->d_name);

                if(b_add_indicator){
                    char s_suffix = get_suffix_char_for_file_detect_filetype(s_full_path_filename); 
                    if(s_suffix != S_CHAR_DEFAULT){
                        printf("%c", s_suffix);
                        sprintf(a_item_string, "%s%c", dir->d_name, s_suffix);
                    }else{
                        sprintf(a_item_string, "%s", dir->d_name);
                    }
                }
            }
            n_counter++;
            strcpy(a_items[n_counter], a_item_string);
        }

        closedir(d);
    }

    for(int i = 0; i < n_items_length; i++){
        printf("\n%s", a_items[i]);
    }
    if(!b_we_have_to_sort_aswell){
        return 0;
    }

    // d = opendir(s_path);
    // char a_items[n_items_length][MAX_FILENAME_LENGTH];
    // if (d) {

    //     int n_c = 0;
    //     while ((dir = readdir(d)) != NULL) {
    //         if(s_is_hidden_file(dir->d_name)){
    //             continue;
    //         }
    //         n_c++;
            
    //         strcpy(a_items[n_c], dir->d_name); 
    //         // a_items[n_c] = dir->d_name;
    //     }
    // }
    // //use bubble sort to sort the array alphabetically 

    //   //Sort array using the Buuble Sort algorithm
    // char s_tmp[MAX_FILENAME_LENGTH];

    // for(int i=0; i<n_items_length; i++){
    //     for(int j=0; j<n_items_length-1-i; j++){
    //         if(strcmp(a_items[j], a_items[j+1]) > 0){
    //             //swap a_items[j] and a_items[j+1]
    //             strcpy(s_tmp, a_items[j]);
    //             strcpy(a_items[j], a_items[j+1]);
    //             strcpy(a_items[j+1], s_tmp);
    //         }
    //     }
    // }

    // char s_item_separator[] = "  ";
    // char s_file_type_indicator = "";
    // char s_prefix_path = s_argument_path; 

    // // if(s_argument_path[strlen(s_argument_path)-1] != '/'){
    // //     char starting_string[] = s_argument_path;
    // //     char ending_string[] = "/";
    // //     strcat(ending_string,starting_string);
    // //     s_prefix_path[] = starting_string;
    // // }

    // for(int i = 0; i < n_items_length; i++){

    //     // char s_prefix_path_copy[] = s_prefix_path;
    //     // strcat(a_items[i], s_prefix_path_copy);
    //     // char s_full_path[] =  s_prefix_path_copy;
    //     // printf("%s", s_item_separator);

    //     if(b_add_indicator){
    //         printf("filepath %s", a_items[i]);
    //         //get_indicator(a_items[i], n_items_length);
    //     }

    //     printf("%s", a_items[i]);


    //     if(b_one_file_per_line){
    //         strcpy(s_item_separator, "\n");
    //     }else{
    //         strcpy(s_item_separator, "  ");
    //     }
        
    // }



    return(0);
}