#include "camera.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

Camera::Camera(string filename) {
	std::ifstream file(filename);

	// ? Input values
	double px, py, pz;
	double tx, ty, tz;
	double ux, uy, uz;
	double distance;
	int horizontal, vertical;

	// ? Reading Values
	file >> px >> py >> pz;
	file >> tx >> ty >> tz;
	file >> ux >> uy >> uz;
	file >> distance >> horizontal >> vertical;

	// ? Setting values to object properties
	this->position = Point(px, py, pz);
	this->target = Point(tx, ty, tz);

	this->up = Vector(ux, uy, uz);
	this->screen = {vertical, horizontal};

	this->distance = distance;
}

Image::ptr Camera::render(Scene::ref scene) {
	Vector target = this->target - this->position;
	Vector offset = this->up * target;

	target.normalize();
	offset.normalize();

	Vector upside = target * offset;

	double vertical_size = (this->screen.vertical - 1) / 2.0;
	double horizontal_size = (this->screen.horizontal - 1) / 2.0;

	Vector vertical_offset = upside * (2 * vertical_size / (this->screen.vertical - 1));
	Vector horizontal_offset = offset * (2 * horizontal_size / (this->screen.horizontal - 1));

	Vector corner = (target * this->distance) - (offset * horizontal_size) - (upside * vertical_size);

	Image::ptr image_ptr = new Image(this->screen);

	Image::ref image = *image_ptr;
	for (int i = 0; i < this->screen.horizontal; i++) {
		for (int j = 0; j < this->screen.vertical; j++) {
			Vector ray = corner + (horizontal_offset * i) + (vertical_offset * (this->screen.horizontal - j - 1));

			bool intersected = false;
			for (auto object : scene) {
				intersected = object->intersect(ray, this->position);

				if (intersected) {
					image[i][j] = object->color;
					break;
				}
			}

			if (!intersected) {
				image[i][j] = {0, 0, 0};
			}
		}
	}

	return image_ptr;
}
