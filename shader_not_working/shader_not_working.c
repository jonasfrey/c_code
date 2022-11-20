
// c file 
#include <stdio.h>
#include <math.h>

int main() {

   //the original shader which is not working 
   //  float n_time = mod(iTime,1.0);
   //  uint n_max = uint(pow(2.0, 32.0)-1.0);
   //  uint n_current = uint(float(n_max) * n_time);
   //  uint n_2pow8minus1 = uint(pow(2.0,8.0)-1.0);
   //  uint n_r = (n_current) & n_2pow8minus1;
   //  uint n_g = (n_current >> 8 * 1) & n_2pow8minus1;
   //  uint n_b = (n_current >> 8 * 2) & n_2pow8minus1;
   //  uint n_a = (n_current >> 8 * 3) & n_2pow8minus1;
    
   //  float n_r_normalized = float(n_r) / float(n_2pow8minus1);
   //  float n_g_normalized = float(n_g) / float(n_2pow8minus1);
   //  float n_b_normalized = float(n_b) / float(n_2pow8minus1);
   //  float n_a_normalized = float(n_a) / float(n_2pow8minus1);
   //  fragColor = vec4(
   //      1.0,
   //      0.0,
   //      0.0,
   //      1.0
   //  );

   //  float n_time = mod(iTime,1.0);

   float n_time = 0.0;
   while(n_time < 10){
   n_time+=0.001;
   float n_time_mod = fmod(n_time,1.0);
      // printf("n_time_mod: %f\n", n_time_mod);

    unsigned int n_max = (unsigned int) (pow(2.0, 32.0)-1.0);
    unsigned int n_current = (unsigned int)((float)n_max * n_time_mod);
        float n_current_normalized = (float)n_current / (float)(n_max);
   printf("n_current_normalized: %f\n", n_current_normalized);

   //  unsigned int n_2pow8minus1 = (unsigned int)(pow(2.0,8.0)-1.0);
   //  unsigned int n_r = (n_current) & n_2pow8minus1;
   //  unsigned int n_g = (n_current >> (8 * 1)) & n_2pow8minus1;
   //  unsigned int n_b = (n_current >> (8 * 2)) & n_2pow8minus1;
   //  unsigned int n_a = (n_current >> (8 * 3)) & n_2pow8minus1;
    
   //  float n_r_normalized = (float)(n_r) / (float)(n_2pow8minus1);
   //  float n_g_normalized = (float)(n_g) / (float)(n_2pow8minus1);
   //  float n_b_normalized = (float)(n_b) / (float)(n_2pow8minus1);
   //  float n_a_normalized = (float)(n_a) / (float)(n_2pow8minus1);
   //    printf("n_current: %u, ", n_current);
   //    printf("n_r: %u, ", n_r);
   //    printf("n_g: %u, ", n_g);
   //    printf("n_b: %u, ", n_b);
   //    printf("n_a: %u, ", n_a);

   //    printf("n_r_normalized: %f, ", n_r_normalized);
   //    printf("n_g_normalized: %f, ", n_g_normalized);
   //    printf("n_b_normalized: %f, ", n_r_normalized);
   //    printf("n_a_normalized: %f, ", n_r_normalized);
   //    printf("\n");
   }

}
