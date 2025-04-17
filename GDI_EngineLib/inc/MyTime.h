#pragma once

#include <chrono>

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Duration = std::chrono::duration<float>;

class MyTime
{
private:
    static TimePoint s_PreviousTime;
    static TimePoint s_CurrentTime;

    static float s_DeltaTime;

private:
    MyTime() = delete;
    ~MyTime() = delete;
    MyTime(const MyTime&) = delete;
    MyTime& operator=(const MyTime&) = delete;
    MyTime(MyTime&&) = delete;
    MyTime& operator=(MyTime&&) = delete;

public:
    static void Update();
    static float GetDeltaTime();
    static TimePoint GetTimestamp();
    static TimePoint GetAccumulatedTime(const TimePoint& timePoint, int second);
    static float GetElapsedTime(const TimePoint& timePoint);
};