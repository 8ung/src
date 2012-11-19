class Scoreboard {

private:
	Position_class position_first_row;
	int spacing;
	int min_points;
	int players;

public:
	Scoreboard(vector& worm_vector);

private:
	bool game_finished();

public:
	void update(vector& survivor_vector);
};
