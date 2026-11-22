#pragma once

#include <cstdint>

namespace ZeroXBridge
{
	enum class SoundType : uint64_t
    {
        UNKNOWN         = 0,
        SOUND_EFFECT    = 1,
        BGM             = 2
    };

    enum class SoundFlags : uint64_t
    {
        NONE = 0,
        // TBC
    };

    struct alignas(16) AudioSound
    {
        SoundType type  { SoundType::UNKNOWN };
        SoundFlags flags{ SoundFlags::NONE };
    };
}
