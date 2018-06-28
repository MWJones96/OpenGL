#pragma once

#include <string>
#include "GLM/glm.hpp"
#include "GLEW/glew.h"
#include "transform.h"

class Shader
{
public:
	Shader(const std::string& vertFile, const std::string& fragFile);
	~Shader();
	void useShader();
	void update(Transform& transform);
protected:
private:
	GLuint shaderID;
};