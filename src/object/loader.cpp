#include "loader.hpp"

#include "plane/plane.hpp"
#include "rect/rect.hpp"
#include "sphere/sphere.hpp"
#include "triangle/triangle.hpp"

Object::registry load_object_types() {
	Object::registry registry;

	Sphere::subscribe(registry);
	Plane::subscribe(registry);
	Rect::subscribe(registry);
	Triangle::subscribe(registry);

	return registry;
}
