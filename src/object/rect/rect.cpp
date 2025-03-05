#include "rect.hpp"

#include <cmath>
#include <fstream>
#include <iostream>

#include "object/plane/plane.hpp"
#include "point/point.hpp"
#include "utils/colorstream.hpp"
#include "utils/utils.hpp"
#include "vector/vector.hpp"

Intersection Rect::intersect(Vector::ref vector, Point::ref camera) {
	Plane plane(this->position, this->normal, this->color);

	auto intersection = plane.intersect(vector, camera);
	if (!intersection) return false;

	double offset = this->size / 2;
	Vector hit_vector = intersection.point - this->position;

	if (std::abs(hit_vector.x) > offset) return false;
	if (std::abs(hit_vector.y) > offset) return false;
	if (std::abs(hit_vector.z) > offset) return false;

	return intersection;
}

void Rect::print() {
	std::cout << this->position << " " << this->normal << " " << this->size << " " << this->color << std::endl;
}

void Rect::subscribe(Object::registry& registry) { registry["rect"] = Rect::construct; }
Object::ptr Rect::construct(std::ifstream& input) {
	Point center;
	Vector normal;
	double size;
	Color color;

	input >> center >> normal >> size >> color;
	return new Rect(center, normal, size, color);
}
