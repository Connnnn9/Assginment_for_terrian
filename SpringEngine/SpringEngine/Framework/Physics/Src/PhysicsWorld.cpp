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
	if (ImGui::CollapsingHeader("Physics", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::Checkbox("DebugDraw", &mDebugDraw);
		if (mDebugDraw)
		{
			int debugMode = mPhysicsDebugDraw.getDebugMode();
			bool isEnabled = (debugMode & btIDebugDraw::DBG_DrawWireframe);
			if (ImGui::Checkbox("[DBG]Wireframe", &isEnabled))
			{
				debugMode = (isEnabled) ? debugMode | btIDebugDraw::DBG_DrawWrieframe : debugMode & ~btIDebugDraw)
			}
			isEnabled = (debugMode & btIDebugDraw)
		}
	}
}

void PhysicsWorld::Register(PhysicsObject* physicsObject)
{
	auto iter = std::find(mPhysicsObjects.begin(), mPhysicsObjects.end(), physicsObject);
	if (iter != mPhysicsObjects.end())
	{

	}
}

void PhysicsWorld::Initialize(const Settings& settings)
{

}
//Terminate
//Update
void PhysicsWorld::Update(float deltaTime)
{
	mDynamicsWorld->stepSimulation(deltaTime, mSetting)
}
