#pragma once

#include <iostream>
#include <map>
#include <string>

#include "utils/utils.hpp"

// ? Material
struct Material {
	// * Types
	using ref = Material&;
	using ptr = Material*;

	// * Properties
	std::string name;
	Color diffusion;
	Color specular;
	Color environment;
	Color reflection;
	Color transmission;
	double roughness;
};

struct Materials {
	// * Types
	using lib = std::map<std::string, Material::ptr>;

	// * Properties
	static lib library;

	// * Methods
	static Material::ptr placeholder();
	static void import(std::string filename);
};
