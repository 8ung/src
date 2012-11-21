#include <stdio.h>
#include "Game.h"
#include "SDL.h"
#include <iostream>
#include <time.h>

Game::Game() {
	initialize();
	Playground* playground = new Playground();
	//skapa objekt av Menu och Scoreboard här också
	//throw "Not yet implemented";
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

void Game::listen_to_keys() {
	throw "Not yet implemented";
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


void onKeyDown( SDL_Event* event )
{

}

void onKeyUp( SDL_Event* event )
{

}

void Game::run() {
	int past = SDL_GetTicks();
	int now = past, pastFps = past ;
	int fps = 0, framesSkipped = 0 ;
	srand(time(NULL));
	Uint32 bg_colour = 0x00000001;

	//SDL_Event event ;
	while ( running ) {
		int timeElapsed = 0 ;

		/* Menu */

		playground->initialize(bg_colour, 132,164);


		/* update/draw */
		timeElapsed = (now=SDL_GetTicks()) - past ;
		if ( timeElapsed >= 1000/60  ) {
			past = now ;
			//update();
			if ( framesSkipped++ >= frameSkip ) {
				//draw();
				++fps ;
				framesSkipped = 0 ;
			}
		}
		/* fps */
		if ( now - pastFps >= 1000 ) {
			pastFps = now ;
			fpsChanged( fps );
			fps = 0 ;
		}
		/* sleep? */
		SDL_Delay( 1 );
	}
}
