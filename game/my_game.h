#pragma once
#include "engine/application.h"



struct MyGame : Application
{
    using Base = Application;

    using Application::Application;

    virtual void initialize(const ApplicationInitializeInfo& init_info) override;
    virtual void shutdown() override;

    virtual void update(f32 dt) override;
    virtual void render() override;
    virtual void event(const Event& event) override;
};

