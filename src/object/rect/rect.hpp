#pragma once

#include "object/object.hpp"

class Rect : public Object {
	// * Properties
   private:
	double size;
	Vector normal;

	// * Constructor
   public:
	Rect(Point center, Vector normal, double size, Color color) : Object(center, color), def(size), def(normal) {}

	// * Methods
   public:
	void print() override;
	Intersection intersect(Vector::ref vector, Point::ref camera) override;

	static void subscribe(Object::registry& registry);
	static Object::ptr construct(std::ifstream& input);
};
