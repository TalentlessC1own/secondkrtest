#pragma once
#include "Vehicle.h"
#include <string>

class Airplane : public Vehicle
{

protected:
	std::string name;
	std::string model;

public:
	Airplane(std::string valueName,int WeightValue, int MotorPowerValue, int SpeedValue, std::string nameModel)
		:name(valueName),Vehicle(WeightValue, MotorPowerValue, SpeedValue), model(nameModel)
	{}

	virtual std::string GetInfo() override = 0;
	Airplane() = default;
	std::string VehicleName() override;
	std::string Model();
};

