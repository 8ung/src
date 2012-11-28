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
	Scoreboard(std::vector<Worm>&, bool);

	void update(std::vector<Worm>&);

	void update_team_play(std::vector<Worm>&, std::vector<Worm>&);

	std::string game_finished_team_play(std::vector<Worm>&);

	int game_finished(std::vector<Worm>&);
};


#endif /* SCOREBOARD_H */
