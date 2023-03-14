#include "Vector2.h"

#include <cmath>

Vector2 Vector2::operator+(Vector2 v1) const
{
	return Vector2(x + v1.x, y + v1.y);
}

Vector2 Vector2::operator+=(Vector2 v1)
{
	x += v1.x;
	y += v1.y;
	return *this;
}

Vector2 Vector2::operator-(Vector2 v1) const
{
	return Vector2(x - v1.x, y - v1.y);
}

Vector2 Vector2::operator-=(Vector2 v1)
{
	x -= v1.x;
	y -= v1.y;
	return *this;
}

Vector2 Vector2::Loop(Vector2 vector, Vector2 min, Vector2 max)
{
	 if (vector.x < min.x)
		vector.x = max.x;
	else if (vector.x > max.x)
		vector.x = min.x;

	if (vector.y < min.y)
		vector.y= max.y;
	else if (vector.y > max.y)
		vector.y = min.y;

	return vector;
}

Vector2 Vector2::GetRandomUnitVector()
{
	double angle = rand() % 360;
	return Vector2(cos(angle), sin(angle));
}

Vector2 Vector2::operator*(double t) const
{
	return Vector2(x * t, y * t);
}

Vector2 Vector2::operator*=(double t)
{
	x *= t;
	y *= t;
	return *this;
}

Vector2 Vector2::operator/(Vector2 v1) const
{
	return Vector2(x / v1.x, y / v1.y);
}

Vector2 Vector2::operator/=(Vector2 v1)
{
	x /= v1.x;
	y /= v1.y;
	return *this;
}

double Vector2::GetMagnitude() const
{
	return sqrt(x * x + y * y);
}

void Vector2::Normalize()
{
	double magnitude = GetMagnitude();
	x /= magnitude;
	y /= magnitude;
}

const Vector2 Vector2::zero = Vector2(0, 0);
const Vector2 Vector2::one = Vector2(1, 1);

Vector2::Vector2(double _x, double _y) : x(_x), y(_y)
{
}
