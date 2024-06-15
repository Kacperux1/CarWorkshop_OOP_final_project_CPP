#include <boost/test/unit_test.hpp>
#include "model/EngineChange.h"
#include "model/Car.h"
#include "model/Client.h"
#include "model/RepairOrder.h"

struct TestEngineChangeFixture{
    int basePrice = 500;
    int EngDisp = 125;
    int HorsePow = 200;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteEngineChange,TestEngineChangeFixture)

    BOOST_AUTO_TEST_CASE(EngineChangeConstructorTest)
    {
        EngineChange engine(EngDisp, HorsePow, basePrice);
        BOOST_TEST(engine.getEngineDisplacement()==EngDisp);
        BOOST_TEST(engine.getHorsePower()==HorsePow);
        BOOST_TEST(engine.getRepairPrice()==basePrice+5*EngDisp+5*HorsePow);
    }
}