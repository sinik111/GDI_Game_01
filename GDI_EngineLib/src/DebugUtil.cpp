#include "pch.h"
#include "DebugUtil.h"

#ifdef _DEBUG
#include <stdarg.h>
#endif // _DEBUG

#include "MyTime.h"

int Debug::s_LastFPS = 0;
int Debug::s_FrameCount = 0;
TimePoint Debug::s_LastTimestamp = MyTime::GetTimestamp();

bool Debug::s_IsConsoleOn = false;

void Debug::CreateConsole()
{
#ifdef _DEBUG
    if (!s_IsConsoleOn)
    {
        AllocConsole();
        FILE* fp;
        freopen_s(&fp, "CONOUT$", "w", stdout);
        SetConsoleTitleW(L"Debug Console");
        s_IsConsoleOn = true;

        Log("Console created");
    }
    else
    {
        Log("Console is already created");
    }
#endif // _DEBUG
}

void Debug::ReleaseConsole()
{
#ifdef _DEBUG
    if (s_IsConsoleOn)
    {
        // 표준 출력 스트림 닫기
        fclose(stdout);
        // 콘솔 해제
        FreeConsole();

        s_IsConsoleOn = false;

        Log("Console released");
    }
    else
    {
        Log("Console is not created");
    }
#endif // _DEBUG
}

void Debug::EnableLeakCheck()
{
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // _DEBUG
}

void Debug::DumpLeaks()
{
#ifdef _DEBUG
    _CrtDumpMemoryLeaks();
#endif // _DEBUG
}

void Debug::UpdateFPS(bool display)
{
    ++s_FrameCount;

    if (MyTime::GetElapsedTime(s_LastTimestamp) > 1.0f)
    {
        s_LastTimestamp = MyTime::GetAccumulatedTime(s_LastTimestamp, 1);

        s_LastFPS = s_FrameCount;

        s_FrameCount = 0;

#ifdef _DEBUG
        if (display)
        {
            DisplayFPS();
        }
#endif // _DEBUG
    }
}

int Debug::GetLastFPS()
{
    return s_LastFPS;
}

void Debug::DisplayFPS()
{
#ifdef _DEBUG
    Log(std::string("FPS: " + std::to_string(s_LastFPS)));
#endif // _DEBUG
}

void Debug::Log(const char* fmt, ...)
{
#ifdef _DEBUG
    char buffer[1024];

    va_list args;

    va_start(args, fmt);

    vsnprintf_s(buffer, 1024, _TRUNCATE, fmt, args);

    va_end(args);

    OutputDebugStringA(buffer);
    OutputDebugStringA("\n");

    if (s_IsConsoleOn)
    {
        std::cout << buffer << "\n";
    }
#endif // _DEBUG
}

void Debug::Log(const wchar_t* fmt, ...)
{
#ifdef _DEBUG
    wchar_t buffer[1024];

    va_list args;

    va_start(args, fmt);

    _vsnwprintf_s(buffer, 1024, _TRUNCATE, fmt, args);

    va_end(args);

    OutputDebugStringW(buffer);
    OutputDebugStringW(L"\n");

    if (s_IsConsoleOn)
    {
        std::wcout << buffer << L"\n";
    }
#endif // _DEBUG
}

void Debug::Log(const std::string& log)
{
#ifdef _DEBUG
    std::string str = log + "\n";

    OutputDebugStringA(str.c_str());

    if (s_IsConsoleOn)
    {
        std::cout << str;
    }
#endif // _DEBUG
}

void Debug::Log(const std::wstring& log)
{
#ifdef _DEBUG
    std::wstring str = log + L"\n";

    OutputDebugStringW(str.c_str());

    if (s_IsConsoleOn)
    {
        std::wcout << str;
    }
#endif // _DEBUG
}
