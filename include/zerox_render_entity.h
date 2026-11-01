#pragma once

#include "zerox_material.h"
#include "zerox_transform.h"

namespace ZeroXBridge
{
	struct alignas(16) RenderEntity
	{
		Transform transform;
		Material material;
	};
}
