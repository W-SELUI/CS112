#ifndef PHARMACY_H
#define PHARMACY_H

#include "List.h"
#include "Medicine.h"
#include <string>

bool readInteger(const std::string& prompt, int minimum, int maximum, int& value);
bool loadMedicinesFromFile(const std::string& filename, List<Medicine>& medicines);
bool saveMedicinesToFile(const std::string& filename, const List<Medicine>& medicines);
void printAllRecords(const List<Medicine>& medicines);
void updateUnits(List<Medicine>& medicines, const std::string& filename);
void printFullReport(const List<Medicine>& medicines);

#endif
