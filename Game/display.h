#pragma once
#include <string>
#include <GLFW/glfw3.h>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	~Display();
	GLFWwindow* getWindow();
protected:
private:
	Display(const Display& display) {}
	void operator=(const Display& display) {}
	GLFWwindow* window;
};
