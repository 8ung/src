#include "Playground.h"
#include <time.h>
#include "SDL.h"

Playground::Playground() {
	upper_left_corner = new Position_class(10, 10);
	bottom_right_corner = new Position_class(540,540);
}

void Playground::random_worm_values() {
	int worm_vector_size  = worm_vector.size();
	for(int i = 0; i < worm_vector_size; i++)
	{
		worm_vector[i].random_position();
		//srand(time(NULL));
		int angle = rand() % 360;
		worm_vector[i].change_direction(angle);
	}
}

void Playground::random_power_up_values() {
	throw "Not yet implemented";
}

void Playground::collision() {
	throw "Not yet implemented";
}

bool Playground::round_finished() {
	if(survivor_vector.size() <= 1)
	{
		return true;
	}
	return false;
}

void Playground::update(int worm_index, bool left_bool, bool right_bool)
{
	double degrees = 0;
	if(survivor_vector[worm_index].powerup_sharp_turn == true)
	{
		degrees = sharp_turn;
	}
	else
	{
		degrees = turn_ratio;
	}
	if(left_bool)
	{
		survivor_vector[worm_index].change_direction(degrees);
		survivor_vector[worm_index].move();
	}
	else if(right_bool)
	{
		survivor_vector[worm_index].change_direction(-degrees);
		survivor_vector[worm_index].move();
	}
	else
	{
		survivor_vector[worm_index].move();
	}
}

void Playground::initialize(Uint32 colour,
		unsigned int left_control,
		unsigned int right_control)
{
	Worm* temp_worm = new Worm(colour, left_control, right_control);
	worm_vector.push_back(*temp_worm);
	survivor_vector.push_back(*temp_worm);
}
