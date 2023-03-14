#pragma once
class IShipDriver
{
public:
	virtual void Accelerate(double deltaTime) = 0;
	virtual void Yaw(double deltaTime, bool clockwise) = 0;
};