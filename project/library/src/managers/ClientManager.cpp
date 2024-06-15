//
// Created by ANDRZEJ on 21.05.2024.
//

#include "managers/ClientManager.h"
#include "model/Client.h"


ClientManager::ClientManager() {clients=std::make_unique<ClientRepository>();}

ClientManager::~ClientManager() = default;

int ClientManager::count() {
   return clients->getSize();
}

ClientPtr ClientManager::findClient(int id) {
    return clients->findById(id);
}

void ClientManager::addClient(const int &clientId, const std::string &name, const std::string &surname) {
    clients->add(std::make_shared<Client>(name, surname, clientId));
}

void ClientManager::writeToFile() {
    clients->toFile();
}

std::string ClientManager::getAllClientInfo() const {
    return clients->info();
}


