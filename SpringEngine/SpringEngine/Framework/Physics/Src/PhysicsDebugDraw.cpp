#include "Precompiled.h"
#include "Physics/Inc/PhysicsDebugDraw.h"

#include "Graphics/Inc/Colors.h"
#include <Graphics/Inc/SimpleDraw.h>

using namespace SpringEngine;
using namespace SpringEngine;
using namespace SpringEngine;

void SpringEngine::Physics::PhysicsDebugDraw::drawLine()
{
	SimpleDraw::AddLine(ConvertTovector3(from), ConvertToVector3(to), ConvertToColors(color));
}

void SpringEngine::Physics::PhysicsDebugDraw::drawContactPoint()
{
	//Nothing
}

void SpringEngine::Physics::PhysicsDebugDraw::reportErrorWarning()
{
	LOG("[]")
}

void SpringEngine::Physics::PhysicsDebugDraw::draw3dText(const btVector3& Location)
{
}

void SpringEngine::Physics::PhysicsDebugDraw::setDebugMode(int debugMode)
{
}

int SpringEngine::Physics::PhysicsDebugDraw::getDebugMode() const
{
	return 0;
}
