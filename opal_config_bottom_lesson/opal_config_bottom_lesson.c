int main() {

   // even if you dont include any file, 
   // there are some defined constants available
   // for example __func__ is a char pointer
   // pointing to the first char of the current function name 
   // unfortunatly i wont print it here, because for the demonstration purpose,
   // i dont want to include any library, not even <stdio.h>

   // if(asdf){} // error: ‘asdf’ undeclared (first use in this function)
   // if(__func__){} //  error: the address of ‘__func__’ will always evaluate as ‘true’ [-Werror=address]
   if(__FILE__){}

   return 0;
}
