//
// Created by ANDRZEJ on 21.05.2024.
//

#include "managers/CarManager.h"
#include <iostream>
#include "model/Car.h"
#include "model/Client.h"
#include "cereal/archives/json.hpp"
#include "managers/ClientManager.h"


CarManager::CarManager() {cars=std::make_unique<CarRepository>();}

CarManager::~CarManager() = default;

int CarManager::count() {
    return cars->getSize();
}

CarPtr CarManager::findCar(std::string &id) {
    return cars->findByNumber(id);
}

void CarManager::addCar(const std::string &registrationNumber, const std::string &brand, const std::string &model,
                        const int &productionYear, ClientPtr client) {
    cars->add(std::make_shared<Car>(brand, model, productionYear, registrationNumber, client));
}

ClientPtr CarManager::findCarOwner(const std::string &id) {
    if(cars->findByNumber(id)!= nullptr)
        return ((cars->findByNumber(id))->getClient());
    return nullptr;
}

OrderPtr CarManager::findCarOrder(const std::string &id) {
    if(cars->findByNumber(id)!= nullptr)
        return ((cars->findByNumber(id))->getOrder());
    return nullptr;
}

std::string CarManager::findAllClientsCar(ClientPtr client) {
    return cars->getCarsOwnedBy(client);
}

void CarManager::writeToFile() {
   cars->toFile();
}

std::string CarManager::getAllCarInfo() {
    return cars->info();
}


