#include "intersection.hpp"

Intersection::operator bool() {
	return this->status == type::hit;
}

void Intersection::operator<<(const Intersection::ref other) {
	if (other.status == type::missed) return;
	if (other.status == type::undefined) return;

	if (this->status == type::undefined) {
		this->status = other.status;
		this->distance = other.distance;
		this->color = other.color;
		return;
	}

	if (this->distance > other.distance) {
		this->status = other.status;
		this->distance = other.distance;
		this->color = other.color;
	}
}
