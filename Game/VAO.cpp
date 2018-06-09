#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &vaoID);
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &vaoID);
	glDeleteBuffers(vboIDs->size(), &(vboIDs->at(0)));
	delete vboIDs;
}

GLuint VAO::getVAO()
{
	return vaoID;
}

std::vector<GLuint>* VAO::getVBOs()
{
	return vboIDs;
}

void VAO::bindVAO()
{
	glBindVertexArray(vaoID);
}

void VAO::unbindVAO()
{
	glBindVertexArray(0);
}

void VAO::bindVBO(GLuint vboID)
{
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
}

void VAO::unbindVBO()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VAO::loadToVAO(const std::vector<GLfloat>& data)
{
	bindVAO();
	GLuint vboID;
	glGenBuffers(1, &vboID);
	vboIDs->push_back(vboID);

	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	unbindVAO();
}