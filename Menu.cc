#include "Menu.h"
#include "SDL.h"
#include <iostream>
#include "Position_class.h"

Menu::Menu(bool team_play, bool start_menu)
{
	if(start_menu == true)
	{
		first_position = Position_class(500, 300);

	}
	else
	{
		first_position = Position_class(500, 200);
	}
}

uint32 Menu::execute()
{
	throw "Not yet implemented";
}

void Menu::move_up()
{
	throw "Not yet implemented";
}

void Menu::move_down()
{
	throw "Not yet implemented";
}
