#pragma once
struct Vector2
{
	Vector2(double x, double y);

	const static Vector2 zero;
	const static Vector2 one;

	double GetMagnitude() const;

	Vector2 operator*(double t);
	Vector2 operator*=(double t);

	Vector2 operator/(Vector2 v1);
	Vector2 operator/=(Vector2 v1);

	Vector2 operator+(Vector2 v1);
	Vector2 operator+=(Vector2 v1);

	Vector2 operator-(Vector2 v1);
	Vector2 operator-=(Vector2 v1);

	double x, y;
};

