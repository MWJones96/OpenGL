#pragma once
#include <GLEW/glew.h>

class Mesh
{
public:
	Mesh();
	~Mesh();
protected:
private:
	Mesh(const Mesh& mesh) {}
	void operator=(const Mesh& mesh) {}
	GLuint m_vaoID;
};
