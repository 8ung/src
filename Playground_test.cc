/*
 * Playground_test.cc
 *
 *  Created on: 19 nov 2012
 *      Author: Oscar
 */
#include "SDL.h"
#include "Playground.h"
#include <iostream>
#include "Position_class.h"
#include <time.h>

using namespace std;

bool in_game = true;
SDL_Event event;
int keys[ SDLK_LAST ] ;



void onKeyDown( SDL_Event* event )
{
	keys[ event->key.keysym.sym ] = 1 ;
	//event->key.keysym.sym; //event->key.keysym.sym av typ SDLKey!
	//cout << "en tangent trycks nu ned!" << endl;
}

void onKeyUp( SDL_Event* event )
{
	keys[ event->key.keysym.sym ] = 0 ;
	//cout << "du släpple tangenten" << endl;

}
void onQuit()
{
	in_game = false;
}

int main(int argc, char *argv[])
{
	Uint32 bg_colour = 0x00000001;
	/*Position_class* position = new Position_class();
	position->random_position();
	cout << position->x_koord;*/

	Playground* playground = new Playground();
	srand(time(NULL));
	playground->initialize(bg_colour, 132,164);
	while (in_game) {
			if (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:    onQuit();            break;
				case SDL_KEYDOWN: onKeyDown( &event ); break;
				case SDL_KEYUP:   onKeyUp( &event );   break;
				}
			}
			if ( keys[SDLK_LEFT] ) {
				cout << "left" << endl;
			}
	//Playground play = *playground;
	}




	int i = 0;
	int length = playground->worm_vector.size();
	while (i < length)
	{
		playground->worm_vector[i].move();
		cout << "Mask nr. " << i << " " << playground->worm_vector[i].get_position()->x_koord << endl;
		//play.worm_vector[0].change_direction(30);
		if(i == 4)
		{
			playground->worm_vector[0].kill_worm();
		}
		//play.worm_vector[1].move();
		i++;
	}
	//int test = rand() % 360;

	cout << rand() % 10 << endl;

	return 0;
}
