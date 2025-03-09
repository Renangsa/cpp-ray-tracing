#include "material.hpp"

#include <fstream>
#include <string>

#include "utils/colorstream.hpp"

Materials::lib Materials::library = Materials::lib();

Material::ptr Materials::placeholder() {
	if (!Materials::library.count("placeholder")) {
		Material::ptr material = new Material();

		material->name = "placeholder";
		material->diffusion = 0.8;
		material->specular = 0.5;
		material->environment = 1.0;
		material->roughness = 250;

		Materials::library["placeholder"] = material;
	}

	return Materials::library["placeholder"];
}

void Materials::import(std::string filename) {
	std::ifstream file(filename);

	Material::ptr material;
	std::string prefix;
	while (file >> prefix) {
		if (prefix == "newmtl") {
			std::string name;
			file >> name;

			material = new Material();

			material->name = name;
			Materials::library[name] = material;
		} else if (prefix == "Kd") {
			file >> material->diffusion;
		} else if (prefix == "Ks") {
			file >> material->specular;
		} else if (prefix == "Ka") {
			file >> material->environment;
		} else if (prefix == "Ns") {
			file >> material->roughness;
		} else {
			std::string _;
			std::getline(file, _);
		}
	}
}
