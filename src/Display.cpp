#include "Display.hpp"

Display::Display()
{
}

Display::~Display()
{
}

void Display::create_window(unsigned int width, unsigned int height, std::string title, 
                int openGL_min_version, int openGL_max_version, bool resizable)
{
    glfwInit();
    glewExperimental = GL_TRUE;
    glewInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, openGL_max_version);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, openGL_min_version);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_RESIZABLE, resizable);

    this->window.reset(glfwCreateWindow(width, height, title.c_str(), NULL, NULL));
    if (!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window.get());

    glewExperimental = GL_TRUE;
    glewInit();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);


}

void Display::clear()
{
    //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::update()
{
    glfwPollEvents();
    glfwSwapBuffers(window.get());
}

bool Display::is_open()
{
    return !glfwWindowShouldClose(window.get());
}
