#include "Vehicle.h"

int Vehicle::GetSpeed()
{
	return Speed;
}

std::string Vehicle::GetInfo()
{
	return "Weight = " + std::to_string(Weight) + "\n" + "Motor Power = " + std::to_string(MotorPower) + "\n" + "Speed = " + std::to_string(Speed) + "\n";
}

int Vehicle::GetWeight()
{
	return Weight;
}

int Vehicle::GetMotorPower()
{
	return MotorPower;
}