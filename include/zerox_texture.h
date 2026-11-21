#pragma once

#include <cstdint>

namespace ZeroXBridge
{
	enum class TextureWrapMode : uint16_t
	{
		UNKNOWN			= 0,
		REPEAT			= 1,
		CLAMP_TO_EDGE	= 2,
		CLAMP_TO_BORDER	= 3
	};

	enum class TextureFilter : uint16_t
    {
        UNKNOWN = 0,
        NEAREST = 1,
        LINEAR  = 2
    };

	struct Texture
	{
		uint32_t width				{ 0 };
		uint32_t height				{ 0 };
		TextureWrapMode wrapModeS	{ TextureWrapMode::UNKNOWN };
		TextureWrapMode wrapModeT	{ TextureWrapMode::UNKNOWN };
		TextureFilter minFilter		{ TextureFilter::UNKNOWN };
		TextureFilter magFilter		{ TextureFilter::UNKNOWN };
	};
}
