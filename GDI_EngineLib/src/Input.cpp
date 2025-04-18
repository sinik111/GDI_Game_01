#include "pch.h"
#include "Input.h"

Input::Input()
    :m_hWnd(nullptr)
{

}

void Input::SetWindow(HWND hWnd)
{
    m_hWnd = hWnd;
}

void Input::Update()
{
    m_PreviousKeyState = m_CurrentKeyState;

    for (int i = 0; i < 256; ++i)
    {
        m_CurrentKeyState[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
    }
}

bool Input::IsKeyDown(int vkey)
{
    return m_CurrentKeyState[vkey];
}

bool Input::IsKeyPressed(int vkey)
{
    return !m_PreviousKeyState[vkey] && m_CurrentKeyState[vkey];
}

bool Input::IsKeyReleased(int vkey)
{
    return m_PreviousKeyState[vkey] && !m_CurrentKeyState[vkey];
}

POINT Input::GetCursorPosition()
{
    POINT point;

    GetCursorPos(&point);

    ScreenToClient(m_hWnd, &point);

    return point;
}
