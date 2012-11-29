#ifndef POWERUP_H
#define POWERUP_H

#include "C:\Users\Dennis\C++\Achtung\src\src\Position_class.h"
#include "SDL_stdinc.h"
#include <vector>
#include "C:\Users\Dennis\C++\Achtung\src\src\Worm.h"

class Powerup
{

private:
	Position_class position;

public:
	Powerup(Position_class, Uint32);
	virtual ~Powerup() = default;

	Uint32 colour_id;
	int radius;

	virtual void execute(int, std::vector<Worm>&) = 0;
};

#endif
