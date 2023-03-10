#include "Input.h"


void ConsoleInput(std::vector<std::shared_ptr<Airplane>>& VehicleCase)
{
	int ves = 0;
	int moshnost = 0;
	int scor = 0;
	std::string mod;
	std::string name;
	std::string nametype = "";
	int countofseats = 0;				//pole transport classa
	int countofbombs = 0;				//pole military classa
	std::cout << "Choose type of plane:" << std::endl << std::endl;
	

	while (true)
	{

		std::cout << "1 - Military plane " << std::endl << "2 - Transport plane" << "\n3 - Enough" << std::endl << std::endl;

		PlaneType type = static_cast<PlaneType>(CheckMenuItem(3));
		switch (type)
		{
		case PlaneType:: Mltr:
		{
			nametype = "Military plane";
			std::cout << nametype << std::endl << std::endl;

			std::cout << "Enter model of plane:" << std::endl << std::endl;
			std::getline(std::cin, mod);

			std::cout << "Weight: " << std::endl << std::endl;
			ves = CheckIntValue();

			std::cout << "Motor Power:" << std::endl << std::endl;
			moshnost = CheckIntValue();

			std::cout << "Speed: " << std::endl << std::endl;
			scor = CheckIntValue();

			std::cout << "Count of bombs:" << std::endl << std::endl;
			countofbombs = CheckIntValue();

			

			VehicleCase.emplace_back(std::make_shared<Mlrt_Trnsp>(nametype, mod, ves,moshnost,scor,countofbombs));
			break;
		}
		case PlaneType:: Trnsp:
		{
			nametype = "Transport plane";
			std::cout << nametype << std::endl << std::endl;

			std::cout << "Enter model of plane:" << std::endl << std::endl;
			std::getline(std::cin, mod);

			std::cout << "Weight: " << std::endl << std::endl;
			ves = CheckIntValue();

			std::cout << "Motor Power:" << std::endl << std::endl;
			moshnost = CheckIntValue();

			std::cout << "Speed: " << std::endl << std::endl;
			scor = CheckIntValue();

			std::cout << "Count of seats:" << std::endl << std::endl;
			countofseats = CheckIntValue();

			VehicleCase.emplace_back(std::make_shared<TransportPlane>(nametype, mod, ves, moshnost, scor,countofseats));
			break;
		}
		case PlaneType::Enough:
			return;
		}
	}
}

void FileInput(std::vector<std::shared_ptr<Airplane>>& VehicleCase)
{
	std::string fileName = "";
	std::ifstream file;

	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	while (true)
	{

		std::cout << "Enter file name. " << std::endl << "ENTER : ";
		std::getline(std::cin, fileName);
		try
		{
			file.open(fileName);
			std::cout << "Sucefull file open " << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "Incorrect file name or way.Try again ." << std::endl;
			continue;
		}

		int ves = 0;
		int moshnost = 0;
		int scor = 0;
		std::string nametype = "";
		std::string mod{};
		int countOfBombs = 0;
		int countOfSeats = 0;

		int count = 0;
			try
			{
				count = CheckLineInt(file);
				for (int i = 0; i < count; i++)
				{
					nametype = CheckLineString(file);
					ves = CheckLineInt(file);
					moshnost = CheckLineInt(file);
					scor = CheckLineInt(file);
					mod = CheckLineString(file);
					std::cout << nametype << std::endl;
					std::cout << "Weight: " << ves << std::endl;
					std::cout << "Motor Power: " << moshnost << std::endl;
					std::cout << "Speed: " << scor << std::endl;
					std::cout << "Model: " << mod << std::endl;

					if (nametype == "Military plane")
					{
						countOfBombs = CheckLineInt(file);
						VehicleCase.emplace_back(std::make_shared<Mlrt_Trnsp>(nametype, mod, ves, moshnost, scor, countOfBombs));
						std::cout << "Count of bombs:" << countOfBombs << std::endl;
					}
					else if (nametype == "Transport plane")
					{
						countOfSeats = CheckLineInt(file);
						VehicleCase.emplace_back(std::make_shared<TransportPlane>(nametype,mod, ves, moshnost, scor,countOfSeats));
						std::cout << "Count of seats:" << countOfSeats << std::endl;
					}

					std::cout << std::endl << std::endl;
				}
			}
			catch (std::invalid_argument iaex)
			{
				std::cout << "Incorect data " << std::endl;
				file.close();
				continue;
			}

			file.close();
			break;
	}
}