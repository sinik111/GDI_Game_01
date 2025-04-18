#pragma once

#include "Object.h"
#include "Vector2.h"

namespace Gdiplus
{
	class Bitmap;
}

enum class ResultCode;
class Camera;

class Box :
	public Object
{
private:
	Vector2 m_Direction;
	Gdiplus::Bitmap* m_image;
	float m_speed;

public:
	Box() = default;
	~Box() = default;

public:
	ResultCode Initialize() override;
	void Destroy() override;

public:
	void Update() override;
	void Render() override;
};