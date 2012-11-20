#include "Position_class.h"
#include "SDL_stdinc.h"

class Worm {

private:
	int distance_to_hole;
	Uint32 colour;
	int left_control;
	int right_control;
	Position_class* position;
	int direction;
public:
	double speed = 0.1;
	double thickness = 8;
	int powerup_timer = 0;
	int score = 0;
	bool powerup_through_wall = false;
	bool powerup_ghost = false;

	Worm(Uint32 colour, int left_control, int right_control);

private:
	int random_distance_to_hole();

public:
	void change_direction(int degrees);

	void kill_worm();

	//Position_class get_position();

	Uint32 get_colour();

	int get_left_control();

	int get_right_control();

	void move();

	void reset_worm();

	void random_position();
};
