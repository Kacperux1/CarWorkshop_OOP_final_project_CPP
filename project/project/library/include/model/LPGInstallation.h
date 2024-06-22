//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_LPGINSTALLATION_H
#define CARWORKSHOP_LPGINSTALLATION_H


#include "RepairType.h"

class LPGInstallation : public RepairType {
    int lpgTankCapacity;
public:
    /**
     * Parameter constructor for subclass LPGInstallation (inheritance from class RepairType)
     * @param order
     * @param lpgTankCapacity
     * @param basePrice
     */
    LPGInstallation(int lpgTankCapacity, int basePrice);

    /**
     * Destructor for subclass LPGInstallation
     */
    ~LPGInstallation() override;

    /**
     * Returns cost of repair. In this case is depending on tank capacity.
     * If it's less than 35 liters this value is equal to basePrice.
     * If it's over/equal to 35 and less than 45 liters this value is equal to basePrice*2.
     * If it's over/equal to 45 liters this value is equal to basePrice*3.
     * @return
     */
    int getRepairPrice() override;

    /**
     * Returns combined information about EngineChange subclass (tank capacity)
     * @return
     */
    std::string getTypeInfo() const override;

    /**
     * Returns value of LpgTankCapacity
     * @return
     */
    int getLpgTankCapacity() const;


};


#endif //CARWORKSHOP_LPGINSTALLATION_H
