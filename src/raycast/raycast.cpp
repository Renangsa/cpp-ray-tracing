#include "raycast.hpp"

Intersection RayCast::trace(Scene::ref scene) {
	Intersection hit_point;

	for (auto object : scene) {
		auto intersection = object->intersect(this->ray, this->origin);

		hit_point << intersection;
	}

	return hit_point;
}
