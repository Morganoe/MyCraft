#ifndef MODEL_HPP_INCLUDED
#define MODEL_HPP_INCLUDED

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

class Model
{
public:
    Model(const std::vector<GLfloat>& vertex_positions);
    ~Model();

    void bind();
    void unbind();

private:
    GLuint vao;
    GLuint vbo;

};

#endif // MODEL_HPP_INCLUDED
