#include "game/main_scene.h"

#include "engine/engine.h"
#include "scene/scene_manager.h"
#include "object/object_allocator.h"
#include "resource/resource_manager.h"
#include "resource/tile_set.h"


EngineConfiguration(
	.WindowSize = Vector2I(1280, 720),
	.DisplayTargetSize = Vector2I(1280, 720),
	.CreateMainScene = DefaultCreateScene(MainScene),
	.VSync = true,
	.EnableDebugConsole = true,
);

PreloadBegin()
PreloadEnd()
