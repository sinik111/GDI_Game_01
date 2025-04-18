#pragma once

#include "Scene.h"
#include "ResultCode.h"

class PlayScene
	: public Scene
{
public:
	PlayScene() = default;
	~PlayScene() = default;

public:
	ResultCode Load() override;
	ResultCode Enter() override;
	void Exit() override;
	void Unload() override;

public:
	void Update() override;
};