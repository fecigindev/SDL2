#include <SDL.h>
#include <stdio.h>

main(int argc, char **argv){
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("part 1",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500,SDL_WINDOW_OPENGL);
    SDL_Delay(3000);
    SDL_Quit();
    return 0;
}
