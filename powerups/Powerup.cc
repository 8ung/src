#include "Powerup.h"
#include "C:\Users\Dennis\C++\Achtung\src\src\Playground.h"
#include "SDL_stdinc.h"

using namespace std;

Powerup::Powerup(Position_class new_position, Uint32 color)
{
	position = new_position;
	colour_id = color;
	radius = 30;
}
