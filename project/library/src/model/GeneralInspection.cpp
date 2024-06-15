//
// Created by ANDRZEJ on 21.05.2024.
//

#include <sstream>
#include "model/GeneralInspection.h"

std::string GeneralInspection::getTypeInfo() const {
    std::stringstream s;
    s<<"Repair type - general inspection";
    return s.str();
}

int GeneralInspection::getRepairPrice() {
    return getBasePrice();
}

GeneralInspection::GeneralInspection(const int basePrice) : RepairType(basePrice) {}

GeneralInspection::~GeneralInspection() = default;
