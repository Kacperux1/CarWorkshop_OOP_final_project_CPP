
#include <boost/test/unit_test.hpp>
#include "model/RepairOrder.h"
#include "model/Car.h"
#include "model/Client.h"

struct TestRepairOrderFixture{
    int idNumber1 = 2137;
    int daysForRepair1 = 30;
    ClientPtr client;
    int idNumber2 = 111;
    int daysForRepair2 = 2;
    int idNumber3 = 345;
    int daysForRepair3 = 8;
    CarPtr car1;
    CarPtr car2;
    OrderPtr order2;
    OrderPtr order3;
    TestRepairOrderFixture(){
        client = std::make_shared<Client>("Bolek","Prus",8);
        car1 = std::make_shared<Car>("BMW", "X", 1872, "EL 0772", client);
        car2 = std::make_shared<Car>("Opel", "c", 1999, "Eo4", client);
    }
    ~TestRepairOrderFixture()= default;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepaitOrder,TestRepairOrderFixture)

    BOOST_AUTO_TEST_CASE(RepaiOrderConstructorTest)
    {
        RepairOrder repair(idNumber1, daysForRepair1, client, car1);
        BOOST_TEST(repair.getId()==idNumber1);
        BOOST_TEST(repair.getDaysForRepair()==daysForRepair1);
        BOOST_TEST(repair.getClient()==client);
        BOOST_TEST(repair.getCar()==car1);
    }
}
