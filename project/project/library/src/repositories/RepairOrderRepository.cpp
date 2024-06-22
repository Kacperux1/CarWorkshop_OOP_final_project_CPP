
#include "repositories/RepairOrderRepository.h"
#include <algorithm>
#include <filesystem>
#include "model/RepairOrder.h"
#include "cereal/archives/json.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/types/memory.hpp"
#include "cereal/types/vector.hpp"
#include <memory>
#include <filesystem>

RepairOrderRepository::RepairOrderRepository() {}

RepairOrderRepository::~RepairOrderRepository() {
    archivedOrdersToFile();
}

void RepairOrderRepository::add(OrderPtr order) {
    if(order->getCar()!= nullptr)
        orders.push_back(order);
}

void RepairOrderRepository::remove(OrderPtr order) {
    orders.erase(find(orders.begin(), orders.end(), order));
}

OrderPtr RepairOrderRepository::findById(int id) {
    OrderPtr result;
    auto temp=std::find_if(orders.begin(), orders.end(), [id](const OrderPtr & order) {
        return order->getId() == id;});
    if(temp==orders.end())
    {
        throw std::logic_error("There is no such Repair Order!");
    }
    result=*temp;
    return result;
}

int RepairOrderRepository::getSize() {
    return orders.size();
}

std::string RepairOrderRepository::getOrdersOwnedBy(ClientPtr &client) {
    std::stringstream s;
    for(auto &iter : orders)
        if(iter->getClient()==client)
             s<<iter->getInfo()<<std::endl;
    return s.str();
}

void RepairOrderRepository::toFile() {
    std::ofstream os("orders.json");
    if (!os.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }
    std::cout << "orders data will be written to: " << std::endl;
    cereal::JSONOutputArchive archive(os);
    archive(orders);
    std::cout << "Data has been written to orders.json" << std::endl;


}

void RepairOrderRepository::archive(const OrderPtr& order) {
    archivedOrders.push_back(order);
    remove(order);
}

std::string RepairOrderRepository::info() const {
        std::stringstream s;
        for(auto &iter :orders)
            s<<iter->getInfo();
        return s.str();

    }

void RepairOrderRepository::archivedOrdersToFile() {
    std::ofstream os("orders_archive.json");
    if (!os.is_open()) {
        return;
    }
    cereal::JSONOutputArchive archive(os);
    archive(archivedOrders);

}

void RepairOrderRepository::returnOrder(int id) {
    findById(id)->returnOrder();
}

