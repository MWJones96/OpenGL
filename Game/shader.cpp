#include "transform.h"
#include "shader.h"
#include "camera.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>

Shader::Shader(const std::string& vertFile, const std::string& fragFile)
{
	GLuint vID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fID = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertexCode;
	std::string fragmentCode;

	std::ifstream vsStream(vertFile.c_str(), std::ios::in);

	if (vsStream.is_open())
	{
		std::stringstream sstr;
		sstr << vsStream.rdbuf();
		vertexCode = sstr.str();
	}
	else
	{
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", "test_vertex.vs");
		getchar();
	}

	vsStream.close();

	std::ifstream fsStream(fragFile.c_str(), std::ios::in);
	if (fsStream.is_open())
	{
		std::stringstream sstr;
		sstr << fsStream.rdbuf();
		fragmentCode = sstr.str();
	}
	else
	{
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", "test_fragment.fs");
		getchar();
	}

	fsStream.close();

	GLint result = GL_FALSE;
	int infoLogLength;

	const char* vPtr = vertexCode.c_str();
	glShaderSource(vID, 1, &vPtr, NULL);
	glCompileShader(vID);

	glGetShaderiv(vID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0)
	{
		std::vector<char> VertexShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(vID, infoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

	const char* fPtr = fragmentCode.c_str();
	glShaderSource(fID, 1, &fPtr, NULL);
	glCompileShader(fID);

	glGetShaderiv(fID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0)
	{
		std::vector<char> FragmentShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(fID, infoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	shaderID = glCreateProgram();
	glAttachShader(shaderID, vID);
	glAttachShader(shaderID, fID);
	glLinkProgram(shaderID);

	glGetProgramiv(shaderID, GL_LINK_STATUS, &result);
	glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0)
	{
		std::vector<char> ProgramErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(shaderID, infoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	glDetachShader(shaderID, vID);
	glDetachShader(shaderID, fID);

	glDeleteShader(vID);
	glDeleteShader(fID);
}

Shader::~Shader()
{
	glDeleteProgram(shaderID);
}

void Shader::useShader()
{
	glUseProgram(shaderID);
}

GLuint Shader::getShaderID()
{
	return shaderID;
}
