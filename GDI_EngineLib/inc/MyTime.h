#pragma once

#include <chrono>

#include "Singleton.h"

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Duration = std::chrono::duration<float>;

class MyTime :
    public Singleton<MyTime>
{
    friend class Singleton<MyTime>;
private:
    TimePoint m_PreviousTime;
    TimePoint m_CurrentTime;

    float m_DeltaTime;

private:
    MyTime();
    ~MyTime() = default;

public:
    void Update();

    float DeltaTime();
    TimePoint GetTimestamp();
    TimePoint GetAccumulatedTime(const TimePoint& timePoint, int second);
    float GetElapsedTime(const TimePoint& timePoint);
};