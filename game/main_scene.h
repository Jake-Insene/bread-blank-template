#pragma once
#include "2d/object_2d.h"


struct MainScene : Object2D
{
    OBJECT(MainScene, Object2D);

    void init(const CreateInfo&);

    void enter();
    void exit();

    void update(f64 dt);
};

