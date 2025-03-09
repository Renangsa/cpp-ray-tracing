#pragma once

#include "point/point.hpp"
#include "scene/scene.hpp"
#include "utils/intersection.hpp"
#include "utils/utils.hpp"
#include "vector/vector.hpp"

class RayCast {
	// * Properties
   private:
	Vector::ref ray;
	Point::ref origin;

	// * Constructor
   public:
	RayCast(Point::ref origin, Vector::ref ray) : def(origin), def(ray) {}

	// * Methods
   public:
	Intersection trace(Scene::ref scene);
};
