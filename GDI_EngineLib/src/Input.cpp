#include "pch.h"
#include "Input.h"

HWND Input::s_hWnd = nullptr;

void Input::Initialize(HWND hWnd)
{
    s_hWnd = hWnd;
}

void Input::Update()
{
    s_PreviousKeyState = s_CurrentKeyState;

    for (int i = 0; i < 256; ++i)
    {
        s_CurrentKeyState[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
    }
}

bool Input::IsKeyDown(int vkey)
{
    return s_CurrentKeyState[vkey];
}

bool Input::IsKeyPressed(int vkey)
{
    return !s_PreviousKeyState[vkey] && s_CurrentKeyState[vkey];
}

bool Input::IsKeyReleased(int vkey)
{
    return s_PreviousKeyState[vkey] && !s_CurrentKeyState[vkey];
}

POINT Input::GetCursorPosition()
{
    POINT point;

    GetCursorPos(&point);

    ScreenToClient(s_hWnd, &point);

    return point;
}
