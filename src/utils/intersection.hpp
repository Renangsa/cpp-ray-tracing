#pragma once

#include <iostream>

#include "point/point.hpp"
#include "utils.hpp"
#include "vector/vector.hpp"

struct Intersection {
	// * Types
	using ref = Intersection&;
	using ptr = Intersection*;

	// * Enum
	enum type {
		hit,
		missed,
		undefined,
	};

	// * Properties
	type status;
	double distance;
	Point point;
	Vector normal;
	Color color;

	// * Constructors
	Intersection() : status(type::undefined) {}
	Intersection(bool miss) : status(type::missed) {}
	Intersection(double distance, Point point, Vector normal, Color color) : status(type::hit), def(distance), def(point), def(normal), def(color) {}

	// * Operators
	operator bool();
	void operator<<(const Intersection::ref other);
};
