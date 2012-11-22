#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <vector>
#include "Worm.h"


class Playground {

private:
	Position_class* upper_left_corner;
	Position_class* bottom_right_corner;
	const double turn_ratio = 0.2;
	const double sharp_turn = 90;
public:
	std::vector<int> powerup_vector;
	std::vector<Worm> worm_vector;
	std::vector<Worm> survivor_vector;

	Playground();
	//~Playground();

private:
	//void random_worm_values();

	void random_power_up_values();

	void collision();

	bool round_finished();

public:

	void random_worm_values();
	void update(int,bool,bool);

	void initialize(Uint32 colour, unsigned int left_control, unsigned int right_control);
};

#endif /* PLAYGROUND_H */
