#pragma once

#include <iostream>

#include "utils/utils.hpp"

class Vector {
	// * Types
   public:
	using ptr = Vector*;
	using ref = Vector&;

	// * Properties
   public:
	double x;
	double y;
	double z;

	// * Constructors
   public:
	Vector() : x(1), y(1), z(1) {}
	Vector(double x, double y, double z) : def(x), def(y), def(z) {}

	// * Methods
   public:
	void normalize();

	Vector operator+(const Vector other) const;
	Vector operator-(const Vector other) const;

	Vector operator+(const Vector::ref other) const;
	Vector operator-(const Vector::ref other) const;
	Vector operator*(const Vector::ref other) const;

	// Vector operator-=(const)

	Vector operator*(const double scalar) const;

	void operator*=(const double scalar);
};

std::istream& operator>>(std::istream& input, const Vector::ref vector);
std::ostream& operator<<(std::ostream& output, const Vector::ref vector);
