#ifndef __APPLICATION_H_
#define __APPLICATION_H_

#include <stack>
#include <memory>

#include "Display.hpp"
#include "Game_State.hpp"

class Application
{
    public:
        Application();

        void run_main_game_loop(Display &display);

        void push_state(std::unique_ptr<Game_State> state);
        void pop_state();

    private:
        std::stack<std::unique_ptr<Game_State>> states;

};


#endif
