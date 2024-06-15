//
// Created by ANDRZEJ on 21.05.2024.
//

#include <sstream>
#include "model/GearboxRepair.h"

GearboxRepair::GearboxRepair(bool automatic, int basePrice) : RepairType(basePrice), automatic(automatic) {}

GearboxRepair::~GearboxRepair() = default;

bool GearboxRepair::isAutomatic() const {
    return automatic;
}

int GearboxRepair::getRepairPrice() {
    if(automatic)
        return getBasePrice()*3;
    return getBasePrice();
}

std::string GearboxRepair::getTypeInfo() const {
    std::stringstream s;
    s<<"Type of repair - gearbox repair, gearbox type: ";
    if(automatic)
        s<<"automatic";
    else
        s<<"manual";
    return s.str();
}
