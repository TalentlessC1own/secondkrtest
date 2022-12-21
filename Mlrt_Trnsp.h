#pragma once
#include "Airplane.h"

class Mlrt_Trnsp : public Airplane
{
private:
	std::string name;
	std::string model;
public:
	std::string VehicleName() override;

	Mlrt_Trnsp(std::string valueName, int WeightValue, int MotorPowerValue, int SpeedValue,std::string nameModel)
		:name(valueName), Airplane(WeightValue, MotorPowerValue, SpeedValue, nameModel)
	{}
};

class TransportPlane : public Airplane
{
private:
	std::string name;
	std::string model;

public:
	std::string VehicleName() override;

	TransportPlane(std::string valueName, int WeightValue, int MotorPowerValue, int SpeedValue, std::string nameModel)
		: name(valueName), Airplane(WeightValue, MotorPowerValue, SpeedValue, nameModel)
	{}
};
