/*
 * Playground_test.cc
 *
 *  Created on: 19 nov 2012
 *      Author: Oscar
 */
//#include "SDL.h"
#include "Playground.h"
#include <iostream>

using namespace std;

int main()
{
	Uint32 bg_colour = 0x00000001;
	Playground* playground = new Playground();
	playground->initialize(bg_colour, 132,164);
	Playground play = *playground;
	cout << play.worm_vector[0].get_colour() << endl;
	cout << "hej" << endl;
	return 0;
}
