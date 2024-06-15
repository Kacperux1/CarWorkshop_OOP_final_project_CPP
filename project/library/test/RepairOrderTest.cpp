
#include <boost/test/unit_test.hpp>
#include "model/RepairOrder.h"
#include "model/Car.h"
#include "model/Client.h"

struct TestRepairOrderFixture{
    int idNumber = 2137;
    int daysForRepair = 30;
    ClientPtr client;
    CarPtr car;
    TestRepairOrderFixture(){
        client = std::make_shared<Client>("Bolek","Prus",8);
        car = std::make_shared<Car>("BMW", "X", 1872, "EL 0772", client);
    }
    ~TestRepairOrderFixture()= default;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepaitOrder,TestRepairOrderFixture)

    BOOST_AUTO_TEST_CASE(RepaiOrderConstructorTest)
    {
        RepairOrder repair(idNumber, daysForRepair, client, car);
        BOOST_TEST(repair.getId()==idNumber);
        BOOST_TEST(repair.getDaysForRepair()==daysForRepair);
        BOOST_TEST(repair.getClient()==client);
        BOOST_TEST(repair.getCar()==car);
    }
}
