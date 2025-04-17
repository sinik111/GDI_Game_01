#include "pch.h"
#include "Input.h"

namespace
{

}

void Input::Update()
{
    previous_key_state = current_key_state;

    for (int i = 0; i < 256; ++i)
    {
        current_key_state[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
    }
}

bool Input::IsKeyDown(int vkey)
{
    return current_key_state[vkey];
}

bool Input::IsKeyPressed(int vkey)
{
    return !previous_key_state[vkey] && current_key_state[vkey];
}

bool Input::IsKeyReleased(int vkey)
{
    return previous_key_state[vkey] && !current_key_state[vkey];
}

POINT Input::GetCursorPosition(HWND hwnd)
{
    POINT point;

    GetCursorPos(&point);

    ScreenToClient(hwnd, &point);

    return point;
}
