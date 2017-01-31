/*
 * main.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: tim
 */

#include "Point.h"
#include <iostream>
using std::cout;
using std::endl;

int main6(void)
{
	cout << Point<double>::dist({2, 3},{4,6}) << endl;
	cout << "Please define two points by following the given instructions." << endl << endl;
	Point<double> p1 = Point<double>::get_user_defined_point();
	Point<double> p2 = Point<double>::get_user_defined_point();
	cout << "The distance between these points is: " << Point<double>::dist(p1, p2);
	cout << " (Units of distance or whatever)" << endl;
	return 0;
}

