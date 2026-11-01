#pragma once

#include <cstdint>
#include <type_traits>

namespace ZeroXBridge
{
	struct alignas(16) EntityReadDescriptor
	{
		uint64_t start	{ 0 };
		uint64_t offset	{ 0 };
	};

	enum class EntitySectionType : uint64_t
	{
		UNKNOWN			= 0,
		BACKGROUND		= 1,
		SPRITE			= 2,
		TILED_SPRITE	= 3,
		COLLIDER		= 4,
		PARTICLE		= 5,
		TEXT			= 6
		// etc...
	};

	enum class EntitySectionFlags : uint64_t
	{
		NONE				= 0,
		ALLOCATE_BATCH		= 1,
		SET_VERTEX_LAYOUT	= 1 << 1
		// etc...
	};

	inline EntitySectionFlags operator|(EntitySectionFlags a, EntitySectionFlags b) {
		return static_cast<EntitySectionFlags>(static_cast<std::underlying_type_t<EntitySectionFlags>>(a) | static_cast<std::underlying_type_t<EntitySectionFlags>>(b));
	}
	inline EntitySectionFlags operator&(EntitySectionFlags a, EntitySectionFlags b) {
		return static_cast<EntitySectionFlags>(static_cast<std::underlying_type_t<EntitySectionFlags>>(a) & static_cast<std::underlying_type_t<EntitySectionFlags>>(b));
	}
	inline EntitySectionFlags& operator|=(EntitySectionFlags& a, EntitySectionFlags b) { a = (a | b); return a; }
	inline EntitySectionFlags& operator&=(EntitySectionFlags& a, EntitySectionFlags b) { a = (a & b); return a; }
	inline EntitySectionFlags operator~(EntitySectionFlags a) { return static_cast<EntitySectionFlags>(~static_cast<std::underlying_type_t<EntitySectionFlags>>(a)); }

	struct alignas(16) EntitySection
	{
		EntitySectionType type					{ EntitySectionType::UNKNOWN };
		EntitySectionFlags flags				{ EntitySectionFlags::NONE };
		EntityReadDescriptor* readDescriptors	{ nullptr };
		uint64_t descriptorCount				{ 0 };
	};
}
