#pragma once

#include <iostream>

#include "utils.hpp"

std::istream& operator>>(std::istream& input, ColorChannel& color);
std::ostream& operator<<(std::ostream& output, ColorChannel& color);

std::istream& operator>>(std::istream& input, Color& color);
std::ostream& operator<<(std::ostream& output, Color& color);
