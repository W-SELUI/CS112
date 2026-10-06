#ifndef MEDICINE_H
#define MEDICINE_H

#include <ostream>
#include <string>

class Medicine
{
private:
    int medicineID;
    std::string medicineName;
    int unitsAvailable;

public:
    Medicine(int id, const std::string& name, int units);

    int getID() const;
    const std::string& getName() const;
    int getUnits() const;
    void setUnits(int units);
    std::string getStatus() const;
};

// Lets the lecture's generic printList() print Medicine objects.
std::ostream& operator<<(std::ostream& output, const Medicine& medicine);

#endif
