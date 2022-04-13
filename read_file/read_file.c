
// c file 
#include <stdio.h>

#define S_ANSI_COLOR_RED     "\x1b[31m"
#define S_ANSI_COLOR_GREEN   "\x1b[32m"
#define S_ANSI_COLOR_YELLOW  "\x1b[33m"
#define S_ANSI_COLOR_BLUE    "\x1b[34m"
#define S_ANSI_COLOR_MAGENTA "\x1b[35m"
#define S_ANSI_COLOR_CYAN    "\x1b[36m"
#define S_ANSI_COLOR_RESET   "\x1b[0m"


typedef unsigned int my_fancy_own_data_type;

int main() {

   char * s_filename = "./i_am_text";
   char * s_fopen_mode_read_binary = "rb";
   // FILE is just a typedef
   // like my_fancy_own_data_type
   my_fancy_own_data_type n_num = 18;
   FILE * s_fopen_stream = fopen(
      s_filename,
      s_fopen_mode_read_binary
   );

   if(s_fopen_stream == NULL){
      printf(S_ANSI_COLOR_RED "file open failure!\n" S_ANSI_COLOR_RESET);
   }else{
      printf(S_ANSI_COLOR_GREEN "file open success!\n" S_ANSI_COLOR_RESET);
   }
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_IO_read_ptr:" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_IO_read_ptr);
   printf(S_ANSI_COLOR_MAGENTA "s_fopen_stream->_IO_read_base:" S_ANSI_COLOR_RESET "%p\n"  ,s_fopen_stream->_IO_read_base);

   // printf("%i", s_fopen_stream[0]);

}
