#pragma once

#include "utils/image.hpp"
#include "utils/utils.hpp"

struct pixelmap {
	static void save(string filename, Image::ptr image);
	static void save(string filename, Image::ref image);
	static void save(std::string filename, Image::set render);
};

struct simple_pixelmap {
	static void save(string filename, Image::ptr image);
	static void save(string filename, Image::ref image);
	static void save(std::string filename, Image::set render);
};
