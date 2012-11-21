#include "Playground.h"
#include <time.h>

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

void Playground::update(std::vector<int> pressed_keys) {
	int survivor_vector_size =  survivor_vector.size();
	for(int i = 0; i < survivor_vector_size; i++)
	{
		int pressed_keys_size = pressed_keys.size();
		for(int j = 0; j < pressed_keys_size; j++)
		{
			if(pressed_keys[j] == survivor_vector[i].get_left_control())
			{
				if(survivor_vector[i].powerup_sharp_turn == true)
				{
					survivor_vector[i].change_direction(sharp_turn);
				}
				else
				{
					survivor_vector[i].change_direction(turn_ratio);
				}
			}
			else if(pressed_keys[j] == survivor_vector[i].get_right_control())
			{
				if(survivor_vector[i].powerup_sharp_turn == true)
				{
					survivor_vector[i].change_direction(-sharp_turn);
				}
				else
				{
					survivor_vector[i].change_direction(-turn_ratio);
				}
			}
		}
	}
}

void Playground::initialize(Uint32 colour,
		unsigned int left_control,
		unsigned int right_control)
{
	Worm* temp_worm = new Worm(colour, left_control, right_control);
	worm_vector.push_back(*temp_worm);
}
