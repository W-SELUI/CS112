#include "Pharmacy.h"
#include <iostream>
#include <string>

int main()
{
    const std::string filename = "medicines.txt";
    List<Medicine> medicines;

    if (!loadMedicinesFromFile(filename, medicines))
        return 1;

    std::cout << "Loaded " << medicines.getSize() << " medicine records.\n";

    int choice = 0;
    while (true)
    {
        std::cout << "\n---------- USP Pharmacy ----------\n"
                  << "1. Print all medicine records\n"
                  << "2. Update units for a medicine\n"
                  << "3. Print full stock report\n"
                  << "4. Exit\n";

        if (!readInteger("Enter your choice: ", 1, 4, choice))
        {
            std::cout << "\nInput ended. Goodbye!\n";
            break;
        }

        switch (choice)
        {
        case 1:
            printAllRecords(medicines);
            break;
        case 2:
            updateUnits(medicines, filename);
            break;
        case 3:
            printFullReport(medicines);
            break;
        case 4:
            std::cout << "Goodbye!\n";
            return 0;
        }
    }

    return 0;
}
