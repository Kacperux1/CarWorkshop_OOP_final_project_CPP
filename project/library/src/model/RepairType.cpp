//
// Created by ANDRZEJ on 21.05.2024.
//

#include "model/RepairType.h"

RepairType::RepairType(const int basePrice) : basePrice(basePrice) {}

RepairType::~RepairType() {}

int RepairType::getBasePrice() const {
    return basePrice;
}
