#include "Game.h"
#include "Playground.h"
#include "SDL.h"
#include <iostream>
#include <time.h>

using namespace std;

Game::Game() {
	frameSkip = 0;
	running = 0;
	display = NULL;
	for ( int i=0; i<SDLK_LAST; ++i ) {
		this->keys[ i ] = 0 ;
	}
	initialize();
	Playground* playground = new Playground();
	Uint32 bg_colour = 0x00000001;
	playground->initialize(bg_colour, 132,164);
	//skapa objekt av Menu och Scoreboard här också
}

void Game::initialize()
{

	int flags = SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_ANYFORMAT ;

	/* initialize SDL */
	if ( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) ) {
		return ;
	}

	/* set video surface */
	this->display = SDL_SetVideoMode(400, 400, 0, flags );//| SDL_FULLSCREEN);
	if ( display == NULL ) {
		return ;
	}

	/* Set caption */
	SDL_WM_SetCaption( "Achtung, die Kurve!", NULL );

	this->running = 1 ;
	run();
	//throw "Not yet implemented";
}

void Game::listen_to_keys()
{
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:    quit();            break;
		case SDL_KEYDOWN: key_pressed( &event ); break;
		case SDL_KEYUP:   key_unpressed( &event );   break;
		}
	}
}

void Game::draw_playground() {
	throw "Not yet implemented";
}

void Game::draw_menu() {
	throw "Not yet implemented";
}

void Game::draw_scoreboard() {
	throw "Not yet implemented";
}

bool Game::game_finished() {
	throw "Not yet implemented";
}
void fpsChanged( int fps ) {
	char szFps[ 128 ] ;

	sprintf( szFps, "%s: %d FPS", "Achtung, die Kurve!", fps );
	SDL_WM_SetCaption( szFps, NULL );
}


void Game::key_pressed( SDL_Event* event )
{
	keys[ event->key.keysym.sym ] = 1;
}

void Game::key_unpressed( SDL_Event* event )
{
	keys[ event->key.keysym.sym ] = 0;
}

void Game::quit()
{
	running = 0;
}

void Game::fpsChanged( int fps ) {
	char szFps[ 128 ] ;

	sprintf( szFps, "%s: %d FPS", "SDL Base C++ - Use Arrow Keys to Move", fps );
	SDL_WM_SetCaption( szFps, NULL );
}

void Game::run() {
	int past = SDL_GetTicks();
	int now = past, pastFps = past ;
	int fps = 0, framesSkipped = 0 ;
	srand(time(NULL));

	//SDL_Event event ;
	while ( running )
	{
		int timeElapsed = 0 ;

		listen_to_keys();
		playground->update(keys[SDLK_LAST]);

		/* Menu */

		/* update/draw */
		timeElapsed = (now=SDL_GetTicks()) - past ;
		if ( timeElapsed >= 1000/60  )
		{
			past = now ;
			//update();
			if ( framesSkipped++ >= frameSkip )
			{
				SDL_Flip( display );
				++fps ;
				framesSkipped = 0 ;
			}
		}

		/* fps */
		if ( now - pastFps >= 1000 )
		{
			pastFps = now ;
			fpsChanged( fps );
			fps = 0 ;
		}
		/* sleep? */
		SDL_Delay( 1 );
	}
}
