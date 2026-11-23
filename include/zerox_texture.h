#pragma once

#include <cstdint>

namespace ZeroXBridge
{
	enum class TextureWrapMode : uint8_t
	{
		UNKNOWN			= 0,
		REPEAT			= 1,
		CLAMP_TO_EDGE	= 2,
		CLAMP_TO_BORDER	= 3
	};

	enum class TextureFilter : uint8_t
    {
        UNKNOWN = 0,
        NEAREST = 1,
        LINEAR  = 2
    };

	enum class TextureFormat : unsigned
	{
		UNKNOWN = 0,
		RGB		= 1,
		RGBA	= 2
	};

	struct Texture
	{
		uint32_t width				{ 0 };
		uint32_t height				{ 0 };
		TextureFormat format		{ TextureFormat::UNKNOWN };
		TextureWrapMode wrapModeS	{ TextureWrapMode::UNKNOWN };
		TextureWrapMode wrapModeT	{ TextureWrapMode::UNKNOWN };
		TextureFilter minFilter		{ TextureFilter::UNKNOWN };
		TextureFilter magFilter		{ TextureFilter::UNKNOWN };
	};
}
