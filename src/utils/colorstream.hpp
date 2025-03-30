#pragma once

#include <iostream>

#include "material/material.hpp"
#include "utils.hpp"

std::istream& operator>>(std::istream& input, ColorChannel& color);
std::ostream& operator<<(std::ostream& output, ColorChannel& color);

std::istream& operator>>(std::istream& input, Color& color);
std::ostream& operator<<(std::ostream& output, Color& color);

// ? Coefficient Operators
Color operator*(Color&& first, Color& second);
Color operator*(Color& first, Color& second);
Color operator+(Color&& first, Color& second);
Color operator+(Color& first, Color& second);

Color operator*(Color&& color, double value);
Color operator*(Color& color, double value);
