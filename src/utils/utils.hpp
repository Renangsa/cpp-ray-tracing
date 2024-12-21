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

	ColorChannel() {}
	ColorChannel(double value) {
		this->value = static_cast<byte>(value * 255);
	}

	void operator=(double value) {
		this->value = static_cast<byte>(value * 255);
	}
};

struct Color {
   public:
	ColorChannel red;
	ColorChannel green;
	ColorChannel blue;

	// Color(byte red, byte green, byte blue) : def(red), def(green), def(blue) {}
	Color() {}
	Color(double red, double green, double blue) : def(red), def(green), def(blue) {}
};
