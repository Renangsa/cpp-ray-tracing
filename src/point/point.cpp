#include "point.hpp"

Vector Point::operator-(Point::ref other) {
	return {this->x - other.x, this->y - other.y, this->z - other.z};
}

std::istream& operator>>(std::istream& input, Point& point) {
	input >> point.x >> point.y >> point.z;
	return input;
}

std::ostream& operator<<(std::ostream& output, const Point& point) {
	output << "(" << point.x << ", " << point.y << ", " << point.z << ")";
	return output;
}
