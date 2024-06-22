//
// Created by ANDRZEJ on 21.05.2024.
//

#include <sstream>
#include "model/Car.h"
#include "model/Client.h"

Car::Car(const std::string &brand, const std::string &model, int productionYear, const std::string &registrationNumber,
         const ClientPtr &client) : brand(brand), model(model), productionYear(productionYear),
                                    registrationNumber(registrationNumber), client(client), order(nullptr) {}

Car::~Car() = default;

int Car::getProductionYear() const {
    return productionYear;
}

const std::string &Car::getModel() const {
    return model;
}

const std::string &Car::getBrand() const {
    return brand;
}

bool Car::isRepaired() const {
    if(order==nullptr)
        return false;
    throw std::logic_error("Car is in workshop!");
}

const std::string &Car::getRegistrationNumber() const {
    return registrationNumber;
}

const ClientPtr &Car::getClient() const {
    return client;
}

const OrderPtr &Car::getOrder() const {
    return order;
}

std::string Car::getInfo() const {
    std::stringstream s;
    s<<"Brand: "<<brand<<", model: "<<model<<", prod. year: "<<std::to_string(productionYear)<<", plate number:"<<registrationNumber;
    return s.str();
}

void Car::setOrder(const OrderPtr &order) {
    Car::order = order;
}


