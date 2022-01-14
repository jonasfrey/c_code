

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

// dump not die
// currently only working for integers
#define dnd(var)\
   printf("\n");\
   print_current_unix_timestamp_formatted();\
   printf(": %s : ", #var);\
   printf("%i", var);\
   printf("\n");

// dump not die
// currently only working for long integers
#define dndli(var)\
   printf("\n");\
   print_current_unix_timestamp_formatted();\
   printf(": %s : ", #var);\
   printf("%li", var);\
   printf("\n");


int get_current_unix_timestamp(){
   //  January 1st, 1970 at UTC
   int n_current_unix_timestamp = (unsigned long)time(NULL);
   return n_current_unix_timestamp;
}

void print_current_unix_timestamp_formatted(){

   // January 1st, 1970 at UTC
   int n_current_unix_timestamp = get_current_unix_timestamp();

   // int n_years = n_current_unix_timestamp / (60.0*60*24*365) + 1970;
   //int n_months = n_current_unix_timestamp / (60.0*60*24*365) + 1970;
   //int n_days = n_current_unix_timestamp / (60.0*60*24) + 1970;

   int n_seconds = (int) n_current_unix_timestamp % 60;
   int n_minutes = (int) n_current_unix_timestamp % (60*60) / (60.0);
   int n_hours = (int) n_current_unix_timestamp % (60*60*24) / (60.0*60);

   //utc +1 or so
   n_hours = (n_hours + 1) % 24;

   // // char s_h_m_s[] = "00:00:00";
   // printf("%05i", n_seconds);
   // printf("%05i", n_minutes);
   // printf("%05i", n_hours);

   // char s_seconds_padded[] = "00";
   // char s_minutes_padded[] = "00";
   // char s_hours_padded[] = "00";

   // sprintf(s_seconds_padded, "%02i", n_seconds);
   // sprintf(s_minutes_padded, "%02i", n_minutes);
   // sprintf(s_hours_padded, "%02i", n_hours);

   // char s_unix_ts_formatted[] = "00:00:00";

   // printf("%s:%s:%s", s_hours_padded, s_minutes_padded, s_seconds_padded);
   printf(ANSI_BG_COLOR_UNSATURATED_BLACK "%i:%i:%i" ANSI_COLOR_RESET, n_hours, n_minutes, n_seconds);

   // printf("%s", s_unix_ts_formatted);
   // return s_unix_ts_formatted;
   //return 1;
}


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
   int d;

   // d cannot have a same primefactor as m
   //extended euler algorhitm
   int e_mod_m = 1;//1 placeholder
   
   uint32_t tmp_e = e; 
   uint32_t tmp_m = m; 
   uint32_t int_e_divided_by_m = 0;
   while(e_mod_m > 0){
      
      e_mod_m = tmp_e % tmp_m;
      int_e_divided_by_m = (int) tmp_e / tmp_m;

      tmp_e = tmp_m; 
      tmp_m = e_mod_m; 
      
   }

   return d;
}
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

   uint32_t d = get_d_by_m(m);
   
   return 0;
}
