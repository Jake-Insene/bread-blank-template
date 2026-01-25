#pragma once
#include "scene/scene.h"



struct MainScene : Scene
{
    SCENE_BODY(MainScene, Scene);

    void on_enter();
    void on_exit();

    void on_update(f32 dt);
};

