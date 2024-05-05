#include "Precompiled.h"
#include "Physics/Inc/PhysicsWorld.h"
#include "Physics/Inc/PhysicsObject.h"


using namespace SpringEngine;
using namespace SpringEngine::Physics;

namespace
{
	std::unique_ptr<PhysicsWorld> sPhysicsWorld;
}

void Physics::PhysicsWorld::StaticInitialize(const Settings& settings)
{
	ASSERT(sPhysicsWorld == nullptr, "PhysicsWorld: is already initialized");
	sPhysicsWorld
}

PhysicsWorld:~PhysicsWorld()
{
	ASSERT(mDynamicsWorldWorld == nullptr, "PhysicsWorld: terminate must bt called");
}

void PhysicsWorld::DebugUI()
{

}

void PhysicsWorld::Register(PhysicsObject* physicsObject)
{
	auto iter = std::find(mPhysicsObjects.begin(), mPhysicsObjects.end(), physicsObject);
	if (iter != mPhysicsObjects.end())
	{

	}
}
