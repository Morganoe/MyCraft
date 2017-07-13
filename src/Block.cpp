#include "Block.hpp"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
Block::Block(glm::vec3 pos, glm::vec3 size, glm::vec3 color)
{}

Block::~Block()
{}

void Block::draw()
{
    glBegin(GL_QUADS);
    {
        // Front face
        glVertex3f(x_pos - width/2, y_pos - height/2, z_pos - depth/2);
        glVertex3f(x_pos + width/2, y_pos - height/2, z_pos - depth/2);
        glVertex3f(x_pos + width/2, y_pos + height/2, z_pos - depth/2);
        glVertex3f(x_pos - width/2, y_pos + height/2, z_pos - depth/2);

        // Back face
        glVertex3f(x_pos - width/2, y_pos - height/2, z_pos + depth/2);
        glVertex3f(x_pos + width/2, y_pos - height/2, z_pos + depth/2);
        glVertex3f(x_pos + width/2, y_pos + height/2, z_pos + depth/2);
        glVertex3f(x_pos - width/2, y_pos + height/2, z_pos + depth/2);

        // Left face
        glVertex3f(x_pos - width/2, y_pos - height/2, z_pos - depth/2);
        glVertex3f(x_pos - width/2, y_pos - height/2, z_pos + depth/2);
        glVertex3f(x_pos - width/2, y_pos + height/2, z_pos + depth/2);
        glVertex3f(x_pos - width/2, y_pos + height/2, z_pos - depth/2);

        // Right face
        glVertex3f(x_pos + width/2, y_pos - height/2, z_pos + depth/2);
        glVertex3f(x_pos + width/2, y_pos - height/2, z_pos - depth/2);
        glVertex3f(x_pos + width/2, y_pos + height/2, z_pos - depth/2);
        glVertex3f(x_pos + width/2, y_pos + height/2, z_pos + depth/2);

        // Top face
        glVertex3f(x_pos + width/2, y_pos - height/2, z_pos + depth/2);
        glVertex3f(x_pos + width/2, y_pos - height/2, z_pos - depth/2);
        glVertex3f(x_pos - width/2, y_pos - height/2, z_pos - depth/2);
        glVertex3f(x_pos - width/2, y_pos - height/2, z_pos + depth/2);

        // Bottom face
        glVertex3f(x_pos - width/2, y_pos + height/2, z_pos + depth/2);
        glVertex3f(x_pos - width/2, y_pos + height/2, z_pos - depth/2);
        glVertex3f(x_pos + width/2, y_pos + height/2, z_pos - depth/2);
        glVertex3f(x_pos + width/2, y_pos + height/2, z_pos + depth/2);
    }
    glEnd();

}
