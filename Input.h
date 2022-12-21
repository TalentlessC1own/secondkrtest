#pragma once
#include <iostream>

#include "InputCheck.h"
#include "Vehicle.h"
#include "Airplane.h"
#include "Mlrt_Trnsp.h"
#include <vector>

enum class PlaneType
{
	Mltr = 1,
	Trnsp,
	Enough
};

void ConsoleInput(std::vector<std::shared_ptr<Airplane>>& VehicleCase);

void FileInput(std::vector<std::shared_ptr<Airplane>>& VehicleCase);