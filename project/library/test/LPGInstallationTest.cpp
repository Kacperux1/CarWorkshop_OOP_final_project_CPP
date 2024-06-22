#include <boost/test/unit_test.hpp>
#include "model/LPGInstallation.h"
#include "model/Car.h"
#include "model/Client.h"
#include "model/RepairOrder.h"

struct TestLPGInstallationFixture{
    int basePrice = 500;
    int tankCapacity1 = 30;
    int tankCapacity2 = 40;
    int tankCapacity3 = 50;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteLPGInstallation,TestLPGInstallationFixture)

    BOOST_AUTO_TEST_CASE(LPGInstallationConstructorTest)
    {
        LPGInstallation lpg1(tankCapacity1, basePrice);
        BOOST_TEST(lpg1.getLpgTankCapacity()=tankCapacity1);
        BOOST_TEST(lpg1.getRepairPrice()==basePrice);
    }

    BOOST_AUTO_TEST_CASE(LPGInstallationBasePriceTest)
    {
        LPGInstallation lpg1(tankCapacity1, basePrice);
        BOOST_TEST(lpg1.getRepairPrice()==basePrice);
        LPGInstallation lpg2(tankCapacity2, basePrice);
        BOOST_TEST(lpg2.getRepairPrice()==basePrice*2);
        LPGInstallation lpg3(tankCapacity3, basePrice);
        BOOST_TEST(lpg3.getRepairPrice()==basePrice*3);
    }
}