//© 2019 copyright fecigindev

bool loadMedia()
{
	//load media success
	bool success = true;

	//Load splash image
	gXOut = SDL_LoadBMP( "x.bmp" );
	if( gXOut == NULL )
	{
		printf( " image tidak bisa diload ke aplikasi %s! SDL Error: %s\n",
         "03_event_driven_programming/x.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}
