#include "vector.hpp"

#include <cmath>

#include "point/point.hpp"
#include "utils/utils.hpp"

std::istream& operator>>(std::istream& input, Vector::ref vector) {
	input >> vector.x >> vector.y >> vector.z;
	return input;
}

std::ostream& operator<<(std::ostream& output, const Vector::ref vector) {
	output << "<" << vector.x << ", " << vector.y << ", " << vector.z << ">";
	return output;
}

void Vector::normalize() {
	double length = sqrt(sqr(x) + sqr(y) + sqr(z));

	this->x /= length;
	this->y /= length;
	this->z /= length;
}

Vector Vector::operator+(const Vector other) const {
	return Vector(this->x + other.x, this->y + other.y, this->z + other.z);
}
Vector Vector::operator+(const Vector::ref other) const {
	return Vector(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector Vector::operator-(const Vector other) const {
	return Vector(this->x - other.x, this->y - other.y, this->z - other.z);
}
Vector Vector::operator-(const Vector::ref other) const {
	return Vector(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector Vector::operator*(const Vector::ref other) const {
	double i = (this->y * other.z) - (this->z * other.y);
	double j = (this->z * other.x) - (this->x * other.z);
	double k = (this->x * other.y) - (this->y * other.x);

	return {i, j, k};
}

Vector Vector::operator*(const double scalar) const {
	return Vector(this->x * scalar, this->y * scalar, this->z * scalar);
}

void Vector::operator*=(const double scalar) {
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}
