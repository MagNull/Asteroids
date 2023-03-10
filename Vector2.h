#pragma once
struct Vector2
{
	Vector2() : x(0), y(0)
	{
	}

	Vector2(double _x, double _y);

	const static Vector2 zero;
	const static Vector2 one;

	double X() const
	{
		return x;
	}

	double Y() const
	{
		return y;
	}

	static Vector2 Loop(Vector2 vector, Vector2 min, Vector2 max);
	static Vector2 GetRandomUnitVector();

	double GetMagnitude() const;
	void Normalize();

	Vector2 operator*(double t) const;
	Vector2 operator*=(double t);

	Vector2 operator/(Vector2 v1) const;
	Vector2 operator/=(Vector2 v1);

	Vector2 operator+(Vector2 v1) const;
	Vector2 operator+=(Vector2 v1);

	Vector2 operator-(Vector2 v1) const;
	Vector2 operator-=(Vector2 v1);

	double x;
	double y;
};
