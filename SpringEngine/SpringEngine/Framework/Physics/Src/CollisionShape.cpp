#include "..\Inc\CollisionShape.h"

SpringEngine::Physics::CollisionShape::~CollisionShape()
{
	ASSERT(mcollisionShape == nullptr, "collisionShape is already initialized");
	mcollisionShape = new btEmptyShape;
}

void SpringEngine::Physics::CollisionShape::InlitializeEmpty()
{
}

void SpringEngine::Physics::CollisionShape::InlitializeBox(const SpringEngine::Math::Vector3& halfExtents)
{
	ASSERT(mcollisionShape == nullptr, "collisionShape is already initialized");
	mcollisionShape = new btBoxShape(convertTobtVector3(halfExtents));
}

void SpringEngine::Physics::CollisionShape::InlitializeSphere(float raidus)
{
	ASSERT(mcollisionShape == nullptr, "collisionShape is already initialized");
	mcollisionShape = new btsphereShape(radius);
}

void SpringEngine::Physics::CollisionShape::Inlitializehull(const SpringEngine::Math::Vector3& halfExtents, const)
{
	ASSERT(mcollisionShape == nullptr, "collisionShape is already initialized");
	btConvexHullShape* hullshape = new btConvexHullShape();
	std::vector<Math::Vector3> points =
	{
		{-halfExtents.x,-halfExtents.y,-halfExtents.z},
		{-halfExtents.x,halfExtents.y,-halfExtents.z},
		{halfExtents.x,halfExtents.y,-halfExtents.z},
		{halfExtents.x,-halfExtents.y,-halfExtents.z},
		{-halfExtents.x,-halfExtents.y,halfExtents.z},
		{-halfExtents.x,halfExtents.y,halfExtents.z},
		{halfExtents.x,halfExtents.y,halfExtents.z},
		{halfExtents.x,-halfExtents.y,halfExtents.z}
	};
	for (const Math::Vector3 point : points)
	{
		hullShape->addpoint(ConverTobtVector3(point + origin), false);
	}
	hullShape->recalcLocalAabb();
}

void SpringEngine::Physics::CollisionShape::terminate()
{

}


