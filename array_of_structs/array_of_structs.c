
// c file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct O_dynamic_struct{
   char * s_dynamic_sized;
   long n_length_s_dynamic_sized; 
   long n_never_used;
};

void f_dynamic_length_array_of_structs(){
   // struct 1 
   struct O_dynamic_struct o_dynamic_struct_1;
   o_dynamic_struct_1.n_length_s_dynamic_sized = 26;
   int n_i = 0; 
   o_dynamic_struct_1.s_dynamic_sized = malloc(o_dynamic_struct_1.n_length_s_dynamic_sized+1);
   while(n_i < o_dynamic_struct_1.n_length_s_dynamic_sized){
      o_dynamic_struct_1.s_dynamic_sized[n_i] = 65+(n_i%26);
      n_i++;
   }
   o_dynamic_struct_1.s_dynamic_sized[n_i+1] = '\0';
   printf("o_dynamic_struct_1.s_dynamic_sized: %s\n", o_dynamic_struct_1.s_dynamic_sized);
   printf("sizeof(o_dynamic_struct_1): %li\n", sizeof(o_dynamic_struct_1));
   printf("sizeof(o_dynamic_struct_1.s_dynamic_sized): %li\n", sizeof(o_dynamic_struct_1.s_dynamic_sized));
   printf("strlen(o_dynamic_struct_1.s_dynamic_sized): %li\n", strlen(o_dynamic_struct_1.s_dynamic_sized));

   struct O_dynamic_struct o_dynamic_struct_2;
   o_dynamic_struct_2.n_length_s_dynamic_sized = 1000;
   n_i = 0; 
   o_dynamic_struct_2.s_dynamic_sized = malloc(o_dynamic_struct_2.n_length_s_dynamic_sized+1);
   while(n_i < o_dynamic_struct_2.n_length_s_dynamic_sized){
      o_dynamic_struct_2.s_dynamic_sized[n_i] = 65+(n_i%26);
      n_i++;
   }
   o_dynamic_struct_2.s_dynamic_sized[n_i+1] = '\0';
   printf("o_dynamic_struct_2.s_dynamic_sized: %s\n", o_dynamic_struct_2.s_dynamic_sized);
   printf("sizeof(o_dynamic_struct_2): %li\n", sizeof(o_dynamic_struct_2));
   printf("sizeof(o_dynamic_struct_2.s_dynamic_sized): %li\n", sizeof(o_dynamic_struct_2.s_dynamic_sized));
   printf("strlen(o_dynamic_struct_2.s_dynamic_sized): %li\n", strlen(o_dynamic_struct_2.s_dynamic_sized));

}
struct O_point_2_d{
   long n_x; 
   long n_y;
};
void f_simple_struct(){
   struct O_point_2_d o_point_2_d;
   o_point_2_d.n_x = 2123; 
   o_point_2_d.n_y = -2;
   printf("o_point_2_d.n_x|o_point_2_d.n_y:%li|%li\n", o_point_2_d.n_x,o_point_2_d.n_y);
}

void f_static_length_array_of_structs(){
   // struct O_point_2_d a_o_point_2_d[3];//Werror=uninitialized
   int n_not_enough = 1;
   // int n_enough = 4*2*6; // why is this already enough?
   int n_enough = 4*2*8;
   // struct O_point_2_d * a_o_point_2_d = malloc(n_not_enough);
   struct O_point_2_d * a_o_point_2_d = malloc(n_enough);

   a_o_point_2_d[0].n_x = 1; 
   a_o_point_2_d[0].n_x = 3;

   a_o_point_2_d[1].n_x = 12; 
   a_o_point_2_d[1].n_x = 55; 
   
   a_o_point_2_d[2].n_x = 23; 
   a_o_point_2_d[2].n_x = -2;

   a_o_point_2_d[3].n_x = 1; 
   a_o_point_2_d[3].n_x = 123412341234123412;
   printf(
      "a_o_point_2_d[0].n_x|a_o_point_2_d[0].n_y:%li|%li\n", 
      a_o_point_2_d[0].n_x,
      a_o_point_2_d[0].n_y
   );

   printf(
      "a_o_point_2_d[1].n_x|a_o_point_2_d[1].n_y:%li|%li\n", 
      a_o_point_2_d[1].n_y,
      a_o_point_2_d[1].n_x
   );

   printf(
      "a_o_point_2_d[2].n_x|a_o_point_2_d[2].n_y:%li|%li\n", 
      a_o_point_2_d[2].n_x,
      a_o_point_2_d[2].n_y
   );
   printf(
      "a_o_point_2_d[3].n_x|a_o_point_2_d[3].n_y:%li|%li\n", 
      a_o_point_2_d[3].n_x,
      a_o_point_2_d[3].n_y
   );


}
int main() {

   // f_simple_struct();
   // f_static_length_array_of_structs();
   f_dynamic_length_array_of_structs();
}
