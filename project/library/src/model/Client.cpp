//
// Created by ANDRZEJ on 21.05.2024.
//

#include "model/Client.h"
#include <sstream>
#include "model/RepairOrder.h"
#include "model/RepairType.h"


Client::Client(const std::string &name, const std::string &surname, int clientId) : name(name), surname(surname),
                                                                                    clientID(clientId) {}
Client::~Client() = default;

int Client::getClientId() const {
    return clientID;
}

const std::string &Client::getSurname() const {
    return surname;
}

const std::string &Client::getName() const {
    return name;
}

std::string Client::getClientInfo() const {
    std::stringstream s;
    s<<"Name: "<<name<<", surname: "<<surname<<", client ID: "<<clientID;
    return s.str();
}
