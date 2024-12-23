#pragma once

#include "utils.hpp"

struct Intersection {
	// * Types
	using ref = Intersection&;

	// * Enum
	enum type {
		hit,
		missed,
		undefined,
	};

	// * Properties
	type status;
	double distance;
	Color color;

	// * Constructors
	Intersection() : status(type::undefined) {}
	Intersection(bool miss) : status(type::missed) {}
	Intersection(double distance, Color color) : status(type::hit), def(distance), def(color) {}

	// * Operators
	operator bool();
	void operator<<(const Intersection::ref other);
};
