// 1 - консольный ввод 2 - файловы1 
// 1- военный 2 - транспортный
//добавить еще один 


#include "Vehicle.h"
#include "Input.h"
#include "Menu.h"
#include "Output.h"
#include <iostream>
#include <vector>
//#include <windows.h>

enum class Options
{
	Add = 1,
	FileOutput,
	Clear,
	//Exit
};
enum class HowToInput
{
	ByConsole = 1,
	ByFile
};

enum class Quit
{
	Yes = 1,
	No
};

enum class Save
{
	Save = 1,
	Cont
};
enum class SubMenu
{
	Military = 1,
	Transport,
	Model,
	Out
};

int main()
	{

	setlocale(LC_ALL, "ru");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	std::cout << "Яндиева Хава, 415, контрольная 2, вариант 7" << std::endl << std::endl;

	std::vector <std::shared_ptr<Airplane>> VehicleCase; //maybe Airplane, not Vehicle idk :(
	

	while (true) {

		//std::cout << "1 - Add \n2 - File output\n3 - Clear list" << std::endl;
		std::cout<<"Базовый класс – средство передвижения.\n"<<
			"Поля в нем: вес, мощность мотора, скорость.\n"<<
			"Производный класс – самолет; \nпроизводный класс второго"<<
			"поколения – военный самолет, транспортный самолет." << std::endl << std::endl;

		HowToInput choice = static_cast<HowToInput>(AscMenuItem());

		switch (choice)
		{
		case HowToInput::ByConsole:
		{
			VehicleCase.clear();
			ConsoleInput(VehicleCase);
			InitialDataOutput(VehicleCase);
			break;
		}
		case HowToInput::ByFile:
			{
			VehicleCase.clear();
				FileInput(VehicleCase);
				break;
			}
			
		}

		bool loop = true;
		while (loop)
		{
			std::cout << std::endl;
			std::cout << "1 - list of military planes \n"
				<< "2 - list of transport planes \n"
				<< "3 - list by same models of planes\n"
				<< "4 - exit" << std::endl << std::endl;

			SubMenu Sort = static_cast<SubMenu>(CheckMenuItem(4));
			std::vector<std::shared_ptr <Airplane>> list;

			switch (Sort)
			{
			case SubMenu::Military:
			{
				list.clear();
				std::string name{};
				int weight{};
				int power{};
				int speed{};
				std::string model{};
				for (int i = 0; i < VehicleCase.size(); i++)
				{
					if (VehicleCase[i]->VehicleName() == "Military plane")
					{
						name = VehicleCase[i]->VehicleName();
						weight = VehicleCase[i]->GetWeight();
						power = VehicleCase[i]->GetMotorPower();
						speed = VehicleCase[i]->GetSpeed();
						model = VehicleCase[i]->Model();

						std::cout << name << std::endl;
						std::cout << "Weight: " << weight << std::endl;
						std::cout << "Motor Power:" << power << std::endl;
						std::cout << "Speed: " << speed << std::endl;
						std::cout << "Model:" << model << std::endl << std::endl;

						list.emplace_back(VehicleCase[i]);

					}
				}

				InitialDataOutput(list);
				break;
			}
			case SubMenu::Transport:
			{
				list.clear();
				std::string name{};
				int weight{};
				int power{};
				int speed{};
				std::string model{};
				for (int i = 0; i < VehicleCase.size(); i++)
				{
					if (VehicleCase[i]->VehicleName() == "Transport plane")
					{
						name = VehicleCase[i]->VehicleName();
						weight = VehicleCase[i]->GetWeight();
						power = VehicleCase[i]->GetMotorPower();
						speed = VehicleCase[i]->GetSpeed();
						model = VehicleCase[i]->Model();

						std::cout << name << std::endl;
						std::cout << "Weight: " << weight << std::endl;
						std::cout << "Motor Power:" << power << std::endl;
						std::cout << "Speed: " << speed << std::endl;
						std::cout << "Model:" << model << std::endl << std::endl;

						list.emplace_back(VehicleCase[i]);

					}
				}

				InitialDataOutput(list);
				break;
			}
			case SubMenu::Model:
			{
				std::string ModelYouWant = "";
				std::cout << "Enter whished model of plane:" << std::endl;
				std::cin >> ModelYouWant;
				std::cout << std::endl;
				list.clear();
				std::string name{};
				int weight{};
				int power{};
				int speed{};
				std::string model{};
				for (int i = 0; i < VehicleCase.size(); i++)
				{
					if (VehicleCase[i]->Model() == ModelYouWant)
					{
						name = VehicleCase[i]->VehicleName();
						weight = VehicleCase[i]->GetWeight();
						power = VehicleCase[i]->GetMotorPower();
						speed = VehicleCase[i]->GetSpeed();
						model = VehicleCase[i]->Model();

						std::cout << name << std::endl;
						std::cout << "Weight: " << weight << std::endl;
						std::cout << "Motor Power:" << power << std::endl;
						std::cout << "Speed: " << speed << std::endl;
						std::cout << "Model:" << model << std::endl << std::endl;

						list.emplace_back(VehicleCase[i]);

					}
				}

				InitialDataOutput(list);
				break;
			}
			case SubMenu::Out:				//
			{
				loop = false;
				break;
			}
			}
			
		}

			//выход из программы
		std::cout << "Are you sure you want to exit?" << std::endl;
			Quit YesOrNo = static_cast<Quit>(AskToQuitOrToStay());
			switch (YesOrNo)
			{
			case Quit::Yes:
			{
				return 0;
			}
			case Quit::No:
			{
				break;

			}
			}
		
	}


	
	return 0;
	}
