#include "filesystem.hpp"

#include <fstream>

#include "utils/colorstream.hpp"

#define endl '\n'

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
