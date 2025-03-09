#include "triangle.hpp"

#include <fstream>
#include <iostream>

#include "object/plane/plane.hpp"

Triangle::Triangle(Point::ref first, Point::ref second, Point::ref third, Color color) : Object(first, color) {
	this->first = second - first;
	this->second = third - first;
	this->normal = this->first * this->second;

	this->normal.normalize();

	double dot_one = this->first & this->first;
	double dot_two = this->second & this->second;
	double dot_three = this->first & this->second;

	this->area = (dot_one * dot_two) - (dot_three * dot_three);
}

Intersection Triangle::intersect(Vector::ref vector, Point::ref camera) {
	Plane plane(this->position, this->normal, this->color);

	auto intersection = plane.intersect(vector, camera);
	if (!intersection) return false;

	Point hit_point = intersection.point;
	Vector hit_vector = hit_point - this->position;

	double dot_one = this->first & this->first;
	double dot_two = this->second & this->second;
	double dot_three = this->first & this->second;

	double hit_one = hit_vector & this->first;
	double hit_two = hit_vector & this->second;

	double alpha = (dot_two * hit_one - dot_three * hit_two) / this->area;
	double beta = (dot_one * hit_two - dot_three * hit_one) / this->area;
	double gama = 1.0 - alpha - beta;

	if (alpha < 0 || alpha > 1) return false;
	if (beta < 0 || beta > 1) return false;
	if (gama < 0 || gama > 1) return false;

	return intersection;
}

void Triangle::print() {
	std::cout << this->position << this->first << " " << this->second << std::endl;
}

void Triangle::subscribe(Object::registry& registry) { registry["triangle"] = Triangle::construct; }
Object::ptr Triangle::construct(std::ifstream& input) {
	Point first;
	Point second;
	Point third;
	Color color;

	input >> first >> second >> third >> color;
	return new Triangle(first, second, third, color);
}
