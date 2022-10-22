#pragma once

#include "Object.h";

class Camera : public Object
{
public:
	enum Mode
	{
		Orthographic,
		Perspective
	};
public:
	Camera();
	Camera(const std::string& name);

	const ObjectType type = ObjectType::Camera;

	void setMode(Mode mode);
	void setFov(float fov);
	void setZExtremes(float min, float max);
	void setOrthoBox(float left, float right, float bottom, float top);
protected:
	virtual glm::mat4 renderSelf(glm::mat4 model) const override;
private:
	float fov;
	float minv, maxv;
	glm::vec4 orthoBoxSize;
	static const glm::vec3 FRONT;
	static const glm::vec3 UP;
	Mode mode;
};