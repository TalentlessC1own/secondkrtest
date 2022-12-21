#pragma once
#include <iostream>
#include <string>

class Vehicle
{
protected:

	int Weight;
	int MotorPower;
	int Speed;
public:
	Vehicle(int WeightValue, int MotorPowerValue, int SpeedValue)
		:Weight(WeightValue), MotorPower(MotorPowerValue), Speed(SpeedValue)
	{}

	int GetWeight();
	int GetMotorPower();
	int GetSpeed();

	virtual std::string VehicleName() = 0;
	

	virtual ~Vehicle() = default;


	std::string GetInfo();
};

