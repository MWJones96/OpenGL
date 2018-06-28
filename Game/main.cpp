#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include "display.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "mesh.h"
#include "shader.h"

std::vector<GLfloat> vertices({
	0.0f, 0.0f, 0.0f,

	- 0.2f, 0.8f, 0.0f,
	0.2f, 0.8f, 0.0f,
	0.0f, 0.8f, 0.0f,
	0.0f, 1.0f, 0.0f,

	-0.2f, -0.8f, 0.0f,
	0.2f, -0.8f, 0.0f, 
	0.0f, -0.8f, 0.0f,
	0.0f, -1.0f, 0.0f,

	-0.8f, -0.2f, 0.0f,
	-0.8f, 0.2f, 0.0f,
	-0.8f, 0.0f, 0.0f,
	-1.0f, 0.0f, 0.0f,

	0.8f, -0.2f, 0.0f,
	0.8f, 0.2f, 0.0f,
	0.8f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f
});

std::vector<GLfloat> colors({
	1.0f, 1.0f, 1.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 0.0f
});

std::vector<GLuint> indices({
	// Top
	0, 1, 3,
	0, 3, 2,
	3, 1, 4,
	3, 4, 2,
	// Bottom
	0, 5, 7,
	0, 7, 6,
	7, 5, 8,
	7, 8, 6,
	// Left
	0, 9, 11,
	0, 11, 10,
	11, 9, 12,
	11, 12, 10,
	// Right
	0, 13, 15,
	0, 15, 14,
	15, 13, 16,
	15, 16, 14
});

int main(void)
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const std::string SCREEN_TITLE = "My OpenGL Game";

	Display d(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

	//Initialise GLEW
	if (glewInit() != GLEW_OK)
		return -1;

	Shader s("test_vertex.vs", "test_fragment.fs");
	Mesh m(vertices, colors, indices);
	Transform t;

	s.useShader();

	float counter = 0.0f;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(d.getWindow()))
	{
		d.clearScreen();

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);
		float absSinCounter = abs(sinCounter);

		t.getPos()->x = sinCounter;
		t.getRot()->z = counter * 5;
		t.getScale()->x = absSinCounter;
		t.getScale()->y = absSinCounter;

		s.update(t);
		m.draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(d.getWindow());

		/* Poll for and process events */
		glfwPollEvents();

		counter += 0.0001f;
	}

	return 0;
}