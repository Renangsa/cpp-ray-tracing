#pragma once

#include "object/object.hpp"
#include "point/point.hpp"
#include "utils/utils.hpp"
#include "vector/vector.hpp"

class Plane : public Object {
	// * Properties
   public:
	Vector normal;

	// * Constructor
   public:
	Plane(Point point, Vector normal, Color color) : Object(point, color), def(normal) {}

	// * Methods
   public:
	void print() override;
	bool intersect(Vector::ref vector, Point::ref camera) override;

	static void subscribe(Object::registry& registry);
	static Object::ptr construct(std::ifstream& input);
};
