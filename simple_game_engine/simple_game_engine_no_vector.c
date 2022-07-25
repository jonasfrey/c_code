
// c file 
#include <stdio.h>
// #include <iostream>
// #include <cstring>
// #include <string>
#include <unistd.h>
// #include <chrono>
// #include <thread>
#include <curses.h>

// int n_i;

#define fp_create_dynamic_array_typedef_struct(s_typename_array, s_varname_array, s_typename_element, s_varname_element) \
typedef struct s_typename_array{\
   size_t n_capacity;\
   size_t n_length;\
   s_typename_element * a;\
} s_typename_array;

#define fp_create_dynamic_array_f_init(s_typename_array, s_varname_array, s_typename_element, s_varname_element) \
void f_init_##s_varname_array(\
   s_typename_array * s_varname_array\
){\
   s_varname_array->n_capacity = 0;\
   s_varname_array->n_length = 0;\
   s_varname_array->a = malloc(s_varname_array->n_capacity * sizeof(s_typename_element));\
}

#define fp_create_dynamic_array_f_insertafterindex(s_typename_array, s_varname_array, s_typename_element, s_varname_element) \
void f_insertafterindex_##s_varname_array(\
   s_typename_array * s_varname_array,\
   s_typename_element s_varname_element,\
   size_t n_index\
){\
   s_varname_array->n_capacity +=1;\
   s_varname_array->n_length +=1;\
   s_varname_array->a = realloc(s_varname_array->a, s_varname_array->n_length * sizeof(s_typename_element));\
   int n_i_reversed = s_varname_array->n_length -1;\
   while(n_i_reversed > n_index){\
      s_varname_array->a[n_i_reversed] = s_varname_array->a[n_i_reversed-1];\
      n_i_reversed-=1;\
   }\
   s_varname_array->a[n_index] = s_varname_element;\
}

#define fp_create_dynamic_array_f_push(s_typename_array, s_varname_array, s_typename_element, s_varname_element) \
void f_push_ ##s_varname_array(\
   s_typename_array * s_varname_array,\
   s_typename_element s_var_name_element\
){\
   f_insertafterindex_ ##s_varname_array(s_varname_array, s_var_name_element, s_varname_array->n_length);\
}

#define fp_create_dynamic_array_f_insertbeforeindex(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
void f_insertbeforeindex_a_o_person(\
   s_typename_array * s_varname_array,\
   s_typename_element s_var_name_element,\
   size_t n_index\
){\
   f_insertafterindex_ ##s_varname_array(s_varname_array, s_var_name_element, n_index-1);\
}

#define fp_create_dynamic_array_f_remove_by_index(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
void f_remove_by_index_##s_varname_array(\
   s_typename_array * s_varname_array,\
   int n_index\
){\
   while(n_index < s_varname_array->n_length){\
      n_index+=1;\
      s_varname_array->a[n_index-1] = s_varname_array->a[n_index];\
   }\
   s_varname_array->n_capacity -=1;\
   s_varname_array->n_length -=1;\
   s_varname_array->a = realloc(s_varname_array->a, s_varname_array->n_length * sizeof(s_typename_element));\
}

#define fp_create_dynamic_array_f_n_index(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
int f_n_index_##s_varname_array(\
   s_typename_array * s_varname_array,\
   s_typename_element * s_varname_element\
){\
   int n_i = 0;\
   int n_index = -1;\
   while(n_i < s_varname_array->n_length){\
      int n = memcmp(&s_varname_array->a[n_i], s_varname_element, sizeof(s_typename_element));\
      if(n == 0){\
         n_index = n_i;\
         break;\
      }\
      n_i+=1;\
   }\
   return n_index;\
}
#define fp_create_dynamic_array_f_shift(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
void f_shift_##s_varname_array(\
   s_typename_array * s_varname_array\
){\
   f_remove_by_index_##s_varname_array(s_varname_array, 0);\
}
#define fp_create_dynamic_array_f_pop(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
void f_pop_##s_varname_array(\
   s_typename_array * s_varname_array\
){\
   f_remove_by_index_##s_varname_array(s_varname_array, s_varname_array->n_length-1);\
}
#define fp_create_dynamic_array_f_free(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
void f_free_##s_varname_array(\
   s_typename_array * s_varname_array\
){\
   free(s_varname_array->a);\
   s_varname_array->a = NULL;\
   s_varname_array->n_capacity = 0;\
   s_varname_array->n_length = 0;\
}

#define fp_create_dynamic_array(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_typedef_struct(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_init(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_insertafterindex(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_push(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_insertbeforeindex(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_remove_by_index(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_n_index(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_shift(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_pop(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\
   fp_create_dynamic_array_f_free(s_typename_array, s_varname_array, s_typename_element, s_varname_element)\


// int n_key_pressed;

typedef struct O_point_2d{
   double n_x; 
   double n_y;
} O_point_2d;

