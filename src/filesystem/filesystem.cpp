#include "filesystem.hpp"

#include <fstream>

#include "utils/colorstream.hpp"

#define endl '\n'

// ? Pixel Map
void pixelmap::save(std::string filename, Image::set render) {
	if (render.size() == 1) {
		return pixelmap::save(filename.c_str(), *render[0]);
	}

	int separator = filename.find('.');
	std::string prefix = filename.substr(0, separator);
	std::string suffix = filename.substr(separator);

	for (auto image : render) {
		std::string image_name = prefix + "_" + image->camera + suffix;
		pixelmap::save(image_name.c_str(), *image);
	}
}

void pixelmap::save(string filename, Image::ptr image) {
	return pixelmap::save(filename, *image);
}

void pixelmap::save(string filename, Image::ref image) {
	std::ofstream file(filename);

	file << "P6" << endl;
	file << image.width << " " << image.height << endl;
	file << 255 << endl;

	for (int i = 0; i < image.height; i++) {
		for (int j = 0; j < image.width; j++) {
			Color pixel = image[i][j];
			file << pixel.red << pixel.green << pixel.blue;
		}
	}
}

// ? Simple Pixel Map
void simple_pixelmap::save(std::string filename, Image::set render) {
	if (render.size() == 1) {
		return simple_pixelmap::save(filename.c_str(), *render[0]);
	}

	int separator = filename.find('.');
	std::string prefix = filename.substr(0, separator);
	std::string suffix = filename.substr(separator + 1);

	for (auto image : render) {
		std::string image_name = prefix + "_" + image->camera + suffix;
		simple_pixelmap::save(image_name.c_str(), *image);
	}
}

void simple_pixelmap::save(string filename, Image::ptr image) {
	return simple_pixelmap::save(filename, *image);
}

void simple_pixelmap::save(string filename, Image::ref image) {
	std::ofstream file(filename);

	file << "P3" << endl;
	file << image.width << " " << image.height << endl;
	file << 255 << endl;

	for (int i = 0; i < image.height; i++) {
		for (int j = 0; j < image.width; j++) {
			Color pixel = image[i][j];
			file << (int)pixel.red << " ";
			file << (int)pixel.green << " ";
			file << (int)pixel.blue << endl;
		}
	}
}
