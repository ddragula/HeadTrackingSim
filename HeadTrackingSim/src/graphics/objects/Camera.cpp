#include "Camera.h"

#include "../../App.h"
#include "../../registry/ShadersRegistry.h"
#include "../../utils/Debug.h"

const glm::vec3 Camera::FRONT = glm::vec3(0.0f, 0.0f, -1.0f);
const glm::vec3 Camera::UP = glm::vec3(0.0f, 1.0f, 0.0f);

Camera::Camera() : Camera("Unnamed Camera") {}

Camera::Camera(const std::string& name) : Object(name), mode(Camera::Perspective), fov(45.0f), minv(0.1f), maxv(100.0f) {}

void Camera::setMode(Mode mode)
{
	this->mode = mode;
}

void Camera::setFov(float fov)
{
	this->fov = fov;
}

void Camera::setZExtremes(float min, float max)
{
	this->minv = min;
	this->maxv = max;
}

glm::mat4 Camera::renderSelf(const glm::mat4& model) const
{
	const auto& nm = modelTransform(model);

	const auto aspectRatio = (float)App::getInstance()->getWidth() / (float)App::getInstance()->getHeight();

	glm::mat4 projection;

	if (mode == Mode::Perspective) {
		projection = glm::perspective(glm::radians(fov), aspectRatio, minv, maxv);
	}
	else
	{
		projection = glm::ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f, 0.1f, 100.0f);
	}

	if (mode == Mode::FixedOrtographic) {
		const glm::mat4& view = glm::mat4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, -2, 1
		);

		ShadersRegistry::setVPMatrix(projection * view);
		return nm;
	}

	const auto act_pos_v4 = model * glm::vec4(position, 0.0f);
	const auto act_front_v4 = glm::normalize(nm * glm::vec4(FRONT, 0.0f));
	const auto act_up_v4 = glm::normalize(nm * glm::vec4(UP, 0.0f));

	const auto act_pos = glm::vec3(act_pos_v4);
	const auto act_front = glm::vec3(act_front_v4);
	const auto act_up = glm::vec3(act_up_v4);

	const glm::mat4& view = glm::lookAt(act_pos, act_pos + act_front, act_up);

	ShadersRegistry::setVPMatrix(projection * view);
	return nm;
}