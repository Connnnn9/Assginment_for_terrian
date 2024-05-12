#pragma once
namespace SpringEngine::Physics
{
	class PhysicsDebugDraw final : public btIDebugDraw
	{
	public:
		void drawLine();
		void drawContactPoint();
		void reportErrorWarning();
		void draw3dText(const btVector3& Location);
		void setDebugMode(int debugMode) override;
		int getDebugMode() const override;

	private:
		int mDebugMode = 0;
	};
}