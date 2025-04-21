#pragma once

#include "Object.h"
#include "AnimationController.h"
#include "Vector2.h"

enum class ResultCode;

class GDIRenderer;

enum class PlayerState
{
	Idle,
	Walk,
	Attack,
	None
};

class Player
	: public Object
{
private:
	AnimationController m_animation_controller;

	PlayerState m_current_state;
	PlayerState m_next_state;

	float m_Speed;

	int m_Score;

public:
	Player();
	~Player() = default;

public:
	ResultCode Initialize() override;
	void Destroy() override;

public:
	void Update() override;
	void Render() override;

public:
	void Collide(Object& object, const std::wstring& groupName) override;
};