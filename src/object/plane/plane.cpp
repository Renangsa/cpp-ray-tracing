#include "plane.hpp"

#include <fstream>
#include <iostream>

#include "point/point.hpp"
#include "utils/colorstream.hpp"
#include "utils/utils.hpp"
#include "vector/vector.hpp"

Intersection Plane::intersect(Vector::ref vector, Point::ref camera) {
	Point pixel = camera + vector;
	Vector unity = vector;
	unity.normalize();

	double first = (this->position - pixel) & this->normal;
	double second = unity & this->normal;

	if (second == 0) return false;

	double offset = first / second;
	if (offset <= 0) return false;

	Point hit_point = pixel + (unity * offset);
	Vector hit_vector = hit_point - camera;

	return {hit_vector.size(), this->color};
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
