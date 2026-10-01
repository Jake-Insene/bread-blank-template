#include "game/my_game.hpp"


void MyGame::initialize(const ApplicationInitializeInfo& init_info)
{
    Base::initialize(init_info);
}

void MyGame::shutdown()
{
    Base::shutdown();
}

void MyGame::update(f32 dt)
{
    Base::update(dt);
}

void MyGame::render()
{
    Base::render();
}

void MyGame::event(const Event& event)
{
    Base::event(event);
}
