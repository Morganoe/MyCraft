#ifndef __PLAYING_HPP_
#define __PLAYING_HPP_

#include "Game_State.hpp"
#include "Model.hpp"

class Playing : public Game_State
{
    public:
        Playing(Application &application);

        void input() override;
        void update() override;
        void draw() override;

    private:
        Model model;
};

#endif
