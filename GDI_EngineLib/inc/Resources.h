#pragma once

#include "Singleton.h"

enum class ResultCode;

namespace Gdiplus
{
	class Bitmap;
}

class Resources
	: public Singleton<Resources>
{
	friend class Singleton<Resources>;

private:
	using Images = std::unordered_map<std::wstring, Gdiplus::Bitmap*>;

	std::unordered_map<std::wstring, Images> m_ImageGroups;

private:
	Resources() = default;
	~Resources() = default;

public:
	ResultCode AddImage(const std::wstring& group, const std::wstring& name, Gdiplus::Bitmap* image);
	Gdiplus::Bitmap* GetImage(const std::wstring& group, const std::wstring& name);

public:
	void ReleaseResources(const std::wstring& group);
};