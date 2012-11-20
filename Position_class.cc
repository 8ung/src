#include "Position_class.h"
#include <math.h>

using namespace std;

Position_class::Position_class()
{
	x_koord = 0;
	y_koord = 0;
}

void Position_class::random_position() {
	x_koord = 20;
	y_koord = 20;
	/*x_koord = rand() % (x_max - x_min) + x_min;
	y_koord = rand() % (y_max - y_min) + y_min;*/
}
