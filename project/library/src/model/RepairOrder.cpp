//
// Created by ANDRZEJ on 21.05.2024.
//

#include "model/RepairOrder.h"
#include <cmath>
#include <memory>
#include "model/EngineChange.h"
#include "model/GeneralInspection.h"
#include "model/GearboxRepair.h"
#include "model/LPGInstallation.h"


RepairOrder::~RepairOrder() {

}

int RepairOrder::getCost() const {
    boost::gregorian::date_duration dd=returnDate-acceptanceDate;
    if(dd.days()>daysForRepair)
        return (repairType->getRepairPrice())*pow(0.98, dd.days()-daysForRepair);
    return repairType->getRepairPrice();
}

int RepairOrder::getDaysForRepair() const {
    return daysForRepair;
}

const gt::date &RepairOrder::getReturnDate() const {
    return returnDate;
}

const gt::date &RepairOrder::getAcceptanceDate() const {
    return acceptanceDate;
}

int RepairOrder::getId() const {
    return id;
}

std::string RepairOrder::getInfo() const {
    std::stringstream s;
    s<<"ID: "<<std::to_string(id)<<", "<<repairType->getTypeInfo()<<", acceptance date:"<<gt::to_simple_string(acceptanceDate)
    <<", cost: "<<std::to_string(repairType->getRepairPrice());
    if(returnDate!=gt::date(boost::date_time::not_a_date_time))
        s<<", return date: "<<gt::to_simple_string(returnDate);
    return s.str();
}

RepairOrder::RepairOrder(int id, int daysForRepair, const ClientPtr &client, const CarWeakPtr &car) : id(id),
daysForRepair(daysForRepair),client(client),car(car), returnDate(gt::not_a_date_time)
{
    if(car.lock()->isRepaired())
    {
        throw std::logic_error("Car is already in workshop!");
    }
    acceptanceDate=boost::posix_time::second_clock::local_time().date();
    repairType = nullptr;
}

void RepairOrder::changeTypeToEngineChange(int engineDisplacement, int horsePower, int basePrice) {
    repairType = std::make_shared<EngineChange>(engineDisplacement, horsePower, basePrice);
}

void RepairOrder::changeTypeToGearboxRepair(bool isAutomatic, int basePrice) {
    repairType = std::make_shared<GearboxRepair>(isAutomatic, basePrice);
}

void RepairOrder::changeTypeToGeneralInspection(int basePrice) {
    repairType = std::make_shared<GeneralInspection>(basePrice);
}

void RepairOrder::changeTypeToLPGInstallation(int tankCapacity, int basePrice) {
    repairType = std::make_shared<LPGInstallation>(tankCapacity, basePrice);
}

void RepairOrder::returnOrder() {
    returnDate=boost::posix_time::second_clock::local_time().date();
    car.lock()->setOrder(nullptr);
}

const ClientPtr &RepairOrder::getClient() const {
    return client;
}

const CarPtr RepairOrder::getCar() const {
    return car.lock();
}

const TypePtr &RepairOrder::getRepairType() const {
    return repairType;
}