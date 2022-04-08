
// c file 
#include <stdio.h>
#include <string.h>

int words(char * str){
   int index = 0; 
   int numofwords = 0;
   int lastwasword = 0;
   printf("stringlenght is %li\n", (sizeof(str)/sizeof(str[0])));
   if(str[0]!='\0'){numofwords++;}
   while(str[index] != '\0'){
      index++; 
      if(
         (str[index] == ','||
         str[index] == ';'||
         str[index] == ' '||
         str[index] == '.')
         && !lastwasword
      ){
         if(index != strlen(str)-1){
            lastwasword=1;
            numofwords++;
         }
      }else{lastwasword=0;}
   }
   return numofwords;
}
int main() {
   char * s1 = "Hello, my dear students";
   char * s2 = "CS-Basics is awesome!";
   printf("%i\n", words(s1));
   printf("%i\n", words(s2));
}
