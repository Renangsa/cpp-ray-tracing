#pragma once

#include <vector>

#include "point/point.hpp"
#include "scene/scene.hpp"
#include "utils/image.hpp"
#include "utils/utils.hpp"
#include "vector/vector.hpp"

class Camera {
	// * Properties
   private:
	Point position;
	Point target;
	Vector up;
	Screen screen;
	double distance;

	// * Constructors
   public:
	Camera(string filename);

	Image::ptr render(Scene::ref scene);
};
