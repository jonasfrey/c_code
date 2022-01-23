#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file_types(char file_name[]){ 

   printf("\nfilename is : %s", file_name);
   
   struct stat buf;
   int x;
   x = stat (file_name, &buf);
   if (S_ISLNK(buf.st_mode)) printf (" \n stat says link\n");
   if (S_ISREG(buf.st_mode)) printf (" \n stat says file\n");
   x = lstat (file_name, &buf);
   if (S_ISLNK(buf.st_mode)) printf ("\n lstat says link\n");
   if (S_ISREG(buf.st_mode)) printf ("\n lstat says file\n");


   if (stat(file_name, &buf) == 0 && buf.st_mode & S_IXUSR) 
      /* executable */
   else  
      /* non-executable */

   switch (buf.st_mode & S_IFMT) {
     case S_IFBLK:  printf(" block device\n");            break;
     case S_IFCHR:  printf(" character device\n");        break;
     case S_IFDIR:  printf(" directory\n");               break;
     case S_IFIFO:  printf(" FIFO/pipe\n");               break;
     case S_IFLNK:  printf(" symlink\n");                 break;
     case S_IFREG:  printf(" regular file\n");            break;
     case S_IFSOCK: printf(" socket\n");                  break;
     default:       printf(" unknown?\n");                break;
}

   printf("%i", x);

}
// int main (int argc, char argv[][]) {
// int main (int argc, char* argv[]) {
int main (int argc, char** argv) {

   print_file_types(argv[1]);

    return 0;
}