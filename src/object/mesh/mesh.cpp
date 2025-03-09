#include "mesh.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "material/material.hpp"
#include "object/sphere/sphere.hpp"

Intersection Mesh::intersect(Vector::ref vector, Point::ref camera) {
	Sphere bounds(this->position, this->bound, this->color);

	Intersection hit_bounds = bounds.intersect(vector, camera);
	if (!hit_bounds) return false;

	Intersection hit_point;
	for (auto triangle : this->faces) {
		auto intersection = triangle->intersect(vector, camera);

		hit_point << intersection;
	}

	hit_point.material = this->material;
	return hit_point;
}

void Mesh::preprocess() {
	struct Distance {
		int start;
		int end;
		double value;
	};
	std::vector<Distance> distances;

	Distance bounds = {0, 0, 0};
	for (int i = 0; i < this->vertex.size(); i++) {
		for (int j = i + 1; j < this->vertex.size(); j++) {
			Vector offset = this->vertex[j] - this->vertex[i];

			double distance = offset.size();
			if (distance > bounds.value) {
				bounds = {i, j, distance};
			}
		}
	}

	Vector separation = this->vertex[bounds.end] - this->vertex[bounds.start];
	separation *= 0.5;

	this->position = this->vertex[bounds.start] + separation;
	this->bound = bounds.value / 2;
}

void Mesh::print() {
	std::cout << this->position << " " << this->color << " | Vertices: " << this->vertex.size() << " Faces: " << this->faces.size() << std::endl;
}

void Mesh::subscribe(Object::registry& registry) { registry["mesh"] = Mesh::construct; }
Object::ptr Mesh::construct(std::ifstream& input) {
	Point position;

	std::string reference;
	while (input >> reference) {
		if (reference == "file:") {
			input >> reference;

			std::ifstream mesh_file(reference);
			return Mesh::read_file(mesh_file, position);
		} else if (reference == "position:") {
			input >> position;
		}
	}

	return new Mesh(Point::zero(), Color::black());
}

Object::ptr Mesh::read_file(std::ifstream& input, Point::ref position) {
	std::string prefix;
	Mesh::ptr mesh = new Mesh(position, Color::white());

	while (input >> prefix) {
		if (prefix == "v") {
			// ? Vertice definiton
			Point vertex;
			input >> vertex;

			vertex += position;

			mesh->vertex.push_back(vertex);
		} else if (prefix == "f") {
			Point::ptr first, second, third;

			std::string partition;

			input >> partition;
			first = mesh->get_vertex(partition);

			input >> partition;
			second = mesh->get_vertex(partition);

			input >> partition;
			third = mesh->get_vertex(partition);

			Triangle::ptr face = new Triangle(*first, *second, *third, mesh->color);
			mesh->faces.push_back(face);
		} else if (prefix == "o") {
			std::string name;
			input >> name;
		} else if (prefix == "mtllib") {
			std::string material_file;
			input >> material_file;

			Materials::import(material_file);
		} else if (prefix == "usemtl") {
			std::string material;
			input >> material;

			mesh->material = Materials::library[material];
		} else {
			std::string _;
			std::getline(input, _);
		}
	}

	mesh->preprocess();

	return mesh;
}

Point::ptr Mesh::get_vertex(std::string& partition) {
	std::istringstream stream(partition);

	int index;
	stream >> index;

	index -= 1;

	return &this->vertex[index];
}
