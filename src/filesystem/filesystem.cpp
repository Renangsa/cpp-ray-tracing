#include "filesystem.hpp"

#include <fstream>

#include "utils/colorstream.hpp"

#define endl '\n'

void save_pixelmap(string filename, Image::ref image) {
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
