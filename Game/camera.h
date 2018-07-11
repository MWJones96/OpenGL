#pragma once
#include "GLM/glm.hpp"

class Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar);
	~Camera();
	glm::mat4 getProjection();
	glm::mat4 getView();
	void moveForward(float amt);
	void moveAcross(float amt);
protected:
private:
	glm::vec3 pos;
	glm::vec3 direction;
	glm::vec3 up;

	glm::mat4 projection;
};