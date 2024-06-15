//
// Created by ANDRZEJ on 21.05.2024.
//

#include "managers/RepairOrderManager.h"
#include "model/RepairOrder.h"
#include "model/Car.h"


RepairOrderManager::RepairOrderManager() {orders=std::make_unique<RepairOrderRepository>();}

RepairOrderManager::~RepairOrderManager() = default;

int RepairOrderManager::count() {
    return orders->getSize();
}

OrderPtr RepairOrderManager::findOrder(const int &id) {
    if(orders->findById(id)!=nullptr)
        return orders->findById(id);
    return nullptr;
}

void RepairOrderManager::createOrder(const int &id, const int &daysForRepair, const ClientPtr &client, const CarPtr &car, const typeOfRepair type) {
    OrderPtr order = std::make_shared<RepairOrder>(id, daysForRepair, client, car);
    car->setOrder(order);
    orders->add(order);

    changeRepairType(order,type);
}

ClientPtr RepairOrderManager::findClient(const int &id) {
    if(orders->findById(id)!= nullptr)
        return orders->findById(id)->getClient();
    return nullptr;
}

void RepairOrderManager::writeToFile() {
    orders->toFile();
}

void RepairOrderManager::changeRepairType(const OrderPtr& order, typeOfRepair type) {
    int basePrice;
    bool flag=true;
    while(flag) {
        switch (type) {
            case engineChange:
                std::cout << "You are changing type of repair to Engine Change." << std::endl;

                int engineDisplacement;
                std::cout << "Enter engine displacement: ";
                engineDisplacement = enterData();

                int horsePower;
                std::cout << "Enter horse power: ";
                horsePower = enterData();


                order->changeTypeToEngineChange(engineDisplacement, horsePower, basePrice);
                flag=false;
                break;
            case generalInspection:
                std::cout << "You are changing type of repair to general inspection." << std::endl;

                std::cout << "Enter base price: ";
                basePrice = enterData();

                order->changeTypeToGeneralInspection(basePrice);
                flag=false;
                break;
            case gearboxRepair:
                std::cout << "You are changing type of repair to gearbox repair." << std::endl;

                bool isAutomatic;
                isAutomatic = false;
                char automatic;
                automatic = 'Z';
                while (automatic != 'Y' || automatic != 'N') {
                    std::cout << "If the car has automatic transmission enter Y otherwise enter N: ";
                    std::cin >> automatic;
                    std::cout << std::endl;
                    if (automatic == 'Y')
                        isAutomatic = true;
                }

                std::cout << "Enter base price: ";
                basePrice = enterData();

                order->changeTypeToGearboxRepair(isAutomatic, basePrice);
                flag=false;
                break;
            case lPGInstallation:
                std::cout << "You are changing type of repair to LPG installation." << std::endl;

                int tankCapacity;
                std::cout << "Enter tank capacity: ";
                tankCapacity = enterData();

                std::cout << "Enter base price: ";
                basePrice = enterData();

                order->changeTypeToLPGInstallation(tankCapacity, basePrice);
                flag=false;
                break;
            default:
                std::cout<<"Unknown Option. Please try again."<<std::endl;
        }
    }
}

std::string RepairOrderManager::findAllClientsOrders(ClientPtr client) {
    return orders->getOrdersOwnedBy(client);
}

void RepairOrderManager::archive(OrderPtr order) {
    orders->archive(order);

}

std::string RepairOrderManager::getAllOrderInfo() const {
    return orders->info();
}

void RepairOrderManager::returnOrder(const int &id) {
        orders->returnOrder(id);
}

CarPtr RepairOrderManager::findCar(const int &id) {
    if(orders->findById(id)!=nullptr)
        return orders->findById(id)->getCar();
    return nullptr;
}


