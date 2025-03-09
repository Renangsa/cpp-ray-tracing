#pragma once

#include <iostream>

#include "material/material.hpp"
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
	Material::ptr material;

	// * Constructors
	Intersection() : status(type::undefined) {}
	Intersection(bool miss) : status(type::missed) {}
	Intersection(double distance, Point point, Vector normal, Color color);
	Intersection(double distance, Point point, Vector normal, Color color, Material::ptr material);

	// * Operators
	operator bool();
	void operator<<(const Intersection::ref other);
};
