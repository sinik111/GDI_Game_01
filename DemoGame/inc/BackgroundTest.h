#pragma once

#include <string>

#include "Object.h"
#include "Vector2.h"

namespace Gdiplus
{
	class Bitmap;
}

enum class ResultCode;
class Camera;

class BackgroundTest :
	public Object
{
private:
	Gdiplus::Bitmap* m_Image;
	int m_SceneNumber;

public:
	BackgroundTest(Gdiplus::Bitmap* image, int scene);
	~BackgroundTest() = default;

public: // 초기화, 정리
	ResultCode Initialize() override;
	void Destroy() override;

public: // 루프
	void Update() override;
	void Render() override;
};