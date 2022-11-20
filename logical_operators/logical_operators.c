#include <stdio.h>

int main()
{

    int a = 1; 
    int b = 0; 
    int c = 0; 
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("a && b || c: %d\n", a && b || c); 
    printf("a || b && c: %d\n", a || b && c); 
    return 0;
}

// if warnings are on, c compiler will throw the following warning
// logical_operators.c:9:17: error: suggest parentheses around ‘&&’ within ‘||’ [-Werror=parentheses]
   //  9 |     int res = a && b || c;