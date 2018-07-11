#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "GLM/gtx/transform.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "display.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "mesh.h"
#include "shader.h"
#include "camera.h"

int main(void)
{
	const int SCREEN_WIDTH = 1600;
	const int SCREEN_HEIGHT = 900;
	const float ASPECT_RATIO = SCREEN_WIDTH / SCREEN_HEIGHT;

	const std::string SCREEN_TITLE = "My OpenGL Game";

	Display d(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

	Mesh mesh("monkey_mesh.obj");
	Camera c(glm::vec3(0.0f, 0.0f, -3.0f), 70.0f, ASPECT_RATIO, 0.1f, 100.0f);
	Shader s("test_vertex.vs", "test_fragment.fs");
	s.useShader();

	GLuint matUniform = glGetUniformLocation(s.getShaderID(), "MVP");

	glm::mat4 pos = glm::translate(glm::vec3(0.0f, 0.0f, 0.0f));
	glm::mat4 scale = glm::scale(glm::vec3(0.5f, 0.5f, 0.5f));

	glm::mat4 rotX = glm::rotate(0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotY = glm::rotate(3.141592f, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rotZ = glm::rotate(0.0f, glm::vec3(0.0f, 0.0f, 1.0f));

	glm::mat4 rotMat = rotX * rotY * rotZ;

	glm::mat4 m = pos * rotMat * scale;
	glm::mat4 v = c.getView();
	glm::mat4 p = c.getProjection();

	glm::mat4 mvp = p * v * m;

	glUniformMatrix4fv(matUniform, 1, GL_FALSE, &mvp[0][0]);

	s.useShader();

	glfwSetInputMode(d.getWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(d.getWindow()))
	{
		double xPos, yPos;
		glfwGetCursorPos(d.getWindow(), &xPos, &yPos);

		double xDelta = SCREEN_WIDTH / 2 - xPos;
		double yDelta = SCREEN_HEIGHT / 2 - yPos;

		c.moveAcross((float)xDelta / -1000.0f);
		c.moveForward((float)yDelta / -1000.0f);

		v = c.getView();
		mvp = p * v * m;
		glUniformMatrix4fv(matUniform, 1, GL_FALSE, &mvp[0][0]);

		glfwSetCursorPos(d.getWindow(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

		d.clearScreen();
		mesh.draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(d.getWindow());

		glfwPollEvents();
	}

	return 0;
}