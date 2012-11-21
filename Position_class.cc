#include "Position_class.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

Position_class::Position_class(int x, int y)
{
	x_koord = x;
	y_koord = y;
}

void Position_class::random_position()
{
	//srand(time(NULL));
	x_koord = rand() % (x_max - x_min) + x_min;
	//srand(time(NULL));
	y_koord = rand() % (y_max - y_min) + y_min;
}
