#pragma once
#include <Math/Inc/SpMath.h>
#include <Core/Inc/Core.h>
#include <Graphics/Inc/Transform.h>

#include <Bullet/btBulletCollisionCommon.h>
#include <Bullet/btBulletDynamicsCommon.h>

inline btTransform ConvertTobtTransform(const SpringEngine::Graphics::Transform& trans)
{
	return btTransform()
}