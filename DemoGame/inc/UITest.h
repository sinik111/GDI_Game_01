#pragma once

#include <string>

#include "Object.h"
#include "Vector2.h"

#include "GDIRenderer.h"

namespace Gdiplus
{
	class Bitmap;
}

class UITest :
	public Object
{
private:
	Vector2 m_Position;
	Gdiplus::Bitmap* m_Image;
	std::wstring m_Text;
	Gdiplus::Color m_Color;

public:
	UITest() = default;
	~UITest() = default;

public: // 초기화, 정리
	ResultCode Initialize() override;
	void Destroy() override;

public: // 루프
	void Update() override;
	void Render() override;
};