#pragma once
class Timer
{
public:
	Timer()
	{
	}

	void Start();
	void Stop();
	size_t GetTickSinceStart() const;

private:
	bool m_isStart;
	size_t m_startTick;
};

