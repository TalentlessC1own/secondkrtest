#include "Output.h"

void ConsoleOutput(std::vector<std::shared_ptr<Airplane>>& VehicleCase)
{
	for (int i = 0; i < VehicleCase.size(); i++)
		VehicleCase[i]->GetInfo();
}

void FileOutput(std::vector<std::shared_ptr<Airplane>>& VehicleCase)
{
	std::ofstream fileRecorder = CheckFileOutput();

	for (int i = 0; i < VehicleCase.size(); i++)
	{
		fileRecorder << VehicleCase[i]->GetInfo();
	}
}

void InitialDataOutput(std::vector<std::shared_ptr<Airplane>>& VehicleCase)   
{
	;
	std::cout << "Save initial data ?\n1 - Yes\n2 - No" << std::endl;
	if (CheckMenuItem(2) != 1)
		return;
	std::ofstream fileRecorder = CheckFileOutput();

	fileRecorder << VehicleCase.size() << std::endl;

	for (int i = 0; i < VehicleCase.size(); i++)
	{
		
		fileRecorder << VehicleCase[i]->VehicleName() << std::endl;
		fileRecorder << VehicleCase[i]->GetWeight() << std:: endl;
		fileRecorder << VehicleCase[i]->GetMotorPower() << std::endl;
		fileRecorder << VehicleCase[i]->GetSpeed() << std::endl;
		fileRecorder << VehicleCase[i]->Model() << std::endl;
		if (std::static_pointer_cast<Airplane>(VehicleCase[i])->VehicleName() == "Military plane")
		{
			fileRecorder << std::static_pointer_cast<Mlrt_Trnsp>(VehicleCase[i])->GetCountOfBombs() << std::endl;;
		}
		else
		{
			fileRecorder << std::static_pointer_cast<TransportPlane>(VehicleCase[i])->GetCountOfSeats() << std::endl;;
		}
	}
	std::cout << "File succsesfull saved" << std::endl;
	fileRecorder.close();
}