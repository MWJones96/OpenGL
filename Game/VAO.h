#pragma once
#include <glew/glew.h>
#include <vector>

class VAO
{
private:
	GLuint vaoID;
	std::vector<GLuint>* vboIDs = new std::vector<GLuint>();
public:
	VAO();
	~VAO();
	GLuint getVAO();
	std::vector<GLuint>* getVBOs();
	void bindVAO();
	void unbindVAO();
	void bindVBO(GLuint vbo);
	void unbindVBO();
	void loadToVAO(const std::vector<GLfloat>& vertices);
};
