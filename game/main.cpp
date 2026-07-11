#include "engine/main.h"

#include "game/my_game.h"


ApplicationInfo __get_application_info__()
{
	return ApplicationInfo
	{
		.size_in_bytes = sizeof(MyGame),
		.alignment = alignof(MyGame),
		.constructor = [](Opaque* obj, const ApplicationAllocateInfo& alloc_info)
		{
			ConstructObject(*obj->cast<MyGame*>(), alloc_info);
		},
		.initial_window_size = Vector2I(1280, 720),
		.enable_debug_console = true,
	};
}

