//
// Created by ANDRZEJ on 21.05.2024.
//

#ifndef CARWORKSHOP_REPAIRTYPE_H
#define CARWORKSHOP_REPAIRTYPE_H

//dodac pole baseprice??
#include "typedefs.h"

class RepairType {
private:
    int basePrice;
public:
    /**
     * Parameter constructor for class RepairType (Virtual class)
     * @param order
     * @param basePrice
     */
    explicit RepairType(int basePrice);

    /**
     * Destructor for class RepairType
     */
    virtual ~RepairType()=0;

    virtual int getRepairPrice()=0;

    virtual std::string getTypeInfo() const=0;

    /**
     * Returns value of attribute basePrice
     * @return
     */
    int getBasePrice() const;
};


#endif //CARWORKSHOP_REPAIRTYPE_H
