#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Position_class.h"
#include <vector>
#include "Worm.h"

class Scoreboard
{

private:
	Position_class* position_first_row;
	int spacing;
	int min_points;
	int players;
	bool team_play;

public:
	Scoreboard(std::vector<Worm> &worm_vector, bool teamplay);

	void update(std::vector<Worm> &survivor_vector);

	void update_team_play(std::vector<Worm> &survivor_vector, std::vector<Worm> &Worm_vector);

	std::string game_finished_team_play(std::vector<Worm> &Worm_vector);

	int game_finished(std::vector<Worm> &Worm_vector);
};


#endif /* SCOREBOARD_H */
