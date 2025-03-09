#include "colorstream.hpp"

#include <algorithm>

std::istream& operator>>(std::istream& input, ColorChannel& color) {
	double value;
	input >> value;
	color = value;

	return input;
}

std::ostream& operator<<(std::ostream& output, ColorChannel& color) {
	byte conversion = static_cast<byte>(color.value * 255.0);

	output << conversion;
	return output;
}

std::istream& operator>>(std::istream& input, Color& color) {
	input >> color.red >> color.green >> color.blue;
	return input;
}

std::ostream& operator<<(std::ostream& output, Color& color) {
	output << "(" << color.red << ", " << color.green << ", " << color.blue << ")";
	return output;
}

// ? Coefficient Operators
double clamp(double value) {
	return std::min(1.0, value);
}

Color operator*(Color& first, Color& second) {
	double red = clamp(first.red.value * second.red.value);
	double green = clamp(first.green.value * second.green.value);
	double blue = clamp(first.blue.value * second.blue.value);

	return {red, green, blue};
}

Color operator*(Color&& first, Color& second) {
	double red = clamp(first.red.value * second.red.value);
	double green = clamp(first.green.value * second.green.value);
	double blue = clamp(first.blue.value * second.blue.value);

	return {red, green, blue};
}

Color operator+(Color& first, Color& second) {
	double red = clamp(first.red.value + second.red.value);
	double green = clamp(first.green.value + second.green.value);
	double blue = clamp(first.blue.value + second.blue.value);

	return {red, green, blue};
}

Color operator*(Color& color, double value) {
	double red = clamp(color.red.value * value);
	double green = clamp(color.green.value * value);
	double blue = clamp(color.blue.value * value);

	return {red, green, blue};
}

Color operator*(Color&& color, double value) {
	double red = clamp(color.red.value * value);
	double green = clamp(color.green.value * value);
	double blue = clamp(color.blue.value * value);

	return {red, green, blue};
}
