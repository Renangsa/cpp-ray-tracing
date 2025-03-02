#include "camera.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include "raycast/raycast.hpp"

Camera::Camera(std::string filename) : Camera(filename.c_str()) {}

Camera::Camera(string filename) {
	std::ifstream file(filename);
	*this = Camera(file);
}

Camera::Camera(std::ifstream& file) {
	std::string reference;
	file >> reference;

	if (reference == "file:") {
		file >> reference;

		std::ifstream camera_file(reference);
		*this = Camera(camera_file);

		return;
	}

	// ? Camera name
	this->name = reference;

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
