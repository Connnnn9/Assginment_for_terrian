#pragma once
#include "PhysicsObject.h"

namespace SpringEngine::Graphics
{
	struct Transform;
}

namespace SpringEngine::Physics
{
	class CollisionShape;

	class RigidBody final : public PhysicsObject
	{
	public:
		RigidBody() = default;
		~RigidBody() = override;

		void Initialize(SpringEngine::Graphics::Transform& graphicsTransform, const CollisionShape& shape, float mass = 0);
		void Terminate();

		void SetPosition(const SpringEngine::Math::Vector3& position);
		void SetVelocity(const SpringEngine::Math::Vector3& velocity);

		bool IsDynamic() const;

	protected:
		void Update() override;
		btRigidBody* GetRigidBody() override;
	};
}