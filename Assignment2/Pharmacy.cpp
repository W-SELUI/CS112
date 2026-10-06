#include "Pharmacy.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

namespace
{
    std::string trim(const std::string& text)
    {
        const std::string::size_type first = text.find_first_not_of(" \t\r\n");
        if (first == std::string::npos)
            return "";
        const std::string::size_type last = text.find_last_not_of(" \t\r\n");
        return text.substr(first, last - first + 1);
    }

    bool parseInteger(const std::string& text, int& value)
    {
        std::istringstream input(text);
        if (!(input >> value))
            return false;
        input >> std::ws;
        return input.eof();
    }

    int findMedicineIndex(const List<Medicine>& medicines, int id)
    {
        for (int index = 0; index < medicines.getSize(); ++index)
        {
            if (medicines.getAt(index).getID() == id)
                return index;
        }
        return -1;
    }
}

bool readInteger(const std::string& prompt, int minimum, int maximum, int& value)
{
    std::string line;
    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, line))
            return false;

        if (parseInteger(line, value) && value >= minimum && value <= maximum)
            return true;

        std::cout << "Invalid input. Enter a whole number from "
                  << minimum << " to " << maximum << ".\n";
    }
}

bool loadMedicinesFromFile(const std::string& filename, List<Medicine>& medicines)
{
    std::ifstream input(filename);
    if (!input)
    {
        std::cerr << "Error: Cannot open " << filename
                  << ". Place it in the project's working folder.\n";
        return false;
    }

    medicines.clear();
    std::string line;
    int lineNumber = 0;
    while (std::getline(input, line))
    {
        ++lineNumber;
        if (trim(line).empty())
            continue;

        std::istringstream record(line);
        std::string idText;
        std::string name;
        std::string unitsText;
        int id = 0;
        int units = 0;

        const bool validFields =
            static_cast<bool>(std::getline(record, idText, ',')) &&
            static_cast<bool>(std::getline(record, name, ',')) &&
            static_cast<bool>(std::getline(record, unitsText));

        name = trim(name);
        if (!validFields || !parseInteger(idText, id) || name.empty() ||
            !parseInteger(unitsText, units) || units < 0)
        {
            std::cerr << "Error: Invalid medicine record on line "
                      << lineNumber << " of " << filename << ".\n";
            medicines.clear();
            return false;
        }

        if (findMedicineIndex(medicines, id) != -1)
        {
            std::cerr << "Error: Duplicate medicine ID on line "
                      << lineNumber << " of " << filename << ".\n";
            medicines.clear();
            return false;
        }

        medicines.appendNode(Medicine(id, name, units));
    }

    if (input.bad())
    {
        std::cerr << "Error: Failed while reading " << filename << ".\n";
        medicines.clear();
        return false;
    }
    return true;
}

bool saveMedicinesToFile(const std::string& filename, const List<Medicine>& medicines)
{
    std::ofstream output(filename);
    if (!output)
        return false;

    for (int index = 0; index < medicines.getSize(); ++index)
    {
        const Medicine& medicine = medicines.getAt(index);
        output << medicine.getID() << ',' << medicine.getName() << ','
               << medicine.getUnits() << '\n';
    }
    output.close();
    return !output.fail();
}

void printAllRecords(const List<Medicine>& medicines)
{
    std::cout << '\n' << std::left
              << std::setw(12) << "ID"
              << std::setw(32) << "Medicine Name"
              << "  Availability\n"
              << std::string(72, '-') << '\n';

    if (medicines.isEmpty())
        std::cout << "No medicines loaded.\n";
    else
        medicines.printList();
}

void updateUnits(List<Medicine>& medicines, const std::string& filename)
{
    if (medicines.isEmpty())
    {
        std::cout << "No medicines are available to update.\n";
        return;
    }

    int id = 0;
    if (!readInteger("Enter the Medicine ID to update: ",
                     std::numeric_limits<int>::min(),
                     std::numeric_limits<int>::max(), id))
        return;

    const int index = findMedicineIndex(medicines, id);
    if (index == -1)
    {
        std::cout << "No medicine with that ID was found.\n";
        return;
    }

    Medicine& medicine = medicines.getAt(index);
    std::cout << "Medicine: " << medicine.getName()
              << " | Current units: " << medicine.getUnits() << '\n';

    int newUnits = 0;
    if (!readInteger("Enter the new number of units: ", 0,
                     std::numeric_limits<int>::max(), newUnits))
        return;

    // Match Assignment 1: replace the total, then save the records.
    medicine.setUnits(newUnits);
    if (saveMedicinesToFile(filename, medicines))
        std::cout << "Medicine units updated and saved successfully.\n";
    else
        std::cerr << "Units updated in memory, but could not be saved to "
                  << filename << ".\n";
}

void printFullReport(const List<Medicine>& medicines)
{
    std::cout << "\n----- USP Pharmacy Stock Report -----\n";
    printAllRecords(medicines);

    long long totalUnits = 0;
    int outOfStockCount = 0;
    int highestIndex = -1;

    for (int index = 0; index < medicines.getSize(); ++index)
    {
        const Medicine& medicine = medicines.getAt(index);
        totalUnits += medicine.getUnits();
        if (medicine.getUnits() == 0)
            ++outOfStockCount;

        // Keep the first medicine when two medicines share the highest stock.
        if (highestIndex == -1 ||
            medicine.getUnits() > medicines.getAt(highestIndex).getUnits())
            highestIndex = index;
    }

    std::cout << "\nTotal units in stock: " << totalUnits << '\n';
    if (highestIndex == -1)
    {
        std::cout << "No medicines available for the highest-stock calculation.\n";
    }
    else
    {
        const Medicine& highest = medicines.getAt(highestIndex);
        std::cout << "\nMedicine with the highest units:\n"
                  << "ID: " << highest.getID() << '\n'
                  << "Name: " << highest.getName() << '\n'
                  << "Units: " << highest.getUnits() << '\n'
                  << "Status: " << highest.getStatus() << '\n';
    }

    const double percentage = medicines.isEmpty()
        ? 0.0 : 100.0 * outOfStockCount / medicines.getSize();
    std::cout << std::fixed << std::setprecision(2)
              << "\nPercentage out of stock: " << percentage << "%\n";
}
