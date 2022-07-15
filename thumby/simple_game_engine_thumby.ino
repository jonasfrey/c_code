
// c file 
#include <cstring>
#include <Thumby.h>

#include <vector>
#include <string>
#include <unistd.h>


Thumby thumby = Thumby();
char sendBuf[7] = "Hello!";
uint8_t dataBuf[7];
uint8_t packedBuf[10];

int n_button_left = 0b00000001;
int n_button_right = 0b00000010;
int n_button_up = 0b00000100;
int n_button_down = 0b00001000;
int n_button_b = 0b00010000;
int n_button_a = 0b00100000;

char s_key_pressed[] = "";

class O_point_2d{
   public: 
      double n_x = 0; 
      double n_y = 0;
};
class O_spatialproperty{
   public: 
      O_point_2d o_current; 
      O_point_2d o_velocity; 
      O_point_2d o_acceleration;

      void f_calculate(){
         o_velocity.n_x += o_acceleration.n_x;
         o_velocity.n_y += o_acceleration.n_y;

         o_current.n_x += o_velocity.n_x;
         o_current.n_y += o_velocity.n_y;
      }
};

class O_object_2d{
   public: 
      O_spatialproperty o_translation;
      O_spatialproperty o_rotation;
      O_spatialproperty o_scale;
};

class O_collision_object; 
class O_game_object{
   public: 
      String s_name;
      std::vector< O_object_2d > a_o_object_2d;
      // void f_render_function(){
      //    std::cout << "Hello World!";
      // }
      void (*f_render_function)( 
         O_game_object * o_game_object
         );
      void (*f_collision_function)(
         O_game_object * o_game_object,
         std::vector< O_collision_object > *a_o_collision_object, 
         std::vector< O_game_object > *a_o_game_object
         );
};
class O_collision_object {
   public: 
      O_game_object o_game_object; 
      O_object_2d o_object_2d;
};

std::vector< O_game_object > a_o_game_object;

class O_grid{
   public:
      int n_scale_x = 1;
      int n_scale_y = 1;
      int n_pixel_width = 1;
      int n_pixel_height = 1;
      int n_a_n_size = 1;
      int* a_n = new int[n_a_n_size];


      int* f_a_n(){
         int n_size_old = sizeof(a_n) / sizeof(a_n[0]);
         size_t n_size = n_pixel_width * n_pixel_height;
         // std::cout << "n_a_n_size: " << n_a_n_size;
         // std::cout << "n_size: " << n_size;
         
         // exit(1);
         if(n_a_n_size != n_size){
            int* a_n_new = new int[n_size];

            memcpy( a_n_new, a_n, n_size * sizeof(int) );

            n_a_n_size = n_size;
            // size = n_size;
            // delete [] a_n;
            // arr = newArr;
            delete [] a_n;
            a_n = a_n_new;
         }
         return a_n;
      }
      void f_clear(){
         a_n = f_a_n();
         int n_i = 0; 
         while(n_i < n_pixel_width * n_pixel_height){
            a_n[n_i] = 0;
            n_i+=1;
         }
      }
    //   int* f_a_xy_by_index(int n_index){
    //      int n_y = (int)((float)n_index / (float)n_pixel_width);
    //      int n_x = n_index % n_pixel_width;
    //      int a_n_xy[2] = {n_x, n_y};
    //      return a_n_xy;
    //   }
      int f_n_index_by_xy(
         int n_x,
         int n_y
      ){
         int n_index = n_y * n_pixel_width + n_x; 
         return n_index;
      }
      void f_set_cell(
         int n_x_original, 
         int n_y_original, 
         int n
      ){
         if(
            (
               n_x_original > n_pixel_width
               ||
               n_x_original < 0
               ||
               n_y_original > n_pixel_height
               ||
               n_y_original < 0
            ) == false
         ){
            int n_x = ((int)n_scale_x) * ((int)n_x_original);
            int n_y = ((int)n_scale_y) * ((int)n_y_original);
            int n_y_2 = 0; 
            while(n_y_2 < n_scale_y){
                  int n_x_2 = 0; 
                  while(n_x_2 < n_scale_x){
                     int n_index = f_n_index_by_xy(n_x+n_x_2,n_y+n_y_2);
                     a_n[n_index] = n;
                     n_x_2+=1;
                  }
                  n_y_2+=1;
            }
         }

      }

