#include "light.hpp"

#include <fstream>

Light::Light(std::string filename) {
	std::ifstream file(filename);
	*this = Light(file);
}

Light::Light(std::ifstream& input) {
	input >> this->position >> this->color;
}
