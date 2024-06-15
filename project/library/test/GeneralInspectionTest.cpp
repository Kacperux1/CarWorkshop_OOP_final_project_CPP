#include <boost/test/unit_test.hpp>
#include "model/GeneralInspection.h"
#include "model/Car.h"
#include "model/Client.h"
#include "model/RepairOrder.h"

struct TestGeneralInspectionFixture{
    int basePrice = 500;
    bool automatic = true;
    bool nonautomatic = false;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteGeneralInspection,TestGeneralInspectionFixture)

    BOOST_AUTO_TEST_CASE(GeneralInspectionConstructorTest)
    {
        GeneralInspection inspection(basePrice);
        BOOST_TEST(inspection.getRepairPrice()==basePrice);
    }
}