
// c file
#include <stdio.h>

#define S(X) #X
int main(int argc, char **argv)
{
   printf("%c\n",*S(5));
}