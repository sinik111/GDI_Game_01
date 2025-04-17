#include "pch.h"
#include "MyTime.h"

TimePoint MyTime::s_PreviousTime = Clock::now();
TimePoint MyTime::s_CurrentTime = Clock::now();

float MyTime::s_DeltaTime = 0.0f;

void MyTime::Update()
{
    s_CurrentTime = Clock::now();

    std::chrono::duration<float> duration(s_CurrentTime - s_PreviousTime);
    s_DeltaTime = duration.count();

    s_PreviousTime = s_CurrentTime;
}

float MyTime::GetDeltaTime()
{
    return s_DeltaTime;
}

TimePoint MyTime::GetTimestamp()
{
    return Clock::now();
}

TimePoint MyTime::GetAccumulatedTime(const TimePoint& timePoint, int second)
{
    return timePoint + std::chrono::seconds(1);
}

float MyTime::GetElapsedTime(const TimePoint& timePoint)
{
    return Duration(Clock::now() - timePoint).count();
}
