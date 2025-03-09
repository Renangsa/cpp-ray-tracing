#pragma once

#define def(x) x(x)

typedef unsigned char byte;
typedef const char* string;

double sqr(double value);

struct Screen {
   public:
	int horizontal;
	int vertical;
};

struct ColorChannel {
	double value;

	ColorChannel() : value(0) {}
	ColorChannel(double value) : def(value) {}

	void operator=(double value) {
		this->value = value;
	}

	operator int() {
		return static_cast<int>(this->value);
	}
};

struct Color {
   public:
	ColorChannel red;
	ColorChannel green;
	ColorChannel blue;

	Color() : red(), green(), blue() {}
	Color(double value) : red(value), green(value), blue(value) {}
	Color(double red, double green, double blue) : def(red), def(green), def(blue) {}

	static Color black() { return {0, 0, 0}; }
	static Color white() { return {1, 1, 1}; }

	Color& operator+=(Color& other);
	Color& operator+=(Color&& other);
};
