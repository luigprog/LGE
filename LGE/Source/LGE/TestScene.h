#pragma once

#include "Core.h"

#include "Scene.h"

namespace LGE
{
	class LGE_API TestScene : public Scene
	{
	public:
		TestScene();
		~TestScene();
	public:
		virtual void OnActivate() override;
		virtual void Update(float deltaTime) override;
		virtual void Render() const override;
	};
}