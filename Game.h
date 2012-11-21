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
	SDL_Event event;



public:
	Game();

private:
	void initialize();

	void listen_to_keys();

	void draw_playground();

	void draw_menu();

	void draw_scoreboard();

	bool game_finished();

	void key_pressed( SDL_Event* event );

	void key_unpressed( SDL_Event* event );

	void quit();

	void fpsChanged(int);

public:
	void run();
};

#endif /* GAME_H */
