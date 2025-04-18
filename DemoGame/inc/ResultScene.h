#pragma once

#include "Scene.h"
#include "ResultCode.h"

class ResultScene
	: public Scene
{
public:
	ResultScene() = default;
	~ResultScene() = default;

public:
	ResultCode Load() override;
	ResultCode Enter() override;
	void Exit() override;
	void Unload() override;

public:
	void Update() override;
};