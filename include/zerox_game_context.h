#pragma once

#include <zerox_input.h>

#include "zerox_level.hpp"

namespace ZeroXBridge
{
	struct GameContext
	{
		Input* input		{ nullptr };
		Level* levels		{ nullptr };
		size_t levelCount	{ 0 };
	};
}
