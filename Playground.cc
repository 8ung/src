#include "Playground.h"

/*Playground::Playground() {
	throw "Not yet implemented";
}*/

void Playground::random_worm_values() {
	for(int i = 0; i < worm_vector.size(); i++)
	{
		worm_vector[i].random_position();
		int angle = rand % 360;
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
	if(survivor_vector.size() == 1)
	{
		return true;
	}
	return false;
}

void Playground::update(std::vector<int> pressed_keys) {
	for(int i = 0; i < survivor_vector.size(); i++)
	{
		for(int j = 0; j < pressed_keys.size(); j++)
		{
			if(pressed_keys[j] == survivor_vector[i].get_left_control())
			{
				survivor_vector[i].change_direction(turn_ratio);
			}
			else if(pressed_keys[j] == survivor_vector[i].get_right_control())
			{
				survivor_vector[i].change_direction(-turn_ratio);
			}
		}
	}
}

void Playground::initialize(Uint32 colour,
		unsigned int left_control,
		unsigned int right_control) {
	Worm temp_worm = new Worm(colour, left_control, right_control);
	worm_vector.push_back(temp_worm);
}
