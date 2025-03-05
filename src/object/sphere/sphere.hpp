#pragma once

#include "object/object.hpp"

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
