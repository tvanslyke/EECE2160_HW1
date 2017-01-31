/*
 * problem_6_alt.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: tim
 */


#include <stdio.h>
#include <math.h>


/**
 *  Some (clumsy) c-style class based OOP.
 */


/**
 *  The Point "class".  no vtable used.
 */
typedef struct
{
	double x, y;
	// "instance methods"
	void (*subtract)(void * self, void * other);
	double (*norm)(void * self);
} Point;

/**
 * Essentially the constructor
 */
Point newPoint(double, double);
/**
 * dot product
 */
double dot(Point *, Point *);


/**
 * vector norm
 */
// double leading underscore suggests this function shouldn't be called
// on it's own.  only as a method.  Doesn't actually matter in this case.
double __norm(Point *);
/**
 * subtract the second point arg from the first
 */
void __subtract(Point *, Point *);

Point newPoint(double x, double y)
{
	// assign data members and methods
	Point p;
	p.x = x;
	p.y = y;
	p.subtract = (void (*)(void *, void *))__subtract;
	p.norm = (double (*)(void *))__norm;
	return p;
}


double __norm(Point * self)
{
	return sqrt(dot(self, self));
}

void __subtract(Point * self, Point * other)
{
	self->x -= other->x;
	self->y -= other->y;
}

double dot(Point * self, Point * other)
{
	return self->x * other->x + self->y * other->y;
}

double euc_dist(Point p1, Point p2)
{
	// return the norm of the "point" (vector, in the mathematical sense)
	// pointing from p2 to p1
	p1.subtract(&p1, &p2);
	return p1.norm(&p1);
}

int _main6(void)
{
	// prompt
	printf("Please define two points by following the given instructions.\n");

	// place-holders for assignment
	double x, y;

	// create the first point
	printf("Enter the x and y coordinates of the first point:\n>>> ");
	fscanf(stdin, "%lf %lf", &x, &y);
	Point p1 = newPoint(x, y);

	// create the second point
	printf("Enter the x and y coordinates of the second point:\n>>> ");
	fscanf(stdin, "%lf %lf", &x, &y);
	Point p2 = newPoint(x, y);

	// distance calculation
	double dist = euc_dist(p1, p2);
	printf("The distance between these points is: %lf (units of distance)", dist);

	return 0;
}




