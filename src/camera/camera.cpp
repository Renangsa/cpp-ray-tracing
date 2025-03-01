#include "camera.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include "raycast/raycast.hpp"

Camera::Camera(string filename) {
	std::ifstream file(filename);

	// ? Input values
	double distance;
	int horizontal, vertical;

	// ? Reading Values
	file >> this->position;
	file >> this->target;
	file >> this->up;
	file >> distance >> horizontal >> vertical;

	this->screen = {horizontal, vertical};
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
	for (int i = 0; i < this->screen.vertical; i++) {
		for (int j = 0; j < this->screen.horizontal; j++) {
			Vector ray = corner + (horizontal_offset * j) + (vertical_offset * (this->screen.horizontal - i - 1));

			RayCast raycast(this->position, ray);
			Color color = raycast.trace(scene);

			image[i][j] = color;
		}
	}

	return image_ptr;
}
