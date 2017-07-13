#ifndef __GAME_STATE_HPP_
#define __GAME_STATE_HPP_

class Application;

class Game_State
{
    public:
        Game_State(Application &application);

        virtual void input() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;

    protected:
        Application *application;

};



#endif
