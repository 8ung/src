#ifndef GAME_H
#define GAME_H

#include <vector>
#include "SDL.h"

class Game {

private:
	Uint32 input_colour;
	int input_left_controler;
	int input_right_controler;
	std::vector<int> pressed_keys;
	int keys[ SDLK_LAST ];
	int frameSkip;
	int running;
	SDL_Surface* display;

public:
	Game();

private:
	void initialize();

	void listen_to_keys();

	void draw_playground();

	void draw_menu();

	void draw_scoreboard();

	bool game_finished();

public:
	void run();
};

#endif /* GAME_H */
