class Position_class {

private:
	const int x_max = 500;
	const int x_min = 50;
	const int y_max = 500;
	const int y_min = 50;

public:
	float x_koord = 0;
	float y_koord = 0;

	Position_class();
	~Position_class();

	void random_position();
};
