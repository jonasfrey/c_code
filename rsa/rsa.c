

// c file 
#include <stdio.h>
#include <sodium.h> 
#include <math.h>
#include <time.h>

/*
//install sodium

```bash
wget https://download.libsodium.org/libsodium/releases/libsodium-1.0.18.tar.gz
tar -xf libsodium-1.0.18.tar.gz
cd libsodium-1.0.18
./configure
make && make check
sudo make install
```
or follow this 
https://doc.libsodium.org/installation
*/

#include "./../terminal_color_fun/ansi_color_constants.c"
#include "./../c_helpers/dynamic_array.c"
#include "./../c_helpers/dnd.c"




int random_int_between_exponents(int n_exponent_min, int n_exponent_max){

   char s_random_bytes_string[n_exponent_max];
   
   uint32_t n_random_int;

   if (sodium_init() < 0) {
       /* panic! the library couldn't be initialized, it is not safe to use */
       return 1; 
   }

   /*  will be an array of 32 random bytes, not null-terminated */        
   randombytes_buf(s_random_bytes_string, n_exponent_max);

   /* will be a random number between 2^16 and 2^32 */
   n_random_int = pow(2,n_exponent_min) + randombytes_uniform(pow(2,n_exponent_max));

   return n_random_int;
}

int get_random_16_bit_int(){

   char s_random_bytes_string[32];
   
   uint32_t n_random_int;

   if (sodium_init() < 0) {
       /* panic! the library couldn't be initialized, it is not safe to use */
       return 1; 
   }

   /*  will be an array of 32 random bytes, not null-terminated */        
   randombytes_buf(s_random_bytes_string, 32);

   n_random_int = randombytes_uniform((uint32_t) pow(2.0, 16.0));

   return abs(n_random_int);
}

int get_next_higher_prime(uint32_t n_start){
   
   int is_prime = 0;

   int n_next_prime = 0;

   for(int i = n_start+1; !is_prime; i++){
      is_prime = 1;
      for(int j = 2; j < sqrt((float)i); j++){
         if(i % j == 0){
            is_prime = 0;
            break;
         }
      }

      if(is_prime){
         // printf("\n%i", i);
         n_next_prime = i;
         break;
      }

   }

   return n_next_prime;

}

int get_random_int_between_min_max(uint32_t n_min, uint32_t n_max){

   double n_exponent_max = log((double) n_max)/log((double) n_max);
   int n_exponent_max_ceiled = ceil(n_exponent_max);

   double n_exponent_min = log((double) n_min)/log((double) n_min);
   int n_exponent_min_downceiled = ceil(n_exponent_min) - 1;


   int n_random_int_between_exponents = random_int_between_exponents(n_exponent_min_downceiled, n_exponent_max_ceiled);

   // n_random_int_between_exponents could be smaller than n_min, 
   // todo: prevent it

   return n_random_int_between_exponents;
}

int get_high_prime(){

   //uint32_t n_random_int = get_random_32_bit_int();
   uint32_t n_random_int = get_random_16_bit_int();

   //printf("random int between 2^16 and 2^32 %i", n_random_int);

   uint32_t n_next_prime = get_next_higher_prime(n_random_int);

   //dnd(n_next_prime);

   return n_next_prime;
}


