#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#include <glm/glm.hpp>

#include "Block.hpp"

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int test(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    
    if (!glewInit())
        exit(EXIT_FAILURE);

    if (!glfwInit())
        exit(EXIT_FAILURE);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glfwMakeContextCurrent(window);

    // Allows for key listening on window focus.
    glfwSetKeyCallback(window, key_callback);

    Block test(glm::vec3(0,0,0), glm::vec3(1,1,1), glm::vec3(0,0,0));
    
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;

        glfwGetFramebufferSize(window, &width, &height);
        
        ratio = width / (float) height;
        
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        

        glRotatef((float) glfwGetTime() * 50.f, 
                  (float) glfwGetTime() * 20.f, 
                  (float) glfwGetTime() * 10.f, 
                  1.f);

        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
        glColor3f(1.f,0.f,0.f);
        test.draw();

        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        glColor3f(1.f,1.f,1.f);
        test.draw();

        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

