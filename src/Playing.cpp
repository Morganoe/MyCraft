#include "Playing.hpp"

#include <iostream>

Playing::Playing(Application &application)
: Game_State(application),
  model({0.5, 0.5,
        -0.5, 0.5,
        -0.5,-0.5,
        -0.5,-0.5,
         0.5,-0.5,
         0.5, 0.5})
{

}

void Playing::input()
{

}

void Playing::update()
{

}

void Playing::draw()
{
    model.bind();
    glDrawArrays(GL_TRIANGLES, 0, 6);
    model.unbind();

}
