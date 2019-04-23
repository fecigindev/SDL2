//© 2019 copyright fecigindev

//atur window screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//define fungsi init
bool init();

//define fungsi loads media
bool loadMedia();

//tutup aplikasi
void close();

//window akan di render
SDL_Window* gWindow = NULL;

//untuk membuat konten dalam window
SDL_Surface* gScreenSurface = NULL;

//gambar akan di load ke sini
SDL_Surface* gXOut = NULL;

bool init()
{
	
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//buat windows
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					   SCREEN_WIDTH, SCREEN_HEIGHT,
					   SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}
