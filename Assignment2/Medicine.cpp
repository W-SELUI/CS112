#include "Medicine.h"
#include <iomanip>
#include <stdexcept>

Medicine::Medicine(int id, const std::string& name, int units)
    : medicineID(id), medicineName(name), unitsAvailable(0)
{
    setUnits(units);
}

int Medicine::getID() const
{
    return medicineID;
}

const std::string& Medicine::getName() const
{
    return medicineName;
}

int Medicine::getUnits() const
{
    return unitsAvailable;
}

void Medicine::setUnits(int units)
{
    if (units < 0)
        throw std::invalid_argument("Units cannot be negative.");
    unitsAvailable = units;
}

std::string Medicine::getStatus() const
{
    if (unitsAvailable > 0)
        return "[" + std::to_string(unitsAvailable) + " units] Available";
    return "Out of Stock";
}

std::ostream& operator<<(std::ostream& output, const Medicine& medicine)
{
    output << std::left << std::setw(12) << medicine.getID()
           << std::setw(32) << medicine.getName()
           << "  " << medicine.getStatus();
    return output;
}
