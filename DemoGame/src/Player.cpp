#include "framework.h"
#include "Player.h"

#include "ResultCode.h"
#include "AnimationController.h"
#include "Animation.h"
#include "Resources.h"
#include "GDIRenderer.h"
#include "Input.h"
#include "MyTime.h"
#include "Camera.h"
#include "CollisionManager.h"

Player::Player()
	: m_Speed(0.0f), m_current_state(PlayerState::None), m_next_state(PlayerState::None)
{
}

ResultCode Player::Initialize()
{
	Gdiplus::Bitmap* image = nullptr;

	image = Resources::Get().GetImage(L"Play", L"player_attack");
	m_animation_controller.AddAnimation(L"attack", new Animation(image, 9, 0.5f, false));

	image = Resources::Get().GetImage(L"Play", L"player_idle");
	m_animation_controller.AddAnimation(L"idle", new Animation(image, 7, 1.0f, true));

	image = Resources::Get().GetImage(L"Play", L"player_walk");
	m_animation_controller.AddAnimation(L"walk", new Animation(image, 12, 1.0f, true));

	m_animation_controller.PlayAnimation(L"idle");

	m_current_state = PlayerState::Idle;
	m_next_state = PlayerState::Idle;

	m_Position = Vector2(400.0f, 300.0f);

	m_Speed = 200.0f;

	m_Collider.SetColliderInfo(m_Position, Vector2(0.0f, 27.0f), 0.0f, 35.0f, 75.0f);

	return ResultCode::OK;
}

void Player::Destroy()
{
	__super::Destroy();
}

void Player::Update()
{
	m_animation_controller.Update();

	Vector2 direction = Vector2::Zero;

	if (Input::Get().IsKeyDown(VK_RIGHT) || Input::Get().IsKeyDown(VK_LEFT) 
		|| Input::Get().IsKeyDown(VK_UP) || Input::Get().IsKeyDown(VK_DOWN))
	{
		if (Input::Get().IsKeyDown(VK_RIGHT))
		{
			direction += Vector2::Right;
		}

		if (Input::Get().IsKeyDown(VK_LEFT))
		{
			direction += Vector2::Left;
		}

		if (Input::Get().IsKeyDown(VK_UP))
		{
			direction += Vector2::Up;
		}

		if (Input::Get().IsKeyDown(VK_DOWN))
		{
			direction += Vector2::Down;
		}

		m_next_state = PlayerState::Walk;
	}
	else
	{
		m_next_state = PlayerState::Idle;
	}

	if (Input::Get().IsKeyReleased('A'))
	{
		m_next_state = PlayerState::Attack;
	}

	if (m_current_state != m_next_state)
	{
		switch (m_next_state)
		{
		case PlayerState::Attack:
			if (m_current_state == PlayerState::Idle || m_current_state == PlayerState::Walk)
			{
				m_animation_controller.PlayAnimation(L"attack");

				m_current_state = m_next_state;
			}
			break;

		case PlayerState::Idle:
			if (m_current_state == PlayerState::Walk)
			{
				m_animation_controller.PlayAnimation(L"idle");

				m_current_state = m_next_state;
			}
			else if (m_animation_controller.GetCurrentAnimation()->IsEnd())
			{
				m_animation_controller.PlayAnimation(L"idle");

				m_current_state = m_next_state;
			}
			break;

		case PlayerState::Walk:
			if (m_current_state == PlayerState::Idle)
			{
				m_animation_controller.PlayAnimation(L"walk");

				m_current_state = m_next_state;
			}
			else if (m_animation_controller.GetCurrentAnimation()->IsEnd())
			{
				m_animation_controller.PlayAnimation(L"walk");

				m_current_state = m_next_state;
			}
			break;
		}
	}
	
	if (Input::Get().IsKeyReleased('D'))
	{
		//m_
	}

	if (m_current_state == PlayerState::Walk)
	{
		if (!direction.IsZero())
			m_Position += direction.Normalized() * m_Speed * MyTime::Get().DeltaTime();
	}

	CollisionManager::Get().ResisterGameObject(L"player", this);
}

void Player::Render()
{
	Gdiplus::Bitmap* image;
	Gdiplus::Rect dst_rect;
	Gdiplus::Rect src_rect;

	//Vector2 camera_view_position = camera.ToCameraView(m_position);

	m_animation_controller.GetCurrentAnimation()->GetFrameInfo(image, dst_rect, src_rect);

	dst_rect.X = (int)(m_Position.x - src_rect.Width / 2);
	dst_rect.Y = (int)(m_Position.y - src_rect.Height / 2);

	GDIRenderer::Get().DrawImage(image, dst_rect, src_rect);
}