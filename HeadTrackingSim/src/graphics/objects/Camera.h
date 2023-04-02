#pragma once

#include "Object.h"

class Camera : public Object
{
public:
	enum Mode
	{
		Orthographic,
		Perspective,
		UIMode
	};

	Camera();
	Camera(const std::string& name);

	const ObjectType type = ObjectType::Camera;

	void setMode(Mode mode);
	void setFov(float fov);
	void setZExtremes(float min, float max);
protected:
	glm::mat4 renderSelf(const glm::mat4& model) override;
private:
	float fov;
	float minv, maxv;
	static const glm::vec3 FRONT;
	static const glm::vec3 UP;
	Mode mode;
};