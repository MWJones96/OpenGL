#pragma once

#include <GLEW/glew.h>
#include "obj_loader.h"
#include <vector>

class Mesh
{
public:
	Mesh(const std::string& fileName);
	~Mesh();
	void InitMesh(const IndexedModel& model);
	void draw();
protected:
private:
	enum Attribs
	{
		POSITION,
		COLOR,
		NORMAL,
		INDEX,

		NUM_BUFFERS
	};

	GLuint vaoID;
	GLuint vboIDs[NUM_BUFFERS];

	int numIndices;
};