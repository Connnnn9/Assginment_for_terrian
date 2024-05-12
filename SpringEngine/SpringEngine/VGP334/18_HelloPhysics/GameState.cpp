#include"GameState.h"

using namespace SpringEngine;
using namespace SpringEngine::Graphics;
using namespace SpringEngine::Math;
using namespace SpringEngine::Input;

void GameState::Initialize()
{
	mCamera.SetPosition({ 0.0f,1.0f,-6.0f });
	mCamera.SetLookAt({ 0.0f,0.0f,0.0f });

	mDirectionalLight.direction = Math::Normalize({ 1.0f,-1.0f,1.0f });
	mDirectionalLight.ambient = { 0.5f,0.5f,0.5f,1.0f };
	mDirectionalLight.diffuse = { 0.8f,0.8f,0.8f,1.0f };
	mDirectionalLight.specular = { 1.0f,1.0f,1.0f,1.0f };


	mStandardEffect.Initialize(L"../../Assets/Shaders/Standard.fx");
	mStandardEffect.SetCamera(mCamera);
	mStandardEffect.SetDirectionalLight(mDirectionalLight);

	Mesh Ground = MeshBuilder::CreateGroundPlane(10, 10, 1.0f);
	mGround.meshBuffer.Initialize(Ground);
	mGround.diffuseMapId = TextureManager::Get()->LoadTexture("misc/concrete.jpg");
	mGroundShape.InitializeHull({ 5.0f, 0.5f, 5.0f }, { 0.0f, -0.5f, 0.0f });
	mGroundRB.Initialize(mGround.transform, mGroundShape, 0.0f);

	int numBalls = 5;
	float ballRadius = 1.0f;
	TextureId ballMapId = TextureManager::Get()->LoadTexture("misc/basketball.jpg");
	Mesh ball = MeshBuilder::CreateSphere(60, 60, ballRadius);
	for (int i = 0; i < numBalls; ++i)
	{
		BallInfo& newBall = mBalls.emplace_back();
		newBall.ball.mashBuffer.Initialize(ball);
		newBall.ball.diffuseMapId = TextureManager::Get()->LoadTexture("misc/basketball.jpg");
		newBall.ball.transform.position.y = 4.0f + static_cast<float>(rand() % 5);
		newBall.ball.transform.position.x = 
		newBall.ball.transform.position.z = 
		newBall.ballShape.InitializeSphere(ballRadius + 0.2f);
		newBall.ballRB.Initialize(newball.ball.transform, newBall.ballShape, 1.0f);
	}
}
void GameState::Terminate()
{
	mBallRB.Terminate();
	mBallShape.Terminate();
	mBall.Terminate();
	mGroundRB.Terminate();
	mGroundShape.Terminate();
	mGround.Terminate();
	mStandardEffect.Terminate();
}
void GameState::Update(const float deltaTime)
{
	UpdateCameraControl(deltaTime);

	auto input = Input::InputSystem::Get();
	if (input->IsKeyPressed(KeyCode::SPACE)
	{
		for (BallInfo& ballInfo : mBalls)
		{
			Vector3 pos = ballInfo.ball.transform.position;
			
		}
	}
}
void GameState::Render()
{
	SimpleDraw::AddGroundPlane(10.0f, Colors::White);
	SimpleDraw::Render(mCamera);

	mStandardEffect.Begin();
		mStandardEffect.Render(mGround);
		mStandardEffect.Render(mBall);
	mStandardEffect.End();

}
void GameState::DebugUI()
{
	ImGui::Begin("Debug control", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	if (ImGui::CollapsingHeader("Light", ImGuiTreeNodeFlags_DefaultOpen))
	{
		if (ImGui::DragFloat3("Direction", &mDirectionalLight.direction.x, 0.1f))
		{
			mDirectionalLight.direction = Math::Normalize(mDirectionalLight.direction);
		}

		ImGui::ColorEdit4("Ambient##Light", &mDirectionalLight.ambient.r);
		ImGui::ColorEdit4("Diffuse##Light", &mDirectionalLight.diffuse.r);
		ImGui::ColorEdit4("Specular##Light", &mDirectionalLight.specular.r);
	mStandardEffect.DebugUI();
	Physics::PhysicsWorld::Get()->DebugUI();
	ImGui::End();
}
void GameState::UpdateCameraControl(float deltaTime)
{
	auto input = Input::InputSystem::Get();
	const float moveSpeed = input->IsKeyDown(KeyCode::LSHIFT) ? 10.0f : 1.0f;
	const float turnSpeed = 0.1f;

	if (input->IsKeyDown(KeyCode::W))
	{
		mCamera.Walk(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::S))
	{
		mCamera.Walk(-moveSpeed * deltaTime);
	}
	if (input->IsKeyDown(KeyCode::D))
	{
		mCamera.Strafe(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::A))
	{
		mCamera.Strafe(-moveSpeed * deltaTime);
	}
	if (input->IsKeyDown(KeyCode::E))
	{
		mCamera.Rise(moveSpeed * deltaTime);
	}
	else if (input->IsKeyDown(KeyCode::Q))
	{
		mCamera.Rise(-moveSpeed * deltaTime);
	}
	if (input->IsMouseDown(MouseButton::RBUTTON))
	{
		mCamera.Yaw(input->GetMouseMoveX() * turnSpeed * deltaTime);
		mCamera.Pitch(input->GetMouseMoveY() * turnSpeed * deltaTime);
	}
}