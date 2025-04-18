#include "pch.h"
#include "Resources.h"

#include <ole2.h>
#include <gdiplus.h>

#include "Debug.h"
#include "ResultCode.h"

ResultCode Resources::AddImage(const std::wstring& group, const std::wstring& name, Gdiplus::Bitmap* image)
{
	if (image == nullptr)
	{
		Debug::Log(L"image is nullptr. " + group + L"/" + name + L" - Resources::AddImage()");

		return ResultCode::FAIL;
	}

	Images& images = m_ImageGroups[group];

	if (images.find(name) != images.end())
	{
		Debug::Log(L"same name " + group + L"/" + name + L" - Resources::AddImage()");

		return ResultCode::FAIL;
	}

	images.emplace(name, image);

	return ResultCode::OK;
}

Gdiplus::Bitmap* Resources::GetImage(const std::wstring& group, const std::wstring& name)
{
	Images& images = m_ImageGroups[group];

	if (images.find(name) == images.end())
	{
		Debug::Log(L"can't find image. " + group + L"/" + name + L" - Resources::GetImage()");

		return nullptr;
	}

	return images[name];
}

void Resources::ReleaseResources(const std::wstring& group)
{
	Images& images = m_ImageGroups[group];

	for (auto pair : images)
	{
		delete pair.second;
	}

	images.clear();
}