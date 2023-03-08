#include "Vector2.h"

#include <cmath>

Vector2 Vector2::operator+(Vector2 v1)
{
	return Vector2(x + v1.x, y + v1.y);
}

Vector2 Vector2::operator+=(Vector2 v1)
{
	x += v1.x;
	y += v1.y;
	return *this;
}

Vector2 Vector2::operator-(Vector2 v1)
{
	return Vector2(x - v1.x, y - v1.y);
}

Vector2 Vector2::operator-=(Vector2 v1)
{
	x -= v1.x;
	y -= v1.y;
	return *this;
}

double Vector2::GetMagnitude() const
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::operator*(double t)
{
	return Vector2(x * t, y * t);
}

Vector2 Vector2::operator*=(double t)
{
	x *= t;
	y *= t;
	return *this;
}

Vector2 Vector2::operator/(Vector2 v1)
{
	return Vector2(x / v1.x, y / v1.y);
}

Vector2 Vector2::operator/=(Vector2 v1)
{
	x /= v1.x;
	y /= v1.y;
	return *this;
}

const Vector2 Vector2::zero = Vector2(0, 0);
const Vector2 Vector2::one = Vector2(1, 1);

Vector2::Vector2(double x, double y) : x(x), y(y)
{
}