// typedef struct O_spatialproperty{
//    O_point_2d o_current; 
//    O_point_2d o_velocity; 
//    O_point_2d o_acceleration;
// } O_spatialproperty;

// void f_calculate_o_spatial_property(O_spatialproperty * o){
//    o->o_velocity.n_x += o->o_acceleration.n_x;
//    o->o_velocity.n_y += o->o_acceleration.n_y;

//    o->o_current.n_x += o->o_velocity.n_x;
//    o->o_current.n_y += o->o_velocity.n_y;
// }

// typedef struct O_object_2d{
//    O_spatialproperty o_translation;
//    O_spatialproperty o_rotation;
//    O_spatialproperty o_scale;
// } O_object_2d;

void f_test(){
   fp_create_dynamic_array(A_o_point_2d, a_o_point_2d, O_point_2d, o_point_2d);
   A_o_point_2d a_o_point_2d;
   O_point_2d o_point_2d; 
}

int main(){
   printf("astr");
   f_test();

   return 1;
}
// typedef struct O_game_object{
   
//    char s_name[100];
//    A_o_object_2d * a_o_object_2d;
//    // std::vector< O_object_2d > a_o_object_2d;
//    // void f_render_function(){
//    //    std::cout << "Hello World!";
//    // }
//    void (*f_render_function)(O_game_object * o_game_object);
// } O_game_object;

// fp_create_dynamic_array(A_o_game_object, a_o_game_object, O_game_object, o_game_object);


// class O_grid{
//    public:
//       int n_scale_x = 1;
//       int n_scale_y = 1;
//       int n_pixel_width = 1;
//       int n_pixel_height = 1;
//       int n_a_n_size = 1;
//       int* a_n = new int[n_a_n_size];


//       int* f_a_n(){
//          int n_size_old = sizeof(a_n) / sizeof(a_n[0]);
//          size_t n_size = n_pixel_width * n_pixel_height;
//          // std::cout << "n_a_n_size: " << n_a_n_size;
//          // std::cout << "n_size: " << n_size;
         
//          // exit(1);
//          if(n_a_n_size != n_size){
//             int* a_n_new = new int[n_size];

//             memcpy( a_n_new, a_n, n_size * sizeof(int) );

//             n_a_n_size = n_size;
//             // size = n_size;
//             // delete [] a_n;
//             // arr = newArr;
//             delete [] a_n;
//             a_n = a_n_new;
//          }
//          return a_n;
//       }
//       void f_clear(){
//          a_n = f_a_n();
//          int n_i = 0; 
//          while(n_i < n_pixel_width * n_pixel_height){
//             a_n[n_i] = 0;
//             n_i+=1;
//          }
//       }
//       int* f_a_xy_by_index(int n_index){
//          int n_y = (int)((float)n_index / (float)n_pixel_width);
//          int n_x = n_index % n_pixel_width;
//          int a_n_xy[2] = {n_x, n_y};
//          return a_n_xy;
//       }
//       int f_n_index_by_xy(
//          int n_x,
//          int n_y
//       ){
//          int n_index = n_y * n_pixel_width + n_x; 
//          return n_index;
//       }
//       void f_set_cell(
//          int n_x_original, 
//          int n_y_original, 
//          int n
//       ){
//         int n_x = ((int)n_scale_x) * ((int)n_x_original);
//         int n_y = ((int)n_scale_y) * ((int)n_y_original);
//         int n_y_2 = 0; 
//         while(n_y_2 < n_scale_y){
//             int n_x_2 = 0; 
//             while(n_x_2 < n_scale_x){
//                int n_index = f_n_index_by_xy(n_x+n_x_2,n_y+n_y_2);
//                a_n[n_index] = n;
//                n_x_2+=1;
//             }
//             n_y_2+=1;
//         }

//       }

//       void f_render(){
//          int n_i = 0; 
//          while(n_i < n_pixel_height * n_pixel_width){
//             if(n_i % n_pixel_width == 0){
//                // std::cout << "\n";
//                printf("\r\n"); // \r\n is important for curses
//             }
//             int n = a_n[n_i]; 
//             if(n == 0){
//                // std::cout << "-";
//                printf("-");
//             }else{
//                // std::cout << "x";
//                printf("x");
//             }
//             n_i++;
//          }
//          // std::cout << "" << std::flush;
//       }
// };


// void f_render_function_o_snake(
//    O_game_object * o_snake
// ){
//    double n_velocity = 1.0;
//    char s_key_pressed = (char) n_key_pressed;

//    if(s_key_pressed == 'w'){

//       o_snake->a_o_object_2d[0].o_translation.o_velocity.n_x = 0;
//       o_snake->a_o_object_2d[0].o_translation.o_velocity.n_y = -n_velocity;
//    }

//    if(s_key_pressed == 'a'){

