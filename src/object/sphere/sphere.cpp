#include "sphere.hpp"

#include <cmath>
#include <fstream>
#include <iostream>

#include "utils/colorstream.hpp"
#include "utils/utils.hpp"

Intersection Sphere::intersect(Vector::ref vector, Point::ref camera) {
	Vector offset = camera - this->position;

	double first = vector & vector;
	double second = 2 * (vector & offset);
	double third = (offset & offset) - sqr(this->radius);

	double delta = sqr(second) - 4 * first * third;

	if (delta < 0) return false;

	double parameter = (-second - std::sqrt(delta)) / (2 * first);

	if (parameter < 0) return false;

	Point hit_point = camera + (vector * parameter);
	Vector hit_vector = hit_point - camera;
	Vector hit_normal = hit_point - this->position;

	return Intersection(hit_vector.size(), hit_point, hit_normal, this->color);
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
