#pragma once

#include "Singleton.h"

class GameData :
	public Singleton<GameData>
{
	friend class Singleton<GameData>;
private:
	int m_Score;
	float m_Timer;

private:
	GameData() = default;
	~GameData() = default;

public:
	void SetScore(int score);
	int GetScore();

	void SetTimer(float timer);
	int GetTimer();
};