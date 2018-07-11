#pragma once

#include <string>
#include "GLM/glm.hpp"
#include "GLEW/glew.h"
#include "transform.h"
#include "camera.h"

class Shader
{
public:
	Shader(const std::string& vertFile, const std::string& fragFile);
	~Shader();
	void useShader();
	GLuint getShaderID();
protected:
private:
	GLuint shaderID;
};