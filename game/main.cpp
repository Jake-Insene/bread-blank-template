#include "game/main_scene.h"

#include "engine/engine.h"
#include "scene/scene_manager.h"
#include "resource/resource_manager.h"
#include "resource/tile_set.h"


EngineConfiguration(
	.viewport_size = Vector2I(1280, 720),
	.create_main_scene = DefaultCreateScene(MainScene),
	.vsync = true,
	.keep_viewport = true,
	.enable_debug_console = true,
);

PreloadBegin()
PreloadEnd()
