//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_REPAIRORDER_H
#define CARWORKSHOP_REPAIRORDER_H
#include <boost/date_time.hpp>
#include "Car.h"
#include "model/Client.h"
#include "model/RepairType.h"
#include "typedefs.h"
#include "EngineChange.h"

namespace gt=boost::gregorian;

class RepairOrder : public std::enable_shared_from_this<RepairOrder>{
    int id;
    gt::date acceptanceDate;   //zmiana, jest ptime w umlu
    gt::date returnDate;   //zmiana, nie ma w umlu
    int daysForRepair;
    ClientPtr client;
    CarWeakPtr car;
    TypePtr repairType;
public:

    /*!
 * Parameter Constructor for RepaidOrder class
 * @param id
 * @param daysForRepair
 * @param client
 * @param car
 */
    RepairOrder(int id, int daysForRepair, const ClientPtr &client, const CarWeakPtr &car);

    /*!
 * Destructor for RepairOrder class
 */
    virtual ~RepairOrder();

    /*!
 * counts discounted prise of repair. If repair lasted longer than daysForRepair we apply 2% discount for every extra day
 * @return repair cost
 */
    int getCost() const;

    /*!
 *
 * @return repair Order daysForRepair
 */
    int getDaysForRepair() const;

    /*!
 *
 * @return repair Order returnDate
 */
    const gt::date &getReturnDate() const;

    /*!
 *
 * @return repair Order acceptanceDate
 */
    const gt::date &getAcceptanceDate() const;

    /*!
 *
 * @return repair Order id
 */
    int getId() const;

    /*!
 * combined Information about RepairOrder class
 * @return id, repairType Info, acceptanceDate, cost
 */
    std::string getInfo() const;

    /**
     * This function changes repairType to engine change
     * We construct new object of repairType subclass EngineChange and set attribute repairType to it's adress
     * @param engineDisplacement
     * @param horsePower
     * @param basePrice
     */
    void changeTypeToEngineChange(int engineDisplacement, int horsePower, int basePrice);

    /**
     * This function changes repairType to gearbox repair
     * We construct new object of repairType subclass GearboxRepair and set attribute repairType to it's adress
     * @param isAutomatic
     * @param basePrice
     */
    void changeTypeToGearboxRepair(bool isAutomatic, int basePrice);

    /**
     * This function changes repairType to general inspection
     * We construct new object of repairType subclass GeneralInspection and set attribute repairType to it's adress
     * @param basePrice
     */
    void changeTypeToGeneralInspection(int basePrice);

    /**
     * This function changes repairType to LPG installation
     * We construct new object of repairType subclass LPGInstallation and set attribute repairType to it's adress
     * @param tankCapacity
     * @param basePrice
     */
    void changeTypeToLPGInstallation(int tankCapacity, int basePrice);

    /**
     * This function sets the returnDate to current time.
     * This means that service is finished and the car is ready to be picked up by client.
     */
    void returnOrder();

    /**
     * Returns value of attribute client
     * @return
     */
    const ClientPtr &getClient() const;

    /**
     * Returns value of attribute car
     * @return
     */
    const CarPtr getCar() const;

    /**
     * Returns value of attribute car
     * @return
     */
    const TypePtr &getRepairType() const;


    template <class Archive>
    void serialize(Archive& archive) {
        archive(id, gt::to_simple_string(acceptanceDate),gt::to_simple_string(returnDate),daysForRepair);
    }

};


#endif //CARWORKSHOP_REPAIRORDER_H
