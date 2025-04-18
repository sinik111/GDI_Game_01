#include "pch.h"
#include "MyTime.h"

MyTime::MyTime()
    : m_PreviousTime(Clock::now()), m_CurrentTime(Clock::now()), m_DeltaTime(0.0f)
{

}

void MyTime::Update()
{
    m_CurrentTime = Clock::now();

    std::chrono::duration<float> duration(m_CurrentTime - m_PreviousTime);
    m_DeltaTime = duration.count();

    m_PreviousTime = m_CurrentTime;
}

float MyTime::DeltaTime()
{
    return m_DeltaTime;
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
