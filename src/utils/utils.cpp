#include "utils.hpp"

double sqr(double value) {
	return value * value;
}

Color& Color::operator+=(Color& other) {
	this->red.value = other.red.value;
	this->green.value = other.green.value;
	this->blue.value = other.blue.value;

	return *this;
}

Color& Color::operator+=(Color&& other) {
	this->red.value = other.red.value;
	this->green.value = other.green.value;
	this->blue.value = other.blue.value;

	return *this;
}
