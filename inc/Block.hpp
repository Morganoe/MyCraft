
#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>


class Block
{
private:
    float x_pos, y_pos, z_pos;
    float width, height, depth;
    float color_r, color_g, color_b;


public:

    Block(glm::vec3 pos, glm::vec3 size, glm::vec3 color);
    ~Block();

    void draw();

};
