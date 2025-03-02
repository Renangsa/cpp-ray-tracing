#include "raycast/raycast.hpp"
#include "scene.hpp"

Image::set Scene::render() {
	Image::set images;

	for (auto camera : this->cameras) {
		images.push_back(this->render(camera));
	}

	return images;
}

Image::ptr Scene::render(Camera::ref camera) {
	return this->render(&camera);
}

Image::ptr Scene::render(Camera::ptr camera) {
	Vector target = camera->target - camera->position;
	Vector offset = camera->up * target;

	target.normalize();
	offset.normalize();

	Vector upside = target * offset;

	double vertical_size = (camera->screen.vertical - 1) / 2.0;
	double horizontal_size = (camera->screen.horizontal - 1) / 2.0;

	Vector vertical_offset = upside * (2 * vertical_size / (camera->screen.vertical - 1));
	Vector horizontal_offset = offset * (2 * horizontal_size / (camera->screen.horizontal - 1));

	Vector corner = (target * camera->distance) - (offset * horizontal_size) - (upside * vertical_size);

	Image::ptr image_ptr = new Image(camera->screen, camera->name);

	Image::ref image = *image_ptr;
	for (int i = 0; i < camera->screen.vertical; i++) {
		for (int j = 0; j < camera->screen.horizontal; j++) {
			Vector ray = corner + (horizontal_offset * j) + (vertical_offset * (camera->screen.horizontal - i - 1));

			RayCast raycast(camera->position, ray);
			Color color = raycast.trace(*this);

			image[i][j] = color;
		}
	}

	return image_ptr;
}
