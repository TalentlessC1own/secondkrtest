#include "Mlrt_Trnsp.h"

std::string  Mlrt_Trnsp::VehicleName()
{
	return  name;

}

std::string Mlrt_Trnsp::GetInfo()
{
	return "Name = " + name + "\n" + "Model = " + model + "\n" +  "Weight = " + std::to_string(Weight) + "\n" + "Motor Power = " + std::to_string(MotorPower) + "\n" + "Speed = " + std::to_string(Speed) + "\n" + "Count of bombs = " + std::to_string(countofbombs) + "\n";
}

int Mlrt_Trnsp::GetCountOfBombs()
{
	return countofbombs;
}


int TransportPlane::GetCountOfSeats()
{
	return countofseats;
}

std::string TransportPlane::GetInfo()
{
	return "Name = " + name + "\n" + "Model = " + model + "\n" + "Weight = " + std::to_string(Weight) + "\n" + "Motor Power = " + std::to_string(MotorPower) + "\n" + "Speed = " + std::to_string(Speed) + "\n" + "Count of seats = " + std::to_string(countofseats) + "\n";
}



std::string  TransportPlane::VehicleName()
{
	return name;
}
