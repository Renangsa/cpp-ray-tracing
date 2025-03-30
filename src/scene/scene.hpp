#pragma once

#include <vector>

#include "camera/camera.hpp"
#include "object/light.hpp"
#include "object/object.hpp"
#include "utils/image.hpp"
#include "utils/intersection.hpp"
#include "utils/utils.hpp"

struct SceneIterator {
   private:
	using ref = SceneIterator&;
	using self = SceneIterator;
	using storage = std::vector<Object::ptr>;

	int index;
	storage& data;

   public:
	SceneIterator(int index, storage& data) : def(index), def(data) {}
	SceneIterator(self::ref other) : index(other.index), data(other.data) {}

	bool operator==(self::ref other);
	bool operator!=(self::ref other);

	self operator++(int);
	self::ref operator++();

	Object::ptr operator*();
};

class Scene {
	// * Types
   public:
	using ref = Scene&;
	using ptr = Scene*;

   private:
	using views = std::vector<Camera::ptr>;
	using lights = std::vector<Light::ptr>;
	using storage = std::vector<Object::ptr>;

	// * Properties
   private:
	Color environment;
	Scene::views cameras;
	Scene::lights sources;
	Scene::storage objects;

	// * Constructors
   public:
	Scene(string filename);
	~Scene() {
		for (auto camera : this->cameras) {
			delete camera;
		}
		for (auto light : this->sources) {
			delete light;
		}
		for (auto object : this->objects) {
			delete object;
		}
	}

	// * Methods
   public:
	void insert(Object::ptr object);
	int size() const;
	Color color() const;

	Image::set render();
	Image::ptr render(Camera::ptr camera);
	Image::ptr render(Camera::ref camera);

   private:
	Color process_light(Intersection::ref intersection, Point::ref spectator, int depth);

	//* Operators
   public:
	Scene::ref operator<<(Object::ptr object);

	// * Iterator
	SceneIterator begin();
	SceneIterator end();
};
