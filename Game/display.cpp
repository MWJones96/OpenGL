#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include "display.h"
#include <iostream>
#include <string>

Display::Display(int width, int height, const std::string& title)
{
	glfwInit();
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cerr << "Unable to initialise window";
	}

	glfwMakeContextCurrent(window);

	//Initialise GLEW
	if (glewInit() != GLEW_OK)
		std::cerr << "Error initialising GLEW. Exiting..." << std::endl;

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

Display::~Display()
{
	glfwTerminate();
}

GLFWwindow* Display::getWindow()
{
	return window;
}

void Display::clearScreen()
{
	//Clears the screen to a default background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}