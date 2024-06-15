//
// Created by ANDRZEJ on 21.05.2024.
//

#include <sstream>
#include "model/EngineChange.h"

EngineChange::EngineChange(int engineDisplacement, int horsePower,  int basePrice) : RepairType(basePrice),
                                                                                            engineDisplacement(
                                                                                                    engineDisplacement),
                                                                                            horsePower(horsePower) {}

EngineChange::~EngineChange() = default;

int EngineChange::getEngineDisplacement() const {
    return engineDisplacement;
}

int EngineChange::getHorsePower() const {
    return horsePower;
}

int EngineChange::getRepairPrice() {
    return getBasePrice()+5*engineDisplacement+5*horsePower;
}

std::string EngineChange::getTypeInfo() const {
    std::stringstream s;
    s<<"Type of repair: engine change, displacement of the new engine: "<<std::to_string(engineDisplacement)<<", power: "<<std::to_string(horsePower);
    return s.str();

}
