//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_GEARBOXREPAIR_H
#define CARWORKSHOP_GEARBOXREPAIR_H


#include "RepairType.h"

class GearboxRepair : public RepairType {
    bool automatic;
public:
    /**
     * Parameter constructor for subclass GearboxRepair (inheritance from class RepairType)
     * @param order
     * @param automatic
     * @param basePrice
     */
    GearboxRepair(bool automatic, int basePrice);

    /**
     * Destructor for subclass GearboxRepair
     */
    ~GearboxRepair() override;

    /**
     * Returns cost of repair. In this case the formula is: basePrice*3
     * @return
     */
    int getRepairPrice() override;

    /**
     * Returns combined information about EngineChange subclass (engineDisplacement, horsePower)
     * @return
     */
    std::string getTypeInfo() const override;

    /**
     * returns information whether gearbox is automatic(true) or manual(false)
     * @return
     */
    bool isAutomatic() const;

};


#endif //CARWORKSHOP_GEARBOXREPAIR_H
