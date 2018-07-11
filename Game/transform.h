#pragma once

#include "GLM/glm.hpp"
#include "camera.h"

class Transform
{
public:
	Transform(const glm::vec3& t = glm::vec3(), const glm::vec3& r = glm::vec3(), const glm::vec3& s = glm::vec3(1.0f, 1.0f, 1.0f));
	~Transform();
	glm::mat4 getMatrix();
	glm::mat4 getMVP(const Camera& camera);

	inline glm::vec3* getPos() { return &translation; }
	inline glm::vec3* getRot() { return &rotation; }
	inline glm::vec3* getScale() { return &scale; }

	inline void setPos(glm::vec3& translation) { this->translation = translation; }
	inline void setRot(glm::vec3& rotation) { this->rotation = rotation; }
	inline void setScale(glm::vec3& scale) { this->scale = scale; }
protected:
private:
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;
};
