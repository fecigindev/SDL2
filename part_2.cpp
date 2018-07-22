#include <stdio.h>
#include <SDL.h>

main(int argc, char **argv){
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Event event;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Couldn't initialize SDL ");
        return 0;
    }
    if(SDL_CreateWindowAndRenderer(340,240, SDL_WINDOW_RESIZABLE, &window, &renderer)){
        printf("Couldn't Create Window and renderer");
        return 0;
    }

    surface = SDL_LoadBMP("sample.bmp");
    if(!surface){
        printf("Couldn't Create surface from image");
        return 0;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture){
        printf("Couldn't Create Texture");
        return 0;
    }
    SDL_FreeSurface(surface);

    while(1){
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT){
            break;
        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
