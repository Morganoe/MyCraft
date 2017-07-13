#include "Model.hpp"

Model::Model(const std::vector<GLfloat>& vertex_positions)
{
    vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
            vertex_positions.size() * sizeof(vertex_positions[0]),
            vertex_positions.data(),
            GL_STATIC_DRAW);

    vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid *)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Model::~Model()
{
    glDeleteBuffers(1, &vbo);
}

void Model::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, vao);
}

void Model::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
