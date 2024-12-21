#include "loader.hpp"

#include "plane/plane.hpp"
#include "sphere/sphere.hpp"

Object::registry load_object_types() {
	Object::registry registry;

	Sphere::subscribe(registry);
	Plane::subscribe(registry);

	return registry;
}
