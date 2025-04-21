#include "framework.h"
#include "GameData.h"

void GameData::SetScore(int score)
{
	m_Score = score;
}

int GameData::GetScore()
{
	return m_Score;
}

void GameData::SetTimer(float timer)
{
	m_Timer = timer;
}

int GameData::GetTimer()
{
	return m_Timer;
}
