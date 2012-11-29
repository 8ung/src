#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <vector>
#include "Worm.h"
#include "SDL.h"


class Playground {

private:
	const double turn_ratio = 0.2;
	const double sharp_turn = 90;
public:
	Position_class* upper_left_corner;
	Position_class* bottom_right_corner;
	std::vector<int> powerup_vector;
	std::vector<Worm*> worm_vector;
	std::vector<Worm*> survivor_vector;

	Playground(int);
	//~Playground();

private:

	Uint32 get_pixel(SDL_Surface*, double, double);

	void random_power_up_values();

	bool round_finished();

	void sort_vectors();

public:

	void start_new_round();

	void collision(SDL_Surface*);

	void update(int,bool,bool);

	void reset();

	void initialize(Uint32 colour, unsigned int left_control, unsigned int right_control);
};

#endif /* PLAYGROUND_H */
