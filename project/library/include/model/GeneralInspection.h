//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_GENERALINSPECTION_H
#define CARWORKSHOP_GENERALINSPECTION_H


#include "RepairType.h"

class GeneralInspection: public RepairType {
private:

public:
    /**
     * Parameter constructor for subclass EngineChange (inheritance from class RepairType)
     * @param order
     * @param basePrice
     */
    explicit GeneralInspection(int basePrice);

    /**
     * Destructor for subclass GeneralInspection
     */
    ~GeneralInspection() override;

    /**
     * Destructor for subclass GeneralInspection
     * @return
     */
    std::string getTypeInfo() const override;

    /**
     * Returns cost of repair. In this case this value is equal to basePrice
     * @return
     */
    int getRepairPrice() override;

};


#endif //CARWORKSHOP_GENERALINSPECTION_H
