#pragma once

#include "utils/image.hpp"
#include "utils/utils.hpp"

struct pixelmap {
	static void save(string filename, Image::ptr image);
	static void save(string filename, Image::ref image);
};

struct simple_pixelmap {
	static void save(string filename, Image::ptr image);
	static void save(string filename, Image::ref image);
};
