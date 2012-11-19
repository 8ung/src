#include "Worm.h"
#include <math.h>

Worm::Worm(Uint32 new_colour, char new_left_control, char new_right_control) {
	int distance_to_hole = random_distance_to_hole();
	Uint32 colour = new_colour;
	int left_control = new_left_control;
	int right_control = new_right_control;
	Position_class position = new Position_class();
	position.random_position();
	int direction = rand() % 360;
}

int Worm::random_distance_to_hole() {
	int distance = rand() % 100;
	return distance;
}

void Worm::random_position()
{
	position.random_position();
}

void Worm::change_direction(int degrees) {
	direction = direction + degrees;
}

void Worm::kill_worm() {
	speed = 0;
}

Position_class Worm::get_position() {
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
	position.x_koord = speed*cos(direction*3.141592/180);
	position.y_koord = speed*sin(direction*3.141592/180);
}

void Worm::reset_worm() {
	throw "Not yet implemented";
}
