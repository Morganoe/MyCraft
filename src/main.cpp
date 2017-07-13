#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Display.hpp"
#include "Application.hpp"

#include <string>

int main()
{
	constexpr unsigned int SCR_WIDTH = 640;
	constexpr unsigned int SCR_HEIGHT = 480;
	std::string title = "Learn OpenGL";
    constexpr unsigned int GL_MAJOR = 3;
    constexpr unsigned int GL_MINOR = 3;
    constexpr bool RESIZEABLE = true;


	Display display;

	display.create_window(SCR_WIDTH, SCR_HEIGHT, title, GL_MINOR, GL_MAJOR, RESIZEABLE);

    Application app;

    app.run_main_game_loop(display);

    return 0;

}
