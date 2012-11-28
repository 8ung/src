#include "Playground.h"
#include <time.h>
#include <math.h>

Playground::Playground() {
	upper_left_corner = new Position_class(10, 10);
	bottom_right_corner = new Position_class(540,540);
}

Uint32 Playground::get_pixel(SDL_Surface* display, double x, double y)
{
	int bpp = display->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to retrieve */
	Uint8 *p = (Uint8 *)display->pixels + (int)y * display->pitch + (int)x * bpp;

	switch(bpp) {
	case 1:
		return *p;
		break;

	case 2:
		return *(Uint16 *)p;
		break;

	case 3:
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
		break;

	case 4:
		return *(Uint32 *)p;
		break;

	default:
		return 0;       /* shouldn't happen, but avoids warnings */
	}
}

void Playground::start_new_round()
{
	int worm_vector_size  = worm_vector.size();
	for(int i = 0; i < worm_vector_size; i++)
	{
		worm_vector[i]->random_position();
		//srand(time(NULL));
		int angle = rand() % 360;
		worm_vector[i]->change_direction(angle);
		worm_vector[i]->reset_worm();
	}
	survivor_vector = worm_vector;
}

void Playground::random_power_up_values() {
	throw "Not yet implemented";
}

void Playground::collision(SDL_Surface* display)
{
	int survivor_vector_size = survivor_vector.size();
	for(int worm_index = 0; worm_index < survivor_vector_size; worm_index++)
	{
		if(survivor_vector[worm_index]->get_distance_to_hole() > 0)
		{
			double center_x = survivor_vector[worm_index]->get_position()->x_koord;
			double center_y = survivor_vector[worm_index]->get_position()->y_koord;
			double thickness = survivor_vector[worm_index]->thickness + 1.3;
			double angle = survivor_vector[worm_index]->get_direction();
			Uint32 bg_color = SDL_MapRGB(display->format, 0, 0, 0);

			bool right = get_pixel(display, center_x + thickness*cos((angle - 30)*3.141592/180),
					center_y + thickness*sin((angle-30)*3.141592/180)) != bg_color;
			bool left = get_pixel(display, center_x + thickness*cos((angle + 30)*3.141592/180),
					center_y + thickness*sin((angle+30)*3.141592/180)) != bg_color;
			if(right || left)
			{
				survivor_vector[worm_index]->kill_worm();
				survivor_vector.erase(survivor_vector.begin() + worm_index);
				for(int index = 0; index < survivor_vector_size; index++)
				{
					survivor_vector[index]->add_score();
				}

			}
		}
	}
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
	//survivor_vector[worm_index]->powerup_sharp_turn = true;
	double degrees = 0;
	if(survivor_vector[worm_index]->powerup_sharp_turn == true)
	{
		if(SDL_GetTicks() % 90 == 1)
		{
			degrees = sharp_turn;
		}
	}
	else
	{
		degrees = turn_ratio;
	}
	if(left_bool)
	{
		survivor_vector[worm_index]->change_direction(degrees);
		survivor_vector[worm_index]->move();
	}
	else if(right_bool)
	{
		survivor_vector[worm_index]->change_direction(-degrees);
		survivor_vector[worm_index]->move();
	}
	else
	{
		survivor_vector[worm_index]->move();
	}
}

void Playground::initialize(Uint32 colour,
		unsigned int left_control,
		unsigned int right_control)
{
	Worm* temp_worm = new Worm(colour, left_control, right_control);
	worm_vector.push_back(temp_worm);
	survivor_vector.push_back(temp_worm);
}
