#pragma once

#include <iostream>

#include "utils/utils.hpp"
#include "vector/vector.hpp"

class Point {
	// * Types
   public:
	using ref = Point&;
	using ptr = Point*;

	// * Properties
   public:
	double x;
	double y;
	double z;

	// * Constructors
   public:
	Point() : x(0), y(0), z(0) {}
	Point(Vector vec) : x(vec.x), y(vec.y), z(vec.z) {}
	Point(double x, double y, double z) : def(x), def(y), def(z) {}

	// * Methods

	Vector operator-(Point::ref other);
};

std::istream& operator>>(std::istream& input, Point& point);
std::ostream& operator<<(std::ostream& output, const Point& point);