//       o_snake->a_o_object_2d[0].o_translation.o_velocity.n_x = -n_velocity;
//       o_snake->a_o_object_2d[0].o_translation.o_velocity.n_y = 0;
//    }

//    if(s_key_pressed == 's'){

//       o_snake->a_o_object_2d[0].o_translation.o_velocity.n_x = 0;
//       o_snake->a_o_object_2d[0].o_translation.o_velocity.n_y = n_velocity;
//    }

//    if(s_key_pressed == 'd'){

//       o_snake->a_o_object_2d[0].o_translation.o_velocity.n_x = n_velocity;
//       o_snake->a_o_object_2d[0].o_translation.o_velocity.n_y = 0;
//    }

//    if(s_key_pressed == 'e'){
//          O_object_2d o_object_2d; 
//          f_push_a_o_game_object(o_snake->a_o_object_2d, o_object_2d);
//          // o_snake->a_o_object_2d.push_back(o_object_2d);
//    }

//    int n_i_reversed = o_snake->a_o_object_2d.size() -1;
//    while(n_i_reversed > 0){
//          if(n_i_reversed > 0){

//             o_snake->a_o_object_2d[n_i_reversed].o_translation.o_current.n_x = o_snake->a_o_object_2d[n_i_reversed-1].o_translation.o_current.n_x;
//             o_snake->a_o_object_2d[n_i_reversed].o_translation.o_current.n_y = o_snake->a_o_object_2d[n_i_reversed-1].o_translation.o_current.n_y;
         
//          }
//          n_i_reversed-=1;
//    }
// }

// int main() {
//    A_o_game_object a_o_game_object;
//    f_init_a_o_game_object(&a_o_game_object);
//    O_game_object o_game_object;
//    O_object_2d o_object_2d;

//    // start detect keypress
//    initscr ();
//    noecho ();
//    timeout (0);

//    // end detect keypress 

//    // O_game_object o_game_object;
//    O_grid o_grid;

//    o_grid.n_pixel_height = 40; 
//    o_grid.n_pixel_width = 40; 

//    // O_snake o_snake;
//    O_game_object o_snake;
//    // o_snake.s_name = "snake";
//    strcpy(o_snake.s_name, "snake");
//    O_object_2d o_object_2d; 
//    o_object_2d.o_translation.o_current.n_x = 1;
//    o_object_2d.o_translation.o_current.n_y = 1;
//    o_object_2d.o_translation.o_velocity.n_x = 1;
//    o_object_2d.o_translation.o_velocity.n_y = 1;
//    f_push_a_o_object_2d(o_snake.a_o_object_2d, o_object_2d);
//    // o_snake.a_o_object_2d.push_back(o_object_2d);

//    o_snake.f_render_function = &f_render_function_o_snake;

//    f_push_a_o_game_object(&a_o_game_object, o_snake);
//    // a_o_game_object.push_back(o_snake);


//    while(1){
//       n_key_pressed = getch ();
//       if (n_key_pressed != ERR)
//       {
//       //   printw ("%c", n_key_pressed);
//       }
//       if (n_key_pressed == 27) // escape
//       {
//         break;
//       }

//       o_grid.f_clear();
//       n_i = 0; 
//       while(n_i < a_o_game_object.n_length){
//          o_game_object = a_o_game_object.a[n_i];
//          o_game_object.f_render_function(&o_game_object);

//          int n_i2 = 0; 
//          while(n_i2 < o_game_object.a_o_object_2d->n_length){
//             o_object_2d = o_game_object.a_o_object_2d->a[n_i2];
//                f_calculate_o_spatial_property(&o_object_2d.o_translation);
//                f_calculate_o_spatial_property(&o_object_2d.o_rotation);
//                f_calculate_o_spatial_property(&o_object_2d.o_scale);

//                o_grid.f_set_cell(
//                   o_object_2d.o_translation.o_current.n_x,
//                   o_object_2d.o_translation.o_current.n_y, 
//                   1
//                );
//             n_i2 +=1;
//          }

//          n_i+=1;
//       }


//       o_grid.f_render();
//       // usleep(1000);
//       std::this_thread::sleep_for(std::chrono::milliseconds(100)); // sleep for 1 second

//    }

//    //start detect keypress
//   echo ();
//   endwin ();
//   //end detect keypress 

//   return 0;
// }


// void f_test_o_grid(){
//    O_grid o_grid;

//    o_grid.n_pixel_height = 10; 
//    o_grid.n_pixel_width = 10; 
//    std::cout << o_grid.n_pixel_height;

//    int n_x = 0; 
//    while(n_x < 10000){
//       n_x+=1;
//       o_grid.f_clear();
//       o_grid.f_set_cell(n_x%10, 0, 1);
//       // o_grid.a_n[n_x%5] = 1; 
//       o_grid.f_render();
//    }


// }
