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
	byte value;

	ColorChannel() : value(0) {}
	ColorChannel(byte value) : def(value) {}
	ColorChannel(double value) {
		this->value = static_cast<byte>(value * 255);
	}

	void operator=(double value) {
		this->value = static_cast<byte>(value * 255);
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

	// Color(byte red, byte green, byte blue) : def(red), def(green), def(blue) {}
	Color() : red(), green(), blue() {}
	Color(byte red, byte green, byte blue) : def(red), def(green), def(blue) {}
	Color(double red, double green, double blue) : def(red), def(green), def(blue) {}

	static Color black() { return {0.0, 0.0, 0.0}; }
	static Color white() { return {1.0, 1.0, 1.0}; }
};
