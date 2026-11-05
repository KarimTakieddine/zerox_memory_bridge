#pragma once

namespace ZeroXBridge
{
	struct Input;
	struct Level;

	struct GameContext
	{
		Input* input		{ nullptr };
		Level* levels		{ nullptr };
		size_t levelCount	{ 0 };
	};
}
