#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "point/point.hpp"
#include "utils/utils.hpp"
#include "vector/vector.hpp"

class Camera {
	// * Types
   public:
	using ref = Camera&;
	using ptr = Camera*;

	// * Properties
   public:
	std::string name;
	Point position;
	Point target;
	Vector up;
	Screen screen;
	double distance;

	// * Constructors
   public:
	Camera() {}
	Camera(string filename);
	Camera(std::string filename);
	Camera(std::ifstream& input);
};
