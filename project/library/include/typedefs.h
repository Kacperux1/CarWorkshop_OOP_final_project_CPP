
#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

#include <memory>
#include <iostream>


class Client;
class Car;
class RepairOrder;
class RepairType;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<RepairOrder> OrderPtr;
typedef std::shared_ptr<RepairType> TypePtr;
typedef std::weak_ptr<Client> ClientWeakPtr;
typedef std::weak_ptr<Car> CarWeakPtr;
typedef std::weak_ptr<RepairOrder> WeakOrderPtr;

enum typeOfRepair {
    generalInspection=1,  // moze do usuniecia
    engineChange=2,
    gearboxRepair=3,
    lPGInstallation=4

};

inline int enterData() {
    int dana;
    dana = 0;
    std::cin >> dana;
    std::cout << std::endl;
    while(dana <= 0)
    {
        std::cout << "Given value cannot be equal or less than zero! Try again: ";
        std::cin >> dana;
        std::cout << std::endl;
    }
    return dana;
}





#endif //CARRENTAL_TYPEDEFS_H
