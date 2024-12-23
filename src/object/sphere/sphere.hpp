#pragma once

#include "object/object.hpp"
#include "point/point.hpp"
#include "utils/intersection.hpp"
#include "utils/utils.hpp"
#include "vector/vector.hpp"

class Sphere : public Object {
	// * Properties
   private:
	double radius;

	// * Constructors
   public:
	Sphere(Point center, double radius, Color color) : Object(center, color), def(radius) {}

	// * Methods
   public:
	void print() override;
	Intersection intersect(Vector::ref vector, Point::ref camera) override;

	static void subscribe(Object::registry& registry);
	static Object::ptr construct(std::ifstream& input);
};
