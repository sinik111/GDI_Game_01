#pragma once

#include <bitset>

class Input
{
private:
	static HWND m_hWnd;
	static std::bitset<256> current_key_state;
	static std::bitset<256> previous_key_state;


private:
	Input() = delete;

public:
	// 매 루프마다 호출 필요
	static void Update();

	// 키가 눌려진 상태인지 확인
	static bool IsKeyDown(int vkey);

	// 이번 루프에 키가 눌려졌는지 확인
	static bool IsKeyPressed(int vkey);

	// 이번 루프에 키가 놓아졌는지 확인
	static bool IsKeyReleased(int vkey);

	static POINT GetCursorPosition(HWND hwnd);
};