//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_REPAIRORDERMANAGER_H
#define CARWORKSHOP_REPAIRORDERMANAGER_H


#include <memory>
#include "repositories/RepairOrderRepository.h"

class RepairOrderManager {
    std::unique_ptr<RepairOrderRepository> orders;
public:
    /**
     * Constructor for class RepairOrderManager
     */
    RepairOrderManager();

    /**
     * Destructor for class RepairOrderManager
     */
    virtual ~RepairOrderManager();

    /**
     * This method checks how many repairOrders are in RepairOrderRepository(by calling method getSize() in repository)
     * @return
     */
    int count();

    /**
     * This method finds repairOrder with given identification number(by calling method findById() in repository)
     * @param id
     * @return
     */
    OrderPtr findOrder(const int &id);

    /**
     * This method constructs new repairOrder object and adds it to repository.
     * RepairOrder identification number must be unique so first we check
     * if in repository there already is repairOrder with given ID number.
     * @param id
     * @param daysForRepair
     * @param client
     * @param car
     * @param type
     */
    void createOrder(const int &id, const int &daysForRepair, const ClientPtr &client, const CarPtr &car, const typeOfRepair type);

    /**
     * This method searches for repairOrder with given ID number
     * and then returns information about client who ordered this repair.
     * @param id
     * @return
     */
    ClientPtr findClient(const int &id);

    /**
     * This method returns pointer to car with given id
     * @param id
     * @return
     */
    CarPtr findCar(const int &id);

    /**
     * This method returns informations about all orders owned by client
     * @param client
     * @return
     */
    std::string findAllClientsOrders(ClientPtr client);

    /**
     * This method saves state of repository to file(by calling method toFile() in repository)
     */
    void writeToFile();

    /**
     * This method returns an order of certain id (entered by user).
     * @param id
     */
    void returnOrder(const int &id);

    /**
     * This method can change type of repair that was ordered for car.
     * It takes information from user and than calls constructor of repairOrder subclass
     * with given data.
     * @param order
     * @param type
     */
    void changeRepairType(const OrderPtr& order, typeOfRepair type);

    /**
     * method moving the certain order to archived ones.
     * @param order
     */
    void archive(OrderPtr order);

    /**
     * Method returning info about all current orders.
     * @return
     */
    std::string getAllOrderInfo() const;


};


#endif //CARWORKSHOP_REPAIRORDERMANAGER_H