      void f_render(){
        int n_i = 0; 
        while(n_i < n_pixel_height * n_pixel_width){
            // int a_xy[] = f_a_xy_by_index(n_i);
            int n_x = n_i % n_pixel_width; 
            int n_y = (int) (double) n_i / (double) n_pixel_width;

            thumby.goTo(n_x, n_y); 
            thumby.writePixel(1);

        }
      }
};

class O_snake : public O_game_object {
char s_name[100] = "snake";
   public:
      void f_render_function() {

      }
};


void f_render_function_o_snake(
   O_game_object * o_snake
){
   double n_velocity = 1.0;
   
   // std::cout << "\r\n";
   // std::cout << o_snake->a_o_object_2d[0].o_translation.o_current.n_x;
   // std::cout << "|";
   // std::cout << o_snake->a_o_object_2d[0].o_translation.o_current.n_y;
   // std::cout << "\r\n";
   // exit(0);

   if(thumby.isPressed(n_button_up)){

      o_snake->a_o_object_2d[0].o_translation.o_velocity.n_x = 0;
      o_snake->a_o_object_2d[0].o_translation.o_velocity.n_y = -n_velocity;
   }

   if(thumby.isPressed(n_button_left)){

      o_snake->a_o_object_2d[0].o_translation.o_velocity.n_x = -n_velocity;
      o_snake->a_o_object_2d[0].o_translation.o_velocity.n_y = 0;
   }

   if(thumby.isPressed(n_button_down)){

      o_snake->a_o_object_2d[0].o_translation.o_velocity.n_x = 0;
      o_snake->a_o_object_2d[0].o_translation.o_velocity.n_y = n_velocity;
   }

   if(thumby.isPressed(n_button_right)){

      o_snake->a_o_object_2d[0].o_translation.o_velocity.n_x = n_velocity;
      o_snake->a_o_object_2d[0].o_translation.o_velocity.n_y = 0;
   }

//    if(thumby.isPressed(n_button_a)){
//          O_object_2d o_object_2d; 
//          o_snake->a_o_object_2d.push_back(o_object_2d);
//    }

   int n_i_reversed = o_snake->a_o_object_2d.size() -1;
   while(n_i_reversed > 0){
         if(n_i_reversed > 0){

            o_snake->a_o_object_2d[n_i_reversed].o_translation.o_current.n_x = o_snake->a_o_object_2d[n_i_reversed-1].o_translation.o_current.n_x;
            o_snake->a_o_object_2d[n_i_reversed].o_translation.o_current.n_y = o_snake->a_o_object_2d[n_i_reversed-1].o_translation.o_current.n_y;
         
         }
         n_i_reversed-=1;
   }
};
void f_collision_function_o_snake(
   O_game_object * o_snake,
   std::vector< O_collision_object > *a_o_collision_object,
   std::vector< O_game_object > *a_o_game_object
   ){
      // exit(1);
      // std::cout << "collision happened !";
      for (auto & o_collision_object : *a_o_collision_object) {
         if(o_collision_object.o_game_object.s_name == "food"){
            // std::cout << "collision happened !";

            O_object_2d o_object_2d; 
            o_snake->a_o_object_2d.push_back(o_object_2d);
         }
      }
};
void f_render_function_o_food(
   O_game_object * o_game_object
   ){
}
// void f_collision_function_o_food(
//    O_game_object * o_game_object,
//    std::vector< O_collision_object > *a_o_collision_object, 
//    std::vector< O_game_object > *a_o_game_object
//    ){
//       int n_index = 0; 
//       for (auto & o_game_object2 : *a_o_game_object) {
//          if(&o_game_object2 == o_game_object){
//             a_o_game_object->erase(a_o_game_object->begin() + n_index);
//          }
//          n_index+=1;

//       }


//       //o food
//       O_game_object o_food;
//       o_food.s_name = "food";
//       O_object_2d o_object_2d_food; 
//       double n_random_normalized = ((double) rand() / (RAND_MAX)) + 1;
//       o_object_2d_food.o_translation.o_current.n_x = (int) (n_random_normalized * 10);
//       o_object_2d_food.o_translation.o_current.n_y = (int) (n_random_normalized * 10);
//       o_food.a_o_object_2d.push_back(o_object_2d_food);
//       o_food.f_render_function = &f_render_function_o_food;
//       o_food.f_collision_function = &f_collision_function_o_food;
//       a_o_game_object->push_back(o_food);

