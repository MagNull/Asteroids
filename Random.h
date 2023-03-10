#pragma once
#include <random>

class Random
{
public:
	Random();
	Random(unsigned int seed);

	double GetRandomDouble();
	int GetRandomInt();

	double GetRandomDoubleInRange(double min, double max);
	int GetRandomIntInRange(int min, int max);

private:
	std::mt19937 m_Generator;
};
