#ifndef __DISPLAY_HPP_
#define __DISPLAY_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <memory>
#include <string>

#include <iostream>

struct glfwDeleter
{
	void operator()(GLFWwindow *wnd)
	{
		glfwDestroyWindow(wnd);
	}
};

typedef std::unique_ptr<GLFWwindow, glfwDeleter> smart_window;

class Display
{
private:
	smart_window window;

public:
	Display();
	~Display();

	void create_window(unsigned int width, unsigned int height, std::string title,
			int openGLMinVersion, int openGLMaxVersion, bool resizeable);

	void close();

	void clear();
	void update();

	bool is_open();

};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void window_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif
