#include "point.hpp"

std::istream& operator>>(std::istream& input, Point& point) {
	input >> point.x >> point.y >> point.z;
	return input;
}

std::ostream& operator<<(std::ostream& output, const Point& point) {
	output << "(" << point.x << ", " << point.y << ", " << point.z << ")";
	return output;
}

Point::ref Point::operator+=(const Vector other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}

Point Point::operator+(const Vector other) const {
	return {this->x + other.x, this->y + other.y, this->z + other.z};
}

Vector Point::operator-(const Point other) const {
	return {this->x - other.x, this->y - other.y, this->z - other.z};
}
