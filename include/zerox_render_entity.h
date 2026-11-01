#pragma once

#include <cstddef>

#include "zerox_material.h"
#include "zerox_transform.h"

namespace ZeroXBridge
{
	struct alignas(16) RenderEntity
	{
		Transform transform;
		Material material;
		uint64_t layer{ 0 };
		uint64_t flags{ 0 };
	};
}
