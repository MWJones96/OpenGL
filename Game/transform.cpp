#include "GLM/glm.hpp"
#include "transform.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "GLM/gtx/transform.hpp"

Transform::Transform(const glm::vec3& t, const glm::vec3& r, const glm::vec3& s)
{
	this->translation = t;
	this->rotation = r;
	this->scale = s;
}

Transform::~Transform()
{
}

glm::mat4 Transform::getMatrix()
{
	glm::mat4 translateMat = glm::translate(translation);
	glm::mat4 scaleMat = glm::scale(scale);

	glm::mat4 rotX = glm::rotate(rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotY = glm::rotate(rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rotZ = glm::rotate(rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

	glm::mat4 rotMat = rotX * rotY * rotZ;

	return translateMat * rotMat * scaleMat;
}
