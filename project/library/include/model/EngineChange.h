//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_ENGINECHANGE_H
#define CARWORKSHOP_ENGINECHANGE_H


#include "RepairType.h"

class EngineChange : public RepairType {
    int engineDisplacement;
    int horsePower;
public:

    /**
     * Parameter constructor for subclass EngineChange (inheritance from class RepairType)
     * @param order
     * @param engineDisplacement
     * @param horsePower
     * @param basePrice
     */
    EngineChange(int engineDisplacement, int horsePower, int basePrice);

    /**
     * Destructor for subclass EngineChange
     */
    ~EngineChange() override;

    /**
     * Returns cost of repair. In this case the formula is: basePrice+5*engineDisplacement+5*horsePower
     * @return
     */
    int getRepairPrice() override;

    /**
     * Returns combined information about EngineChange subclass (gearbox type (automatic/manual))
     * @return
     */
    std::string getTypeInfo() const override;

    /**
     * Returns value of engineDisplacement
     * @return
     */
    int getEngineDisplacement() const;

    /**
     * Returns value of horsePower
     * @return
     */
    int getHorsePower() const;
};


#endif //CARWORKSHOP_ENGINECHANGE_H
