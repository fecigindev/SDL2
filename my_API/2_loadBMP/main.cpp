//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "init.h"
#include "loadmedia.h"

void close()
{
	//Deallocate surface
	SDL_FreeSurface( gXOut );
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
    init();

    //Load media
    loadMedia();

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
                printf("close program");
            }
        }

        //Apply the image
        SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );

        //Update the surface
        SDL_UpdateWindowSurface( gWindow );
    }

	return 0;
}
