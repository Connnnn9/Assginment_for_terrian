#pragma once

namespace SpringEngine::Physics
{
	class PhysicsWorld final
	{
	public:
		struct Setting
		{
			SpringEngine::Math::Vector3 gravity = { 0.0f, -9.81f, 0.0f };
			uint32_t simulationSteps = 10;
			float fixedTimeStep = 1.0f / 60.f;
		};

		static void StaticInitialize(const Settings& settings);
		static void StaticTerminate();
		static PhysicsWorld* Get();

		PhysicsWorld() = default;
		~PhysicsWorld();

		void Initialize(const Setting& settings);
		void Terminate();

		void Update(float deltaTime);
		void DebugUI();

		void Register();
		void Unregister();

	private:
		Settings mSettings;

		btBroadphaseInterface* mInterface = nullptr;
		btCollisionDispatcher*

		PhysicsDebugDraw mPhysicsDebugDraw;

		using PhysicsObjects = std::vector<PhysicsObject*>;
		PhysicsObjects
	};
}