int get_e_by_m(uint32_t m){
   // e has to be a primenumber 
   // but cannot be a teiler of m 
   // e has to be smaller than m
   int b_all_conditions_true = 0;
   int b_is_not_teiler_of_m = 0; 
   int b_is_smaller_than_m = 0;
   uint32_t n_random_int;
   while(!b_all_conditions_true){

      b_is_smaller_than_m = 0; 
      b_is_not_teiler_of_m = 0;

      n_random_int = get_random_16_bit_int();

      b_is_smaller_than_m = (n_random_int < m);

      b_is_not_teiler_of_m = m % n_random_int != 0;

      b_all_conditions_true = b_is_not_teiler_of_m && b_is_smaller_than_m;
   
   }

   return n_random_int;
   
}
int get_d_by_e_and_m(uint32_t e, uint32_t m){
   long d;

   // d cannot have a same primefactor as m
   //extended euler algorhitm

   uint32_t e_mod_m = 1;//1 placeholder
   uint32_t tmp_e = e; 
   uint32_t tmp_m = m; 
   uint32_t int_e_divided_by_m = 0;

   long tmp_a = 0;
   long tmp_b = 0;

   Array a_e;
   Array a_m; 
   Array a_int_e_divided_by_m; 
   Array a_e_mod_m;

   Array a_a; 
   Array a_b; 
         
   initArray(&a_e, 1);
   initArray(&a_m, 1);
   initArray(&a_int_e_divided_by_m, 1);
   initArray(&a_e_mod_m, 1);
   initArray(&a_a, 1);
   initArray(&a_b, 1);
   
   //   for (i = 0; i < 100; i++)
   //     insertArray(&a, i);  // automatically resizes as necessary
   //   printf("%d\n", a.array[9]);  // print 10th element
   //   printf("%d\n", a.used);  // print number of elements
   //   freeArray(&a);

   int n_counter = 0; 
   while(e_mod_m > 0){

      e_mod_m = tmp_e % tmp_m;

      
      int_e_divided_by_m = (int) tmp_e / tmp_m;

      a_e.array[n_counter] = tmp_e;
      a_m.array[n_counter] = tmp_a;
      a_int_e_divided_by_m.array[n_counter] = int_e_divided_by_m;
      a_e_mod_m.array[n_counter] = e_mod_m;

      //used later, filled with 0 for now
      a_a.array[n_counter] = 0;
      a_b.array[n_counter] = 0;

      printf("\n\neuclid algorithm step: %i", n_counter);

      dnd(tmp_e);
      dnd(tmp_m);
      dnd(int_e_divided_by_m);
      dnd(e_mod_m);

      if(e_mod_m > 0){
         tmp_e = tmp_m; 
         tmp_m = e_mod_m;
         
         // wtf i have to take a look at pointers... 
         //'grow' the arrays
         //insertArray(&a_e, 0);
         //insertArray(&a_m, 0);
         //insertArray(&a_int_e_divided_by_m, 0);
         //insertArray(&a_e_mod_m, 0);
         //insertArray(&a_a, 0);
         //insertArray(&a_b, 0);
         
         n_counter++;
      }

   }


   long n_a = 0; 
   long n_b = 1; 
   long last_a = 0; 
   long last_b = 1; 

   for(int i = n_counter; i >= 0; i--){
      dnd(i);
      dnd(a_int_e_divided_by_m.array[i]);
   }
   for(int i = n_counter; i >= 0; i--){

      printf("\n\neuclid algorithm backwards step: %i", i);
      
      if(i == n_counter){
         tmp_a = 0;
         tmp_b = 1;
      }else{
         tmp_a = tmp_b;
         tmp_b = a_a.array[i+1] - (a_int_e_divided_by_m.array[i] * a_b.array[i+1]);
      }
      dnd(a_a.array[i+1]);
      dnd(a_int_e_divided_by_m.array[i]);
      dnd(a_b.array[i+1]);
      a_a.array[i] = tmp_a;
      a_b.array[i] = tmp_b;

      dndli(tmp_a);
      dndli(tmp_b);
   }

   d = tmp_a; 
   if(d < 0){
      d = d + m; 
   }
   dndli(d);

   return d;
}

// int encrypt_message(int n_public_key, char[] s_message){}

int main() {
   /* my first program in C */
   
   uint32_t p = get_high_prime();
   uint32_t q = get_high_prime();
   
   //prevent p == q 
   while(p == q){
      q = get_high_prime();
   }

   dnd(p);
   dnd(q);

   uint32_t n = p * q;

   dnd(n);


   // phi(prime_num) = (prime_num - 1)
   uint32_t m = (p-1) * (q-1);

   dnd(m);

   uint32_t e = get_e_by_m(m);

   dnd(e);
   
   uint32_t d = get_d_by_e_and_m(e, m); 

   // static test numbers 

   //p = 7; 
   //q = 11; 
   //n = 77; 
   //m = 60; 
   //e = 13; 
   //uint32_t d = get_d_by_e_and_m(e, m); //should be 37



   int n_public_key_n = n; 
   int n_public_key_e = e; 

   int n_private_key_n = n; 
   int n_private_key_d = d; 


   printf("\nhere's your key, keep it save!:\n");

   dnd(n_public_key_n);
   dnd(n_public_key_e);

   dnd(n_private_key_n);
   dnd(n_private_key_d);

   return 0;
}
