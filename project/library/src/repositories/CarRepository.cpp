//
// Created by ANDRZEJ on 21.05.2024.
//

#include "repositories/CarRepository.h"
#include <algorithm>
#include <fstream>
#include "model/Car.h"
#include "cereal/archives/json.hpp"
#include "cereal/types/memory.hpp"
#include "cereal/types/vector.hpp"
#include <memory>
#include <filesystem>


CarRepository::CarRepository() = default;

CarRepository::~CarRepository() = default;

void CarRepository::add(CarPtr car) {
    if(car!= nullptr)
        cars.push_back(car);
}

void CarRepository::remove(CarPtr car) {
    cars.erase(find(cars.begin(), cars.end(), car));
}

CarPtr CarRepository::findByNumber(std::string id) {
    CarPtr result;
    auto temp=std::find_if(cars.begin(), cars.end(), [&id](const CarPtr & car) {
        return car->getRegistrationNumber() == id;});
    if(temp==cars.end())
    {
        throw std::logic_error("There is no such Car!");
    }
    result=*temp;
    return result;
}

int CarRepository::getSize() {
    return cars.size();
}

std::string CarRepository::getCarsOwnedBy(ClientPtr &client) {
    std::stringstream s;
    for(auto &iter :cars)
        if(iter->getClient()==client)
            s<<iter->getInfo()<<std::endl;
    return s.str();
}

void CarRepository::toFile() {
    std::ofstream os("cars.json");
    if (!os.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }
    std::cout << "Cars data will be written to: " << std::filesystem::absolute("cars.json") << std::endl;
    cereal::JSONOutputArchive archive(os);
    archive(cars);
    std::cout << "Data has been written to cars.json" << std::endl;
}

std::string CarRepository::info() {
    std::stringstream s;
    for(auto &iter :cars)
        s<<iter->getInfo();
    return s.str();

}



