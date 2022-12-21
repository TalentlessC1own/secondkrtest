#pragma once

#include <iostream>
#include <fstream>
//#include <ostream>
#include <string>

int CheckIntValue();

int CheckMenuItem(int numberOfPoints);

std::string CheckLineString(std::ifstream& file);

int CheckLineInt(std::ifstream& file);



std::ofstream CheckFileOutput();
