/*
 * Point.h
 *
 *  Created on: Jan 30, 2017
 *      Author: tim
 */

#ifndef POINT_H_
#define POINT_H_
#include <initializer_list>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <cassert>

/**
 * Over-engineered Point class because I am bored.
 */

template <typename T>
class Point {
private:
	T x, y;
public:

	/**
	 *  Constructors.  Fairly straightforward.
	 */
	Point()
	{
		this->x = 0;
		this->y = 0;
	}
	Point(T x, T y)
	{
		this->x = x;
		this->y = y;
	}
	Point(std::initializer_list<T> vals)
	{
		assert(vals.size() == 2);
		this->x = vals.begin()[0];
		this->y = vals.begin()[1];
	}

	/**
	 *  Destructor.  No managed memory to destroy.
	 */
	virtual ~Point()
	{
		;
	}

	static Point<T> get_user_defined_point()
	{
		T x, y;
		std::cout << "Please enter an x and a y coordinate delimited by a space:\n>>> " << std::flush;
		std::cin >> x >> y;
		std::cout << std::endl;
		return Point<T>(x, y);
	}

	/**
	 * Distance between two points, for all 4 permutations of rvalue reference
	 * and passing by constant reference.
     *
     * So, in principle, you could do something like:
     * double dist = Point<double>::dist({2, 3},{4,6});
	 */

	static T dist(const Point<T> & p1, const Point<T> & p2)
	{
		return (p2 - p1).norm();
	}

	static T dist(const Point<T> & p1, Point<T> && p2)
	{
		return (p2 - p1).norm();
	}
	static T dist( Point<T> && p1, const Point<T> & p2)
	{
		return (p2 - p1).norm();
	}

	static T dist(Point<T> && p1, Point<T> && p2)
	{
		return (p2 - p1).norm();
	}

	/**
	 * Implicit arbitrary type-conversion.
	 */
	template <typename TypeTo>
	operator Point<TypeTo>()
	{
		return Point<TypeTo>((TypeTo)this->x, (TypeTo)this->y);
	}

	/**
	 *  Initializer-list assignment.
	 */
	template <typename T2 = T>
	Point<T> & operator=(std::initializer_list<T2> vals)
	{
		assert(vals.size() == 2);
		this->x = (T)vals[0];
		this->y = (T)vals[1];
		return *this;
	}

	/**
	 *  Copy assignment operator.
	 */
	template <typename T2 = T>
	Point<T> & operator=(const Point<T2> & other)
	{
		this->x = (T)other.x;
		this->y = (T)other.y;
		return *this;
	}
	/**
	 *  Copy assignment operator.
	 */
	template <typename T2 = T>
	Point<T> & operator=(Point<T2> && other)
	{
		this->x = (T)other.x;
		this->y = (T)other.y;
		return *this;
	}
	/**
	 *  Container-like element access.
	 */
	T & operator[](const size_t & index)
	{
		switch(index)
		{
		case 0:
			return this->x;
			break;
		case 1:
			return this->y;
			break;
		default:
			throw new std::invalid_argument("Point objects contain only two coordinates!");
		}
	}
	/**
	 *  Standard vector addition.
	 */
	Point<T> operator+(const Point & other) const
	{
		return Point(this->x + other.x, this->y + other.y);
	}
	Point<T> operator+(Point && other) const
	{
		return Point(this->x + other.x, this->y + other.y);
	}

	/**
	 *  Standard vector subtraction.
	 */
	Point<T> operator-(const Point & other) const
	{
		return Point(this->x - other.x, this->y - other.y);
	}
	Point<T> operator-(Point && other) const
	{
		return Point(this->x - other.x, this->y - other.y);
	}


	/**
	 *  Euclidean inner product/Dot product.
	 */
	T operator*(const Point & other) const
	{
		return this->x * other.x + this->y * other.y;
	}
	/**
	 *  Euclidean inner product/Dot product.
	 */
	T operator*(Point && other) const
	{
		return this->x * other->x + this->y * other->y;
	}

	T norm()
	{
		return sqrt((*this) * (*this));
	}

};

#endif /* POINT_H_ */
