#include "Position_class.h"

void Position_class::random_position() {
	x_koord = rand() % (x_max - x_min) + x_min;
	y_koord = rand() % (y_max - y_min) + y_min;
}
