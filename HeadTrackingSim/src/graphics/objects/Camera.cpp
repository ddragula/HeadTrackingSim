#include "Camera.h"

#include "../../App.h"
#include "../../registry/ShadersRegistry.h"
#include "../../utils/Debug.h"

const glm::vec3 Camera::FRONT = glm::vec3(0.0f, 0.0f, -1.0f);
const glm::vec3 Camera::UP = glm::vec3(0.0f, 1.0f, 0.0f);

Camera::Camera() : Camera("Unnamed Camera") {}

Camera::Camera(const std::string& name) : Object(name), mode(Camera::Perspective), fov(45.0f), minv(0.1f), maxv(100.0f), orthoBoxSize(-1.0f, 1.0f, -1.0f, 1.0f) {}

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

void Camera::setOrthoBox(float left, float right, float bottom, float top)
{
	orthoBoxSize = { left, right, bottom, top };
}

glm::mat4 Camera::renderSelf(glm::mat4 model) const
{
	const glm::mat4& nm = modelTransform(model);

	const glm::mat4& view = glm::lookAt(position, position + FRONT, UP);
	glm::mat4 projection;

	if (mode == Mode::Perspective) {
		projection = glm::perspective(glm::radians(fov), (float)App::getInstance()->getWidth() / (float)App::getInstance()->getHeight(), minv, maxv);
	}
	else
	{
		projection = glm::ortho(orthoBoxSize.x, orthoBoxSize.y, orthoBoxSize.z, orthoBoxSize.w, 0.1f, 100.0f);
	}

	ShadersRegistry::setVPMatrix(projection * view);

	return nm;
}