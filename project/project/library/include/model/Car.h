//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_CAR_H
#define CARWORKSHOP_CAR_H


#include <string>
#include "typedefs.h"
#include "cereal/cereal.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/memory.hpp"
#include "model/Client.h"
#include "model/RepairOrder.h"

class Car {
     std::string brand;
     std::string model;
     int productionYear;
     std::string registrationNumber;
     ClientPtr client;
     OrderPtr order;
public:

    /*!
 * Parameter constructor for Car class
 * @param brand
 * @param model
 * @param productionYear
 * @param registrationNumber
 * @param client
 */
    Car(const std::string &brand, const std::string &model, int productionYear, const std::string &registrationNumber,
        const ClientPtr &client);

    /*!
 *  Destructor for Car class
 */
    virtual ~Car();

    /*!
 *
 * @return Car production year
 */
    int getProductionYear() const;

    /*!
 *
 * @return Car model
 */
    const std::string &getModel() const;

    /*!
 *
 * @return Car brand
 */
    const std::string &getBrand() const;

    /*!
 * return true if car is already rented and false if it's not
 * @return boolean
 */
    bool isRepaired() const;

    /*!
 *
 * @return Car registration number
 */
    const std::string &getRegistrationNumber() const;

    /*!
 *
 * @return Pointer to CLinet
 */
    const ClientPtr &getClient() const; //nie ma w umlu

    /*!
 *
 * @return Pointer to Repair Order
 */
    const OrderPtr &getOrder() const; //nie ma w umlu

/*!
 * Returns combined information about object
 * @return brand, model, production year, registration number
 */
    std::string getInfo() const;

    template <class Archive>
    void serialize(Archive& archive) {
        archive(brand, model, productionYear, registrationNumber);
    }

    void setOrder(const OrderPtr &order);
};


#endif //CARWORKSHOP_CAR_H
