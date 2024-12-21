#include "scene.hpp"

#include <fstream>
#include <map>
#include <string>

#include "object/loader.hpp"
#include "utils/utils.hpp"

// Scene
Scene::Scene(string filename) {
	std::ifstream file(filename);

	Object::registry registry = load_object_types();

	std::string object_type;
	while (file >> object_type) {
		if (!registry.count(object_type)) {
			break;
		}

		Object::factory factory = registry[object_type];
		Object::ptr object = factory(file);

		this->insert(object);
	}
}

Scene::ref Scene::operator<<(Object::ptr object) {
	this->objects.push_back(object);
	return *this;
}

int Scene::size() const { return this->objects.size(); }
void Scene::insert(Object::ptr object) { this->objects.push_back(object); }

SceneIterator Scene::begin() { return {0, this->objects}; }
SceneIterator Scene::end() { return {this->size(), this->objects}; }

// SceneIterator
bool SceneIterator::operator==(self::ref other) { return this->index == other.index; }
bool SceneIterator::operator!=(self::ref other) { return this->index != other.index; }
Object::ptr SceneIterator::operator*() { return this->data[this->index]; }

SceneIterator::ref SceneIterator::operator++() {
	this->index++;
	return *this;
}

SceneIterator SceneIterator::operator++(int) {
	auto copy = *this;
	this->operator++();
	return copy;
}
