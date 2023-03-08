#pragma once
class IShipDriver
{
public:
	virtual void Accelerate() = 0;
	virtual void Yaw(bool clockwise) = 0;
};