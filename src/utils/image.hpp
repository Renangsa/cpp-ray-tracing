#pragma once

#include <functional>
#include <vector>

#include "utils/utils.hpp"

struct Image {
	// * Types
   public:
	using ref = Image&;
	using ptr = Image*;

   private:
	using raster = std::vector<Color>;
	using pixels = std::vector<Image::raster>;

	// * Properties
   public:
	const int width;
	const int height;

   private:
	Image::pixels data;

	// * Constructors
   public:
	Image(Screen screen) : Image(screen.horizontal, screen.vertical) {}
	Image(int width, int height) : def(width), def(height) {
		this->data = Image::pixels(height, Image::raster(width));
	}

	Image::raster& operator[](int index) { return this->data[index]; }
};
