//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_CARREPOSITORY_H
#define CARWORKSHOP_CARREPOSITORY_H


#include <vector>
#include "typedefs.h"

class CarRepository {
    std::vector<CarPtr> cars;
public:
    /**
     * Constructor for class CarRepository
     */
    CarRepository();

    /**
     * Destructor for class CarRepository
     */
    virtual ~CarRepository();

    /**
     * This method adds car(given by pointer) to repository
     * @param car
     */
    void add(CarPtr car);

    /**
     * This method removes car(given by pointer) form repository
     * @param car
     */
    void remove(CarPtr car);

    /**
     * This method finds car by it's unique registration number
     * @param id
     * @return
     */
    CarPtr findByNumber(std::string id);

    /**
     * Returns how many cars are in the repository
     * @return
     */
    int getSize();

    /**
     * Returns information about all
     * @param client
     * @return
     */
    std::string getCarsOwnedBy(ClientPtr &client);

    /**
  * method returning info about all cars;
  * @return string
  */
    std::string info();

    /**
     * This method saves state of repository to file
     */
    void toFile();
};


#endif //CARWORKSHOP_CARREPOSITORY_H
