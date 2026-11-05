#pragma once

#include <cstdint>
#include <span>

#include <glm/vec2.hpp>

#include <memory_view.hpp>
#include <memory_cursor.hpp>

#include "zerox_material.h"

namespace ZeroXBridge
{
	struct alignas(16) TransformConfig
	{
		glm::vec2 position	{ 0.0f, 0.0f };
		glm::vec2 scale		{ 1.0f, 1.0f };
	};

	struct alignas(16) ColliderConfig
	{
		glm::vec2 size	{ 1.0f, 1.0f };
		glm::vec2 normal{ 0.0f, 0.0f };
	};

	struct alignas(16) BackgroundConfig
	{
		Material materialConfig;
		TransformConfig transformConfig;
	};

	struct alignas(16) ObstacleConfig
	{
		Material materialConfig;
		TransformConfig transformConfig;
		ColliderConfig colliderConfig;
	};

	struct alignas(16) EnemyConfig
	{
		Material materialConfig;
		TransformConfig transformConfig;
		ColliderConfig colliderConfig;
	};

	struct alignas(16) PlayerConfig
	{
		Material materialConfig;
		TransformConfig transformConfig;
		ColliderConfig colliderConfig;
	};

	struct alignas(16) Level
	{
		BackgroundConfig* backgrounds	{ nullptr };
		ObstacleConfig* obstacles		{ nullptr };
		EnemyConfig* enemies			{ nullptr };
		PlayerConfig* players			{ nullptr };
		size_t backgroundCount			{ 0 };
		size_t obstacleCount			{ 0 };
		size_t enemyCount				{ 0 };
		size_t playerCount				{ 0 };
	};
}
