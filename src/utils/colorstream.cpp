#include "colorstream.hpp"

std::istream& operator>>(std::istream& input, ColorChannel& color) {
	double value;
	input >> value;
	color = value;

	return input;
}

std::ostream& operator<<(std::ostream& output, ColorChannel& color) {
	output << (int)color.value;
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
