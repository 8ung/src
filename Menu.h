class Menu {

private:
	Position_class marker_position;
	Position_class first_position;
	int spacing;

public:
	Menu();

	uint32 execute();

	void move_up();

	void move_down();
};
