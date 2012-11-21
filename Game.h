#ifndef GAME_H
#define GAME_H

#include <vector>
#include "SDL.h"
#include "Playground.h"

class Game {

private:
	Uint32 input_colour;
	int input_left_controler;
	int input_right_controler;
	int keys[ SDLK_LAST ];
	int frameSkip;
	int running;
	SDL_Surface* display;
	Playground* playground;


public:
	Game();

private:
	void initialize();

	void listen_to_keys();

	void draw_playground();

	void draw_menu();

	void draw_scoreboard();

	bool game_finished();

	void onKeyDown( SDL_Event* event );

	void onKeyUp( SDL_Event* event );

public:
	void run();
};

#endif /* GAME_H */
