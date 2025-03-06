#pragma once

#include <vector>

#include "object/object.hpp"
#include "object/triangle/triangle.hpp"

class Mesh : public Object {
	// * Types
   public:
	using ref = Mesh&;
	using ptr = Mesh*;

	// * Properties
   private:
	double bound;
	std::vector<Point> vertex;
	std::vector<Triangle::ptr> faces;

	// * Constructor
   public:
	Mesh(Point position, Color color) : Object(position, color) {
		this->vertex.reserve(8);
		this->faces.reserve(8);
	}

	// * Methods
   public:
	void print() override;
	Intersection intersect(Vector::ref vector, Point::ref camera) override;

	static void subscribe(Object::registry& registry);
	static Object::ptr construct(std::ifstream& input);

   private:
	void preprocess();
	Point::ptr get_vertex(std::string& partition);
	static Object::ptr read_file(std::ifstream& input, Point::ref position);
};
