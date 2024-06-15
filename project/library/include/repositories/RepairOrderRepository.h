//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_REPAIRORDERREPOSITORY_H
#define CARWORKSHOP_REPAIRORDERREPOSITORY_H


#include <deque>
#include <vector>
#include "typedefs.h"

class RepairOrderRepository {
    std::vector<OrderPtr> orders;
    std::vector<OrderPtr> archivedOrders;
public:
    /**
     * Constructor for class RepairOrderRepository
     */
    RepairOrderRepository();

    /**
     * Destructor for class RepairOrderRepository
     */
    virtual ~RepairOrderRepository();

    /**
     * This method adds repairOrder(given by pointer) to repository
     * @param order
     */
    void add(OrderPtr order);

    /**
     * This method removes repairOrder(given by pointer) form repository
     * @param order
     */
    void remove (OrderPtr order);

    /**
     * This method finds car by it's unique identification number((plate number)
     * @param id
     * @return
     */
    OrderPtr findById(int id);

    /**
     * Returns how many repairOrders are in the repository
     * @return
     */
    int getSize();

    /**
     * Returns information about clients orders
     * @param client
     * @return
     */
    std::string getOrdersOwnedBy(ClientPtr &client);

    /**
     * This method saves state of repository to file
     */
    void toFile();

    /**
     * This metod "returns" repaird car to client
     * @param id
     */
    void returnOrder(int id);

    /**
     * method moving the order to the archive, (meaning that is no longer active)
     * @param order
     */
    void archive(const OrderPtr& order);

    /**
     * method returning info about all current orders
     * @return
     */
    std::string info() const;

private:
    /**
     * method writing the info about archived objects into file (used when destructor is called)
     */
    void archivedOrdersToFile();



};


#endif //CARWORKSHOP_REPAIRORDERREPOSITORY_H
