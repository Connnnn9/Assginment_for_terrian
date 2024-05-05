#include "Precompiled.h"
#include "Physics/Inc/RigidBody.h"

#include <Graphics/Inc/Transform.h>

using namespace SpringEngine;
using namespace SpringEngine::Physics;
using namespace SpringEngine::Graphics;

RigidBody::~RigidBody()
{
	ASSERT(mRigidbody == nullptr, "RigidBody : Terminate must be called");
}

void RigidBody::Initialize(SpringEngine::Graphics::Transform& graphicsTransform, const CollisionShape& shape, float mass)
{
	mGraphicsTransform = &graphicsTransform;
	mMass = mass;
}

void RigidBody::Terminate()
{

}

void RigidBody::SetPosition(const SpringEngine::Math::Vector3& position)
{

}

void RigidBody::SetVelocity(const SpringEngine::Math::Vector3& velocity)
{

}

bool RigidBody::IsDynamic() const
{
	return mMass > 0.0f;
}

void RigidBody::Update()
{
	btTransform& worldTransform = mRigidBody->getWorldTransform();
	mGraphicsTransform->position
}



