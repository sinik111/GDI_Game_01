#pragma once

#include "Scene.h"
#include "ResultCode.h"

class TitleScene
	: public Scene
{
public:
	TitleScene() = default;
	~TitleScene() = default;

public:
	ResultCode Load() override;
	ResultCode Enter() override;
	void Exit() override;
	void Unload() override;

public:
	void Update() override;
};