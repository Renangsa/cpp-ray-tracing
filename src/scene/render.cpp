#include "scene.hpp"
// ! Implements Scene::render

#include <cmath>

#include "material/material.hpp"
#include "raycast/raycast.hpp"
#include "utils/colorstream.hpp"
#include "utils/intersection.hpp"

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
			auto intersection = raycast.trace(*this);

			image[i][j] = this->process_light(intersection, camera->position);
		}
	}

	return image_ptr;
}

Color Scene::process_light(Intersection::ref intersection, Point::ref spectator) {
	Material::ptr material = intersection.material;

	Color environmental = material->environment * this->environment;
	Color illumination;

	for (auto light : this->sources) {
		Vector light_vector = light->position - intersection.point;
		light_vector.normalize();

		double diffusion_value = intersection.normal & light_vector;

		auto part1 = light->color * intersection.color;
		auto part2 = part1 * material->diffusion;

		Color diffusion = part2 * diffusion_value;

		Vector spectator_vector = spectator - intersection.point;
		Vector reflection_vector = (intersection.normal * 2) * (intersection.normal & light_vector) - light_vector;

		spectator_vector.normalize();
		reflection_vector.normalize();

		double specular_component = std::pow(reflection_vector & spectator_vector, material->roughness);
		Color specular = light->color * material->specular * specular_component;

		illumination += diffusion + specular;
	}

	return environmental + illumination;
}
