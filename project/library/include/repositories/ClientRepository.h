//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_CLIENTREPOSITORY_H
#define CARWORKSHOP_CLIENTREPOSITORY_H


#include <deque>
#include <vector>
#include "typedefs.h"

class ClientRepository {
    std::vector<ClientPtr> clients;
public:
    /**
     * Constructor for class ClientRepository
     */
    ClientRepository();

    /**
     * Destructor for class ClientRepository
     */
    virtual ~ClientRepository();

    /**
     * This method adds client(given by pointer) to repository
     * @param client
     */
    void add(ClientPtr client);

    /**
     * This method removes client(given by pointer) form repository
     * @param client
     */
    void remove(ClientPtr client);

    /**
     * This method finds car by it's unique identification number
     * @param id
     * @return
     */
    ClientPtr findById(int id);

    /**
     * Returns how many clients are in the repository
     * @return
     */
    int getSize();

    /**
     * This method saves state of repository to file
     */
    void toFile();
    /**
     * method returning info about all clients.
     * @return string
     */
    std::string info();

};


#endif //CARWORKSHOP_CLIENTREPOSITORY_H
