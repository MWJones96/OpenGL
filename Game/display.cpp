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