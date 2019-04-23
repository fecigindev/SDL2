// © 2019 copyright fecigindev

// panggil header file
#include <SDL.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "init.h"
#include "loadmedia.h"

void close()
{
	SDL_FreeSurface( gXOut );
	gXOut = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}

int main( int argc, char* args[] )
{
    //panggil fungsi create window
    init();

    //panggil fungsi Load media
    loadMedia();

    //seupaya aplikasi terus berjalan
    bool quit = false;

    //Event handler
    SDL_Event e;

    //aplikasi terusberjalan
    while( !quit )
    {
        //hendle event
        while( SDL_PollEvent( &e ) != 0 )
        {
            //tunggu penguna mengklik quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
                printf("close program");
            }
        }

        //masuk gambar ke aplikasi
        SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );

        //apply gambar ke aplikasi
        SDL_UpdateWindowSurface( gWindow );
    }
}
