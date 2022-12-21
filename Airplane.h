#pragma once
#include "Vehicle.h"
#include <string>

class Airplane : public Vehicle
{

protected:
	std::string name;
	std::string model;

public:
	Airplane(int WeightValue, int MotorPowerValue, int SpeedValue, std::string nameModel)
		:Vehicle(WeightValue, MotorPowerValue, SpeedValue), model(nameModel)
	{}

	Airplane() = default;
	std::string VehicleName() override;
	std::string Model();
};

