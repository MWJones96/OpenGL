#pragma once

#include <GLEW/glew.h>
#include <vector>

class Mesh
{
public:
	Mesh(std::vector<GLfloat>& vertices, std::vector<GLfloat>& colors, std::vector<GLuint>& indices);
	~Mesh();
	void draw();
protected:
private:
	GLuint vaoID;
	GLuint eaoID;
	GLuint vboIDs[2];

	int numVertices;
	int numIndices;
};