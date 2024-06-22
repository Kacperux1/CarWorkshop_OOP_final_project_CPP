#include <boost/test/unit_test.hpp>
#include "model/GearboxRepair.h"
#include "model/Car.h"
#include "model/Client.h"
#include "model/RepairOrder.h"

struct TestGearboxRepairFixture{
    int basePrice = 500;
    bool automatic = true;
    bool nonautomatic = false;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteGearboxRepair,TestGearboxRepairFixture)

        BOOST_AUTO_TEST_CASE(AutomaticGearboxRepairConstructorTest)
        {
        GearboxRepair naprawa(automatic, basePrice);
        BOOST_TEST(naprawa.isAutomatic()==automatic);
        BOOST_TEST(naprawa.getRepairPrice()==basePrice*3);
        }

        BOOST_AUTO_TEST_CASE(NonAutomaticGearboxRepairConstructorTest)
         {
        GearboxRepair naprawa(nonautomatic, basePrice);
        BOOST_TEST(naprawa.isAutomatic()==nonautomatic);
        BOOST_TEST(naprawa.getRepairPrice()==basePrice);
         }
}
