#pragma once

namespace SpringEngine::Physics
{
	class CollisionShape final
	{
	public:
		CollisionShape() = default;
		~CollisionShape();

		void InlitializeEmpty();
		void InlitializeBox(const SpringEngine::Math::Vector3& halfExtents);
		void InlitializeSphere(float raidus);
		void Inlitializehull(const SpringEngine::Math::Vector3& halfExtents,const );
		void terminate();

	private:
		btCollisionshape* mcollisionShape = nullptr;
		friend class RigidBody;
		btc

	};

}