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
	//Clears the screen to a default blue background
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
}