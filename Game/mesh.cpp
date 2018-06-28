#include "mesh.h"
#include <GLEW/glew.h>
#include <iostream>
#include <vector>

Mesh::Mesh(std::vector<GLfloat>& vertices, std::vector<GLfloat>& colors, std::vector<GLuint>& indices)
{
	numVertices = vertices.size() / 3;
	numIndices = indices.size();

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	glGenBuffers(2, vboIDs);

	glBindBuffer(GL_ARRAY_BUFFER, vboIDs[0]);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vboIDs[1]);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(colors[0]), &colors[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &eaoID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eaoID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteBuffers(2, vboIDs);
	glDeleteVertexArrays(1, &vaoID);
}

void Mesh::draw()
{
	glBindVertexArray(vaoID);
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}