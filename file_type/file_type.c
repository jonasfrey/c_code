#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "./../c_helpers/dnd.c"
#define S_CHAR_SYMLINK  '@'
#define S_CHAR_DIRECTORY  '/'
#define S_CHAR_EXECUTABLE '*'
#define S_CHAR_DEFAULT ' '


char get_suffix_char_for_file_detect_filetype(char* file_name){ 

   struct stat path_stat;
   
   dnds(file_name);

   struct stat buf;
   int x;

   x = lstat (file_name, &buf);
   
   if(x){
      x = x;
   }

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

// int main (int argc, char argv[][]) {
// int main (int argc, char* argv[]) {
int main (int argc, char** argv) {

   // char s_file_type = get_suffix_char_for_file_detect_filetype(argv[1]);
   char s_test; 

   s_test = get_suffix_char_for_file_detect_filetype("./script.sh");
   dndc(s_test);

   s_test = get_suffix_char_for_file_detect_filetype("./test_dir");
   dndc(s_test);

   // get_suffix_char_for_file_detect_filetype("./hello.sh "); // not working because of to long string!
   s_test = get_suffix_char_for_file_detect_filetype("./hello.sh"); 
   dndc(s_test);

   //get_suffix_char_for_file_detect_filetype("./symlink_to_hello.sh "); // not working because string to long
   s_test = get_suffix_char_for_file_detect_filetype("./test.txt");
   dndc(s_test);

   s_test = get_suffix_char_for_file_detect_filetype("./file_type");
   dndc(s_test);

   s_test = get_suffix_char_for_file_detect_filetype("./symlink_to_hello.sh"); 
   dndc(s_test);


   return 0;
}