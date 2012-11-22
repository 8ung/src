#ifndef MENU_H
#define MENU_H

#include "SDL.h"
#include "Position_class.h"

class Menu
{

private:
	Position_class marker_position;
	Position_class first_position;
	bool team_play;
	bool start_menu;
	int spacing;
	int position;

public:
	Menu(bool team_play, bool start_menu);

	uint32 execute();

	void move_up();

	void move_down();
};


#endif /* MENU_H */
