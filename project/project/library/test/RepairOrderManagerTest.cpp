#include <boost/test/unit_test.hpp>
#include "managers//RepairOrderManager.h"
#include "model/Client.h"


struct TestRepairOrderManagerFixture{
    int id1 = 18;
    int id2 = 13;
    int daysForRepair1 = 23;
    int daysForRepair2 = 31;
    ClientPtr client1;
    ClientPtr client2;
    CarPtr car1;
    CarPtr car2;

    TestRepairOrderManagerFixture() {
        client1 =std::make_shared<Client>("Stachu", "Jones", 2);
        client2 =std::make_shared<Client>("Robciu", "Kubicek", 8);
        car1 = std::make_shared<Car>("BMW", "X", 1872, "LU 236", client1);
        car2 = std::make_shared<Car>("Audi", "Q4", 1998, "PO 236", client2);
    }

    ~TestRepairOrderManagerFixture()= default;
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteRepairOrderManager,TestRepairOrderManagerFixture)

    BOOST_AUTO_TEST_CASE(CarManagerFunctionsTest)
    {
        std::unique_ptr<RepairOrderManager> ROM1 = std::make_unique<RepairOrderManager>();

        BOOST_CHECK_NO_THROW(ROM1->createOrder(id1, daysForRepair1, client1, car1));
        BOOST_CHECK_THROW(ROM1->createOrder(id2,daysForRepair2,client1,car1), std::logic_error);
    }
}