#include <stdlib.h>

#include <SDL2/SDL.h>
#include <time.h>
#include "./../c_helpers/dnd.c"


// holyh motherfucking shit i hate this non-standardized fucking library linking naming system of C 
// link the library with -lSDL2 

// apt-get install libsdl2-dev
// dont forget to link gcc ... -libsdl2-dev
// locate the lib with 
// locate sdl.h or sdl2.h 
// or 
// dpkg --listfiles libsdl2-dev



int main(void) {

    int n_width = 500; 
    int n_height = 500; 
    // dnd(1234);
    // SDL_Event event;
    // SDL_Renderer *renderer;
    // SDL_Window *window;
    dnd(1234);

    // for(int a = 0; a<2; a++){
    //     dnd(a);
    // }
    // float n_random_normalized = (float) (rand()/RAND_MAX);
    
    // dnd(n_random_normalized); 

    // SDL_Init(SDL_INIT_VIDEO);
    // SDL_CreateWindowAndRenderer(n_width, n_height, 0, &window, &renderer);
    
    // SDL_RenderClear(renderer);
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    
    // for(int y = 0; y < n_height; y++){
    //     for (int x = 0; x < n_width; ++x){
    //         printf("%i\n", y);
    //         dndi(y);
    //         // dnd(y);
    //         // dnd(x);
    //         // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    //         // SDL_RenderDrawPoint(renderer, x, y);
    //     }
    // }



    // SDL_RenderPresent(renderer);
    // while (1) {
    //     if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
    //         break;
    // }

    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();
    return EXIT_SUCCESS;
}