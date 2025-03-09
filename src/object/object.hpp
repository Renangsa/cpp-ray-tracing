#pragma once

#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <string>

#include "material/material.hpp"
#include "point/point.hpp"
#include "utils/colorstream.hpp"
#include "utils/intersection.hpp"
#include "utils/utils.hpp"
#include "vector/vector.hpp"

class Object {
	// * Types
   public:
	using ref = Object&;
	using ptr = Object*;
	using factory = std::function<Object::ptr(std::ifstream&)>;
	using registry = std::map<std::string, Object::factory>;

	// * Properties
   public:
	Point position;
	Color color;
	Material::ptr material;

	// * Constructors
   protected:
	Object(Point position, Color color) : def(position), def(color), material(Materials::placeholder()) {}
	Object(Point position, Color color, Material::ptr material) : def(position), def(color), def(material) {}

	// * Methods
   public:
	virtual void print() = 0;
	virtual Intersection intersect(Vector::ref vector, Point::ref camera) = 0;
};
