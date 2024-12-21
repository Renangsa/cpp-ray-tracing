#include "plane.hpp"

#include <fstream>
#include <iostream>

#include "point/point.hpp"
#include "utils/colorstream.hpp"
#include "utils/utils.hpp"

bool Plane::intersect(Vector::ref vector, Point::ref camera) {
	return false;
}

void Plane::print() {
	std::cout << this->position << " " << this->normal << " " << this->color << std::endl;
}

void Plane::subscribe(Object::registry& registry) { registry["plane"] = Plane::construct; }
Object::ptr Plane::construct(std::ifstream& input) {
	Point point;
	Vector vector;
	Color color;

	input >> point >> vector >> color;

	return new Plane(point, vector, color);
}
