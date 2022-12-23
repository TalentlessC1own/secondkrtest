#include "InputCheck.h"

int CheckIntValue()
{
	std::string valueInput;
	int value;

	while (true)
	{
		std::cout << "ENTER : ";
		std::getline(std::cin, valueInput);
		std::cout << std::endl;
		try
		{
			value = stoi(valueInput);
			if (value > 0)
				return value;
			else
				throw value;
		}
		catch (std::exception)
		{

			std::cout << " Eror.Try again. " << std::endl;
		}
		catch (int ex_value)
		{
			std::cout << ex_value << " - uncorrect input .Try again." << std::endl;
		}
	}
}

int CheckMenuItem(int numberOfPoints)
{
	std::string valueInput;
	int value;
	while (true)
	{
		std::cout << "ENTER : " << std::endl;
		//std::cin >> valueInput;
		std::getline(std::cin, valueInput);
		std::cout << std::endl;
		try
		{
			value = stoi(valueInput);
			if (value <= numberOfPoints && value >= 1)
				return value;
			else
				throw value;
		}
		catch (std::exception)
		{

			std::cout << "Error. Try again. " << std::endl;
		}
		catch (int ex_value)
		{
			std::cout << ex_value << " Menu item does not exist. Try again." << std::endl;
		}
	}
}

std::string CheckLineString(std::ifstream& file)
{

	std::string tempValue = "";
	try
	{
		std::getline(file, tempValue);
		return tempValue;
	}
	catch (const std::exception)
	{
		std::cout << "There is not enough data in the file or incorrect file filling form." << std::endl;
		throw std::invalid_argument("Wrong type. Expected string");

	}
}

int CheckLineInt(std::ifstream& file)
{
	std::string tempValue = "";
	int tempInt = 0;
	try
	{
		std::getline(file, tempValue);
	}
	catch (const std::exception)
	{
		std::cout << "There is not enough data in the file or incorrect file filling form." << std::endl;
		throw std::invalid_argument("Not enough data");

	}
	try
	{
		tempInt = stoi(tempValue);
		if (tempInt < 0)

		{
			throw  std::invalid_argument("Out of range ");
		}
		else
			return tempInt;
	}
	catch (const std::exception)
	{
		std::cout << "Wrong data type." << std::endl;
		throw std::invalid_argument("Wrong data type.");
	}
}


//Check File

std::ofstream CheckFileOutput()
{

	const int thisFile = 1;
	std::string name;
	std::ofstream  FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckFileExist;
	CheckFileExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "Enter file name or full way." << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos) {
			std::cout << "Wrong data type\n" << std::endl;
			continue;
		}
		try
		{
			CheckFileExist.open(name);
			std::cout << "A file with the same name already exists. " << std::endl
				<< "1 - Save in this file " << std::endl
				<< "2 - Chose another name " << std::endl;
			int var = CheckMenuItem(2);
			if (var == thisFile)
			{
				FileRecorder.open(name);
				CheckFileExist.close();
			}
			else
			{
				CheckFileExist.close();
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
		}
		catch (const std::exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const std::exception&)
			{
				std::cout << "Access error" << std::endl;
				continue;
			}

		}
		return FileRecorder;
	}
}