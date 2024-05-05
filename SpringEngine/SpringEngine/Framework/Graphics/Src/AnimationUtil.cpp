#include "Precompiled.h"
#include "AnimationUtil.h"
#include "SimpleDraw.h"
using namespace SpringEngine;
using namespace SpringEngine::Graphics;

void AnimationUtil::ComputeBoneformRecursive(ModelId id, BoneTransforms& boneTransforms)
{
	if ()
	{

	}

}
void AnimationUtil::ComputeBoneTransforms(ModelId id, BoneTransforms& boneTransforms)
{
}

void AnimationUtil::ApplyBoneOfset(ModelId id, BoneTransforms& boneTransforms)
{
}

void AnimationUtil::DrawSkeleton(ModelId id, BoneTransforms& boneTransforms)
{
	const Model* model = ModelManager::Get()->GetModel(id);
	if (model->skeleton != nullptr)
	{
		for (auto& bone : model->skeleton->bones)
		{
			if (bone->parent != nullptr)
			{
				const Math::Vector3 posA = Math::GetTranslation(boneTransforms[bone->index]);
				const Math::Vector3 posB = Math::GetTranslation(boneTransforms[bone->parentIndex]);
				SimpleDraw::AddLine(posA, posB, Colors::Blue);
				SimpleDraw::AddSphere(10, 10, 0.03, posA, Colors::Pink);
				//get position of bones
				// get position of parent bone
				// simpldraw it 
			}
		}
	}
}
