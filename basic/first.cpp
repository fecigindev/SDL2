// This sourcecode copyrighted by fecigindev end may not be redistributed without written permissio //

#include <SDL.h>
#include <stdio.h>

const int labar = 640;
const int tinggi = 480;

int main( int argc, char* args[] )
{
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

    //tampilkan window
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, labar, tinggi, SDL_WINDOW_SHOWN );

    //tampilkan selama 2 menit
    SDL_Delay(2000);

	SDL_DestroyWindow( window );

	SDL_Quit();
}
