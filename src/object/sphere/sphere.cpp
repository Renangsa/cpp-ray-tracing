#include "sphere.hpp"

#include <fstream>
#include <iostream>

#include "point/point.hpp"
#include "utils/colorstream.hpp"
#include "utils/utils.hpp"

bool Sphere::intersect(Vector::ref vector, Point::ref camera) {
	Point point = camera - this->position;

	double first = sqr(vector.x) + sqr(vector.y) + sqr(vector.z);
	double second = (vector.x * point.x) + (vector.y * point.y) + (vector.z * point.z);
	double third = sqr(point.x) + sqr(point.y) + sqr(point.z) - sqr(this->radius);

	double delta = sqr(second) - 4 * first * third;

	return delta > 0;
}

void Sphere::print() {
	std::cout << this->position << " " << this->radius << " " << this->color << std::endl;
}

void Sphere::subscribe(Object::registry& registry) { registry["sphere"] = Sphere::construct; }
Object::ptr Sphere::construct(std::ifstream& input) {
	Point center;
	double radius;
	Color color;

	input >> center >> radius >> color;

	return new Sphere(center, radius, color);
}
