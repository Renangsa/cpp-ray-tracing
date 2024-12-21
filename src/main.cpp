#include <iostream>
#include <string>

#include "camera/camera.hpp"
#include "filesystem/filesystem.hpp"
#include "scene/scene.hpp"
#include "utils/image.hpp"

using std::cout, std::endl;

int main() {
	Scene scene("assets/scene.in");
	Camera camera("assets/camera.in");

	Image::ptr image = camera.render(scene);
	save_pixelmap("assets/image.ppm", *image);
}
