//
// Created by ANDRZEJ on 21.05.2024.
//

#include <sstream>
#include "model/LPGInstallation.h"



LPGInstallation::~LPGInstallation() = default;

int LPGInstallation::getLpgTankCapacity() const {
    return lpgTankCapacity;
}

LPGInstallation::LPGInstallation(int lpgTankCapacity, const int basePrice) : RepairType(basePrice),
                                                                               lpgTankCapacity(lpgTankCapacity) {}

int LPGInstallation::getRepairPrice() {
    if(lpgTankCapacity<35)
        return getBasePrice();
    else
        if(lpgTankCapacity<45)
            return getBasePrice()*2;
        else
            return getBasePrice()*3;

}

std::string LPGInstallation::getTypeInfo() const {
    std::stringstream s;
    s<<"Repair type - LPG installation, tank capacity: "<<std::to_string(lpgTankCapacity);
    return s.str();

}
