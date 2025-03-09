#pragma once

#include <fstream>
#include <string>

#include "point/point.hpp"
#include "utils/colorstream.hpp"
#include "utils/utils.hpp"

class Light {
	// * Types
   public:
	using ref = Light&;
	using ptr = Light*;

	// * Properties
   public:
	Point position;
	Color color;

	// * Constructors
   public:
	Light(std::string filename);
	Light(std::ifstream& input);
};