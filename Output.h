#pragma once

#include "Vehicle.h"
#include"Airplane.h"
#include"Mlrt_Trnsp.h"
#include <vector>
#include "InputCheck.h"

void ConsoleOutput(std::vector<std::shared_ptr<Airplane>>& VehicleCase);

void FileOutput(std::vector<std::shared_ptr<Airplane>>& VehicleCase);

void InitialDataOutput(std::vector<std::shared_ptr<Airplane>>& VehicleCase);