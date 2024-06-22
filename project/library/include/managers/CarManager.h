//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_CARMANAGER_H
#define CARWORKSHOP_CARMANAGER_H


#include <memory>
#include "repositories/CarRepository.h"

class CarManager {
    std::unique_ptr<CarRepository> cars;
public:
    /**
     * Constructor for class CarManager
     */
    CarManager();

    /**
     * Destructor for class CarManager
     */
    virtual ~CarManager();

    /**
     * This method checks how many cars are in carRepository(by calling method getSize() in repository)
     * @return
     */
    int count();

    /**
     * This method finds car with given registration number(by calling method findById() in repository)
     * @param id
     * @return
     */
    CarPtr findCar(std::string &id);

    /**
     * This method constructs new car object and adds it to repository.
     * Cars registration number must be unique so first we check
     * if in repository there already is car with given registration.
     * @param registrationNumber
     * @param brand
     * @param model
     * @param productionYear
     * @param client
     */
    void addCar(const std::string &registrationNumber, const std::string &brand, const std::string &model,
                const int &productionYear, ClientPtr client);

    /**
     * This method searches for car with given registration number
     * and then returns information about cars owner
     * @param id
     * @return
     */
    ClientPtr findCarOwner(const std::string &id);

    /**
     * Returns infromation about all Cars owned by client
     * @param client
     * @return
     */
    std::string findAllClientsCar(ClientPtr client);

    /**
     * This method searches for car with given registration number
     * and then returns information about ordered repairs
     * @param id
     * @return
     */
    OrderPtr findCarOrder(const std::string &id);

    /**
     * Returns information about every car in carRepository
     * @return
     */
    std::string getAllCarInfo();

    /**
     * This method saves state of repository to file(by calling method toFile() in repository)
     */
    void writeToFile();
};


#endif //CARWORKSHOP_CARMANAGER_H
