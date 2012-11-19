class Powerup {

private:
	Position_class position;
	int size;
	uint32 colour_id;
	bool affect_me;
	bool affect_map;

public:
	Powerup(Position_class position);

	void execute();
};
