#include "raycast.hpp"

Color RayCast::trace(Scene::ref scene) {
	Intersection hit_point;

	for (auto object : scene) {
		auto intersection = object->intersect(this->ray, this->origin);

		hit_point << intersection;
	}

	if (hit_point)
		return hit_point.color;
	else
		return scene.color();
}
