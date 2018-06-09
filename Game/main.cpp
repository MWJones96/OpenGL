#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include "display.h"
#include <iostream>
#include <vector>
#include "VAO.h"

int main(void)
{
	Display d(1280, 720, "My OpenGL game");

	//Initialise GLEW
	if (glewInit() != GLEW_OK)
		return -1;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(d.getWindow()))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glClearColor(0.1, 0.3, 0.5, 1.0);

		/* Swap front and back buffers */
		glfwSwapBuffers(d.getWindow());

		/* Poll for and process events */
		glfwPollEvents();
	}

	return 0;
}