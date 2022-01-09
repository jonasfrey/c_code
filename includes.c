# include <stdio.h>
// this include <...> searches in the standard locations 
// such as  /usr/include, /usr/local/include

# include "my_file.c"
// include "..." searches in the current folder 


printf("this is the variable from the included file my_file.c, it is called n_from_my_file and its value is : %i", n_from_my_file);


