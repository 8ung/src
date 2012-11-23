#include "Worm.h"
#include <math.h>
#include <time.h>

Worm::Worm(Uint32 new_colour, int new_left_control, int new_right_control) {
	distance_to_hole = random_distance_to_hole();
	colour = new_colour;
	left_control = new_left_control;
	right_control = new_right_control;
	position = new Position_class();
	position->random_position();
	//srand(time(NULL));
	direction = rand() % 360;
}

int Worm::random_distance_to_hole() {
	int distance = rand() % 100;
	return distance;
}

void Worm::random_position()
{
	position->random_position();
}

void Worm::change_direction(double degrees)
{
	direction = direction + degrees;
	if(direction > 360)
	{
		direction = direction - 360;
	}
	else if(direction < 0)
	{
		direction = direction + 360;
	}
}

void Worm::kill_worm() {
	speed = 0;
}

Position_class* Worm::get_position() {
	return position;
}

Uint32 Worm::get_colour() {
	return colour;
}

int Worm::get_left_control() {
	return left_control;
}

int Worm::get_right_control() {
	return right_control;
}

void Worm::move() {
	position->x_koord = position->x_koord + speed*cos(direction*3.141592/180);
	position->y_koord = position->y_koord + speed*sin(direction*3.141592/180);
}

void Worm::reset_worm()
{
	speed = default_speed;
	thickness = default_thickness;
	powerup_timer = default_powerup_timer;
	powerup_through_wall = false;
	powerup_ghost = false;
	powerup_sharp_turn = false;
	powerup_mirror = false;
}
