#pragma once
#include <Math/Inc/SpMath.h>
#include <Core/Inc/Core.h>
#include <Graphics/Inc/Transform.h>
#include <Graphics/Inc/Colors.h>

#include <Bullet/btBulletCollisionCommon.h>
#include <Bullet/btBulletDynamicsCommon.h>
#include <Bullet/BulletSoftBody/btSoftRigidDynamicsWorld.h>
#include <Bullet/BulletSoftBody/btSoftBodyHelpers.h>
#include <Bullet/BulletSoftBody/btSoftBodyRigidBodyCollisionConfiguration.h>
#include <Bullet/BulletSoftBody/btSoftBodySolvers.h>

inline btTransform ConvertTobtTransform(const SpringEngine::Graphics::Transform& trans)
{
	return btTransform();
}