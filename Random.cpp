#include "Random.h"

Random::Random(unsigned seed)
{
	m_Generator = std::mt19937(seed);
}

Random::Random()
{
	m_Generator = std::mt19937(std::random_device()());
}

double Random::GetRandomDouble()
{
	return GetRandomDoubleInRange(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
}

int Random::GetRandomInt()
{
	return GetRandomIntInRange(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

double Random::GetRandomDoubleInRange(double min, double max)
{
	std::uniform_real_distribution distribution(min, max);
	return distribution(m_Generator);
}

int Random::GetRandomIntInRange(int min, int max)
{
		std::uniform_int_distribution distribution(min, max);
	return distribution(m_Generator);
}
