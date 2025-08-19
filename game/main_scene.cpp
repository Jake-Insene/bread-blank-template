#include "game/main_scene.h"

#include "input/input.h"
#include "math/random.h"
#include "object/object_allocator.h"
#include "os/thread.h"
#include "os/semaphore.h"
#include "os/mutex.h"
#include "physics/physics_2d.h"
#include "scene/scene_manager.h"


void MainScene::init(const CreateInfo&)
{
    mark(MARK_UPDATE);
    mark(MARK_EVENT);
}

void MainScene::enter()
{
}

void MainScene::exit()
{
}

void MainScene::update(f64)
{
}
