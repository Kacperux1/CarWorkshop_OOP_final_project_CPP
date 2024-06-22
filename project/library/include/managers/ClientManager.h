//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_CLIENTMANAGER_H
#define CARWORKSHOP_CLIENTMANAGER_H


#include <memory>
#include "repositories/ClientRepository.h"

class ClientManager {
    std::unique_ptr<ClientRepository> clients;

public:
    /**
     * Constructor for class ClientManager
     */
    ClientManager();

    /**
     * Destructor for class ClientManager
     */
    virtual ~ClientManager();

    /**
     * This method checks how many clients are in clientRepository(by calling method getSize() in repository)
     * @return
     */
    int count();

    /**
     * This method finds client with given identification number(by calling method findById() in repository)
     * @param id
     * @return
     */
    ClientPtr findClient(int id);

    /**
     * This method constructs new client object and adds it to repository.
     * Clients identification number must be unique so first we check
     * if in repository there already is client with given ID number.
     * @param clientId
     * @param name
     * @param surname
     */
    void addClient(const int &clientId, const std::string &name, const std::string &surname);

    /**
     * This method saves state of repository to file(by calling method toFile() in repository)
     */
    void writeToFile();

    std::string getAllClientInfo() const;

};


#endif //CARWORKSHOP_CLIENTMANAGER_H
