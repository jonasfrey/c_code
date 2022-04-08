#include <stdlib.h>

#include <SDL2/SDL.h>
#include <time.h>
#include "./../c_helpers/dnd.c"

struct timespec ts;
// int n_width = 500; //holy shit is this fast 
// int n_height = 500; // holy shit is this fast
int n_width = 1000; //holy shit is this fast 
int n_height = 1000; // holy shit is this fast

// heres a js code to compare speed 
// <!DOCTYPE html>
// <html>
//   <body>
//     <body ><canvas id="canvas" width="500" height="500"></canvas></body>
//     <script type='text/javascript' defer>
//       (function() {
//           console.log("asdf");
//           var canvas = document.getElementById('canvas');
//         if (canvas.getContext) {
//           var ctx = canvas.getContext('2d');
//           // while (true) { // we cannot do this
//             var draw = function(){
//               for (var y = 0; y < 500; y++) {
//               for (var x = 0; x < 500; x++) {
//                 // ctx.fillStyle = "#" + Math.floor(Math.random() * 16777215).toString(16);
//                 // var col = (window.performance.now() % 1) * 255;
//                 var colr = (window.performance.now() % 1) * 255;
//                 var colg = (window.performance.now() % 1) * 255;
//                 var colb = (window.performance.now() % 1) * 255;
//                 // var colr = Math.random() * 255;
//                 // var colg = Math.random() * 255;
//                 // var colb = Math.random() * 255;
//                 ctx.fillStyle = `rgb(${colr},${colg},${colb})`;
//                 ctx.fillRect(y, x, 1, 1);
//               }
//             }
//               requestAnimationFrame(draw);
//             }
            
//             }
            
//             var id = requestAnimationFrame(draw);
//         })();
//     </script>
//   </body>
// </html>

// int n_width = 1920; // ca. 3 fps 
// int n_height = 1080;  // ca 3 fps

// holyh motherfucking shit i hate this non-standardized fucking library linking naming system of C 
// link the library with -lSDL2 

// apt-get install libsdl2-dev
// dont forget to link gcc ... -libsdl2-dev
// locate the lib with 
// locate sdl.h or sdl2.h 
// or 
// dpkg --listfiles libsdl2-dev

void fill_with_random_colored_pixels(SDL_Renderer *sdl_renderer){
    for(int y = 0; y < n_height; y++){
        for (int x = 0; x < n_width; ++x){
            // dnd(x);
            // dnd(y);
            // float n_random_normalized = (float) (rand()/(float)RAND_MAX);
            // printf("%f\n", n_random_normalized); 
            // printf("%i\n", (int) (n_random_normalized * (float)255));
            // printf("%d\n",  (uint8_t) (((float) (rand()/(float)RAND_MAX)) * 255));
            SDL_SetRenderDrawColor(
                sdl_renderer, 
                (uint8_t) (((float) (rand()/(float)RAND_MAX)) * 255), 
                (uint8_t) (((float) (rand()/(float)RAND_MAX)) * 255), 
                (uint8_t) (((float) (rand()/(float)RAND_MAX)) * 255),
                0);
                SDL_RenderDrawPoint(sdl_renderer, x, y);

        }
    }
}


void fill_with_timestamp_as_colors(SDL_Renderer *sdl_renderer){
    long ms_ts;
    long ms_ts2;
    for(int y = 0; y < n_height; y++){
        timespec_get(&ts, TIME_UTC);
        ms_ts2 = round(ts.tv_nsec / 1.0e6);
        unsigned long millis_of_current_second2 = ms_ts2 % 1000;
        float ms_ocs_normalized2 = 1.0f / millis_of_current_second2;

        for (int x = 0; x < n_width; ++x){
            timespec_get(&ts, TIME_UTC);
            ms_ts = round(ts.tv_nsec / 1.0e6);
            unsigned long millis_of_current_second = ms_ts % 1000;
            float ms_ocs_normalized = 1.0f / millis_of_current_second;
            SDL_SetRenderDrawColor(
                sdl_renderer, 
                (uint8_t) ((ms_ocs_normalized) * 255), 
                (uint8_t) ((ms_ocs_normalized2) * 255), 
                (uint8_t) ((ms_ocs_normalized) * 255), 
                0);
                SDL_RenderDrawPoint(sdl_renderer, x, y);

        }
    }
}



int main(void) {

    // dnd(1234);
    SDL_Event event;
    SDL_Renderer *sdl_renderer;
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(n_width, n_height, 0, &window, &sdl_renderer);
    
    SDL_RenderClear(sdl_renderer);
    SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 255);
    
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
        // fill_with_random_colored_pixels(sdl_renderer);
        fill_with_timestamp_as_colors(sdl_renderer);
        SDL_RenderPresent(sdl_renderer);
    }

    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}