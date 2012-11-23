#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class Scoreboard {

private:
	Position_class* position_first_row;
	int spacing;
	int min_points;
	int players;

public:
	Scoreboard(std::vector<Worm> &worm_vector);

	void update(std::vector<Worm> &survivor_vector);

	void update_team_play(std::vector<Worm> &survivor_vector, std::vector<Worm> &Worm_vector);

	std::string Scoreboard::game_finished_team_play(std::vector<Worm> &Worm_vector);

	int game_finished(std::vector<Worm> &Worm_vector);
};


#endif /* SCOREBOARD_H */
