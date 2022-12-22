#pragma once
#include "Airplane.h"

class Mlrt_Trnsp : public Airplane
{
private:

	int countofbombs = 0;

public:
	std::string VehicleName() override;
	
	std::string GetInfo() override;

	int GetCountOfBombs();
	Mlrt_Trnsp(std::string valueName, std::string nameModel, int WeightValue, int MotorPowerValue, int SpeedValue,int countOfBombsValue)
		: Airplane(valueName,WeightValue, MotorPowerValue, SpeedValue, nameModel),countofbombs(countOfBombsValue)
	{}
};

class TransportPlane : public Airplane
{
private:
	
	int countofseats = 0;

public:
	int GetCountOfSeats();

	std::string GetInfo() override;

	std::string VehicleName() override;

	TransportPlane(std::string valueName, std::string nameModel, int WeightValue, int MotorPowerValue, int SpeedValue,int countOfSeatsValue)
		:  Airplane(valueName,WeightValue, MotorPowerValue, SpeedValue, nameModel),countofseats(countOfSeatsValue)
	{}
};
