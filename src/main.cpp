#include <iostream>
#include <string>

#include "camera/camera.hpp"
#include "filesystem/filesystem.hpp"
#include "scene/scene.hpp"
#include "utils/image.hpp"

using std::cout, std::endl;

int main() {
	Scene scene("assets/scene5.in");

	Image::set render = scene.render();
	pixelmap::save("images/image.ppm", render);
}
