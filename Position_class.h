#ifndef POSITION_CLASS_H
#define POSITION_CLASS_H

class Position_class
{
private:
	enum
	{
		x_max = 500,
		x_min = 50,
		y_max = 500,
		y_min = 50
	};

public:
	float x_koord;
	float y_koord;

	Position_class(int x = 0, int y = 0);
	//~Position_class();

	void random_position();
};

#endif /* POSITION_CLASS_H */
