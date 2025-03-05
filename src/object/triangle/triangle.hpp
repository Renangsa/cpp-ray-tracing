#pragma once

#include "object/object.hpp"

class Triangle : public Object {
	// * Properties
   private:
	double area;
	Vector first;
	Vector second;
	Vector normal;

	// * Constructor
   public:
	Triangle(Point::ref first, Point::ref second, Point::ref third, Color color);

	// * Methods
   public:
	void print() override;
	Intersection intersect(Vector::ref vector, Point::ref camera) override;

	static void subscribe(Object::registry& registry);
	static Object::ptr construct(std::ifstream& input);
};
