#pragma once

#include <chrono>

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif // _DEBUG

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;

class Debug
{
private:
    static int s_LastFPS;
    static int s_FrameCount;
    static TimePoint s_LastTimestamp;

    static bool s_IsConsoleOn;

private:
    Debug() = delete;
    ~Debug() = delete;
    Debug(const Debug&) = delete;
    Debug& operator=(const Debug&) = delete;
    Debug(Debug&&) = delete;
    Debug& operator=(Debug&&) = delete;

public:
    // 콘솔 생성
    static void CreateConsole();
    // 콘솔 해제
    static void ReleaseConsole();

    // 메모리 누수 체크 활성화
    static void EnableLeakCheck();
    // 메모리 누수 출력
    static void DumpLeaks();

    // Frame Count 누적, 매 프레임 호출 해야함
    static void UpdateFPS(bool display = false);
    // 최근 FPS
    static int GetLastFPS();
    // 최근 FPS 콘솔에 출력, 기본적으로 UpdateFPS에서 호출 중임
    static void DisplayFPS();

    static void Log(const char* fmt, ...); // printf처럼 사용
    static void Log(const wchar_t* fmt, ...); // printf처럼 사용
    static void Log(const std::string& log);
    static void Log(const std::wstring& log);
};