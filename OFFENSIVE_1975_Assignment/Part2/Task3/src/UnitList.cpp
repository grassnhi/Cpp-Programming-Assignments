#include "UnitList.h"

UnitList::UnitList(int S)
{
    // TODO: Implement
    // Truyền S = EXP + LF
    // Hint: Bạn có thể sử dụng hàm isSpecial() tự định nghĩa để kiểm tra xem S có phải là số chính phương hay không.
    if (isSpecial(S)) this->capacity = 12;
    else this->capacity = 8;
}

bool UnitList::insert(Unit *unit)
{
}

bool UnitList::isContain(VehicleType vehicleType)
{
}

bool UnitList::isContain(InfantryType infantryType)
{
}

/* vector<Unit *>& UnitList::getUnits() {
    return units;
} */

string UnitList::str() const
{
}
