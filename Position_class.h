class Position_class
{
private:
	const int x_max = 500;
	const int x_min = 50;
	const int y_max = 500;
	const int y_min = 50;

public:
	float x_koord;
	float y_koord;

	Position_class();
	//~Position_class();

	void random_position();
};
