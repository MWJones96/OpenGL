#include "camera.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "GLM/glm.hpp"
#include <GLM/gtx/transform.hpp>

Camera::Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
{
	this->pos = pos;
	this->direction = glm::vec3(0.0f, 0.0f, 1.0f);
	this->up = glm::vec3(0.0f, 1.0f, 0.0f);
	this->projection = glm::perspective(fov, aspect, zNear, zFar);
}

Camera::~Camera()
{
}

glm::mat4 Camera::getProjection()
{
	return projection;
}

glm::mat4 Camera::getView()
{
	return glm::lookAt(pos, pos + direction, up);
}

void Camera::moveForward(float amt)
{
	pos.z += amt;
}

void Camera::moveAcross(float amt)
{
	pos.x += amt;
}