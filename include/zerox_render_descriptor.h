#pragma once

#include "zerox_entity_section.h"

namespace ZeroXBridge
{
	struct alignas(16) RenderDescriptor
	{
		EntitySection* entitySections	{ nullptr };
		uint64_t entitySectionCount		{ 0 };
	};
}
