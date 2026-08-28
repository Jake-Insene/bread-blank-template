#pragma once
#include <Basic/Templates/GraphicsApplication.hpp>



struct MyGame : Basic::GraphicsApplication
{
    using Base = Basic::GraphicsApplication;

    using Base::Base;

    virtual void initialize(const ApplicationInitializeInfo& init_info) override;
    virtual void shutdown() override;

    virtual void update(f32 dt) override;
    virtual void render() override;
    virtual void event(const Event& event) override;
};

