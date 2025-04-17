#pragma once

#include <windows.h>
#include <bitset>

class Input
{
private:
	static HWND s_hWnd;
	static std::bitset<256> s_CurrentKeyState;
	static std::bitset<256> s_PreviousKeyState;

private:
	Input() = delete;
	~Input() = delete;
	Input(const Input&) = delete;
	Input& operator=(const Input&) = delete;
	Input(Input&&) = delete;
	Input& operator=(Input&&) = delete;

public:
	static void Initialize(HWND hWnd);

	// 매 루프마다 호출 필요
	static void Update();

	// 키가 눌려진 상태인지 확인
	static bool IsKeyDown(int vkey);

	// 이번 루프에 키가 눌려졌는지 확인
	static bool IsKeyPressed(int vkey);

	// 이번 루프에 키가 놓아졌는지 확인
	static bool IsKeyReleased(int vkey);

	static POINT GetCursorPosition();
};