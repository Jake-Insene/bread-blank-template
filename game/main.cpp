#include <Runtime/Main.hpp>
#include <os/os.h>

#include "game/my_game.hpp"


ApplicationInfo __get_application_info__()
{
	return ApplicationInfo
	{
		.size_in_bytes = sizeof(MyGame),
		.alignment = alignof(MyGame),
		.constructor = [](Core::Opaque* obj, const ApplicationAllocateInfo& alloc_info)
		{
			Core::Mem::Placement(*obj->cast<MyGame*>(), alloc_info);
		},
	};
}

ApplicationInfo RegisterApplication()
{
    OS::set_current_directory("assets");
	return __get_application_info__();
}