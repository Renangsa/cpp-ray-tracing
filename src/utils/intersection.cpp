#include "intersection.hpp"

Intersection::Intersection(double distance, Point point, Vector normal, Color color) : status(type::hit) {
	this->distance = distance;
	this->point = point;
	this->normal = normal;
	this->color = color;
	this->material = Materials::placeholder();
}
Intersection::Intersection(double distance, Point point, Vector normal, Color color, Material::ptr material) : status(type::hit) {
	this->distance = distance;
	this->point = point;
	this->normal = normal;
	this->color = color;
	this->material = material;
}

Intersection::operator bool() {
	return this->status == type::hit;
}

void Intersection::operator<<(const Intersection::ref other) {
	if (other.status == type::missed) return;
	if (other.status == type::undefined) return;

	if (this->status == type::undefined || this->distance > other.distance) {
		this->status = other.status;
		this->distance = other.distance;
		this->point = other.point;
		this->normal = other.normal;
		this->color = other.color;
		this->material = other.material;
	}
}
