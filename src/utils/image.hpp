#pragma once

#include <functional>
#include <string>
#include <vector>

#include "utils/utils.hpp"

struct Image {
	// * Types
   public:
	using ref = Image&;
	using ptr = Image*;
	using set = std::vector<Image::ptr>;

   private:
	using raster = std::vector<Color>;
	using pixels = std::vector<Image::raster>;

	// * Properties
   public:
	const int width;
	const int height;
	std::string camera;

   private:
	Image::pixels data;

	// * Constructors
   public:
	Image(Screen screen, std::string camera) : Image(screen.horizontal, screen.vertical, camera) {}
	Image(int width, int height, std::string camera) : def(width), def(height), def(camera) {
		this->data = Image::pixels(height, Image::raster(width));
	}

	Image::raster& operator[](int index) { return this->data[index]; }
};
