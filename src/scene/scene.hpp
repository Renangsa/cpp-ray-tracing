#pragma once

#include <vector>

#include "object/object.hpp"
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
	using storage = std::vector<Object::ptr>;

	// * Properties
   private:
	Scene::storage objects;

	// * Constructors
   public:
	Scene(string filename);

	// * Methods
   public:
	void insert(Object::ptr object);
	int size() const;

	Scene::ref operator<<(Object::ptr object);

	// * Iterator
	SceneIterator begin();
	SceneIterator end();
};
