#include "Application.hpp"

#include "Display.hpp"

#include "Playing.hpp"

Application::Application()
{
    push_state(std::make_unique<Playing>(*this));
}

void Application::run_main_game_loop(Display &display)
{
    while(display.is_open())
    {
        display.clear();

        states.top()->input();
        states.top()->update();
        states.top()->draw();


        display.update();

    }
}

void Application::push_state(std::unique_ptr<Game_State> state)
{
    states.push(std::move(state));
}

void Application::pop_state()
{
    states.pop();
}