// }




    O_grid o_grid;


void setup() {

o_grid.n_pixel_height = 72; 
o_grid.n_pixel_width = 40; 

// O_snake o_snake;
O_game_object o_snake;
o_snake.s_name = "snake";
O_object_2d o_object_2d; 
o_object_2d.o_translation.o_current.n_x = 1;
o_object_2d.o_translation.o_current.n_y = 1;
o_object_2d.o_translation.o_velocity.n_x = 1;
o_object_2d.o_translation.o_velocity.n_y = 1;
o_snake.a_o_object_2d.push_back(o_object_2d);
o_snake.f_render_function = &f_render_function_o_snake;
// o_snake.f_collision_function = &f_collision_function_o_snake;
a_o_game_object.push_back(o_snake);

// //o food
// O_game_object o_food;
// o_food.s_name = "food";
// O_object_2d o_object_2d_food; 
// o_object_2d_food.o_translation.o_current.n_x = 0;
// o_object_2d_food.o_translation.o_current.n_y = 0;
// o_food.a_o_object_2d.push_back(o_object_2d_food);
// o_food.f_render_function = &f_render_function_o_food;
// o_food.f_collision_function = &f_collision_function_o_food;
// a_o_game_object.push_back(o_food);
  // Sets up buttons, audio, link pins, and screen
  thumby.begin();

  // Init duplex UART for Thumby to PC comms
  Serial.begin(115200);

  // Make sure RX buffer is empty
//   removeRxBytes();
}





void loop() {
  // Clear the screen to black
  thumby.clear();


    o_grid.f_clear();

    for (auto & o_game_object : a_o_game_object) {
        // std::cout << o_game_object.s_name;
        o_game_object.f_render_function(&o_game_object);
        for (auto & o_object_2d : o_game_object.a_o_object_2d) {
        o_object_2d.o_translation.f_calculate();
        o_object_2d.o_rotation.f_calculate();
        o_object_2d.o_scale.f_calculate();
        o_grid.f_set_cell(
            o_object_2d.o_translation.o_current.n_x,
            o_object_2d.o_translation.o_current.n_y, 
            1
        );
        // std::cout << o_object_2d.o_translation.o_current.n_x;
        }

    }

    // std::vector<std::vector< O_collision_object >> a_o_collision_object;
    // std::vector< O_collision_object > a_o_collision_object;

    for (auto & o_game_object : a_o_game_object) {
        std::vector< O_collision_object > a_o_collision_object;
        O_collision_object o_collision_object; 
        o_collision_object.o_game_object = o_game_object; 

        for (auto & o_object_2d : o_game_object.a_o_object_2d) {
        
        for (auto & o_game_object2 : a_o_game_object) {

            if(&o_game_object == &o_game_object2){
                continue;
            }

            for (auto & o_object_2d2 : o_game_object2.a_o_object_2d) {
                if(
                    (int) o_object_2d.o_translation.o_current.n_x == (int) o_object_2d2.o_translation.o_current.n_x 
                    &&
                    (int) o_object_2d.o_translation.o_current.n_y == (int) o_object_2d2.o_translation.o_current.n_y
                ){

                    o_collision_object.o_object_2d = o_object_2d;
                    a_o_collision_object.push_back(
                    o_collision_object
                    );
                    O_collision_object o_collision_object; 
                    o_collision_object.o_game_object = o_game_object2;
                    o_collision_object.o_object_2d = o_object_2d2;
                    a_o_collision_object.push_back(
                    o_collision_object
                    );
                }
            }
        }
        }

        if(a_o_collision_object.size() > 1){
        o_game_object.f_collision_function(
            &o_game_object, 
            &a_o_collision_object,
            &a_o_game_object 
        );
        }

    }


    o_grid.f_render();
    // usleep(1000);
    
  // Receive and display a message from link
//   receive();

  // Update the screen
  thumby.writeBuffer(thumby.getBuffer(), thumby.getBufferSize());
}
