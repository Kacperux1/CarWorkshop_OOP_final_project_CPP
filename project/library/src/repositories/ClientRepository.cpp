//
// Created by ANDRZEJ on 21.05.2024.
//

#include "repositories/ClientRepository.h"
#include <algorithm>
#include <filesystem>
#include "model/Client.h"
#include "cereal/archives/json.hpp"
#include "cereal/cereal.hpp"
#include "cereal/types/vector.hpp"
#include <memory>


ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {

}

void ClientRepository::add(ClientPtr client) {
    if (client != nullptr)
        clients.push_back(client);
}



void ClientRepository::remove(ClientPtr client) {
    clients.erase(find(clients.begin(), clients.end(), client));
}

ClientPtr ClientRepository::findById(int id) {
    ClientPtr result;
    auto temp=std::find_if(clients.begin(), clients.end(), [&id](const ClientPtr & client) {
        return client->getClientId() == id;});
    if(temp==clients.end())
    {
        throw std::logic_error("There is no such Client!");
    }
    result=*temp;
    return result;
}



int ClientRepository::getSize() {
    return clients.size();
}

void ClientRepository::toFile() {
    std::ofstream os("clients.json");
    if (!os.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }
    std::cout << "Clients data will be written to: " << std::filesystem::absolute("clients.json") << std::endl;
    cereal::JSONOutputArchive archive(os);
    archive(clients);
    std::cout << "Data has been written to clients.json" << std::endl;

}

std::string ClientRepository::info() {
        std::stringstream s;
        for(auto &iter :clients)
            s<<iter->getClientInfo();
        return s.str();

}
