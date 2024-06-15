#include <boost/test/unit_test.hpp>
#include "repositories/RepairOrderRepository.h"
#include "model/Car.h"
#include "model/Client.h"
#include "model/RepairOrder.h"

struct TestRepairOrderRepositoryFixture{
    int id1 = 18;
    int id2 = 35;
    ClientPtr client1;
    CarPtr car1;
    OrderPtr order1;
    ClientPtr client2;
    CarPtr car2;
    OrderPtr order2;
     TestRepairOrderRepositoryFixture() {
         client1 =std::make_shared<Client>("Stachu", "Jones", 2);
         car1 = std::make_shared<Car>("BMW", "X", 1872, "EL 2137", client1);
         order1 = std::make_shared<RepairOrder>(id1, 15, client1, car1);

         client2 = std::make_shared<Client>("Robert", "Kubica", 18);
         car2 = std::make_shared<Car>("Audi", "Q4", 1998, "WWA 888", client2);
         order2 = std::make_shared<RepairOrder>(id2, 25, client2, car2);
     }

     ~TestRepairOrderRepositoryFixture()=default;

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepairOrderRepository,TestRepairOrderRepositoryFixture)

    BOOST_AUTO_TEST_CASE(RepairOrderRepositoryFunctionsTest)
    {
        std::unique_ptr<RepairOrderRepository> ROR1 = std::make_unique<RepairOrderRepository>();

        ROR1->add(order1);
        BOOST_CHECK_NO_THROW(ROR1->findById(id1));
        BOOST_TEST(ROR1->findById(id1)==order1);
        BOOST_TEST(ROR1->getSize()=1);

        ROR1->add(order2);
        BOOST_CHECK_NO_THROW(ROR1->findById(id1));
        BOOST_CHECK_NO_THROW(ROR1->findById(id2));
        BOOST_TEST(ROR1->findById(id1)==order1);
        BOOST_TEST(ROR1->findById(id2)==order2);
        BOOST_TEST(ROR1->getSize()=2);


        ROR1->remove(order1);
        BOOST_CHECK_THROW(ROR1->findById(id1), std::logic_error);
        BOOST_CHECK_NO_THROW(ROR1->findById(id2));
        BOOST_TEST(ROR1->findById(id2)==order2);
        BOOST_TEST(ROR1->getSize()=1);

        ROR1->remove(ROR1->findById(id2));
        BOOST_CHECK_THROW(ROR1->findById(id1), std::logic_error);
        BOOST_CHECK_THROW(ROR1->findById(id2), std::logic_error);
        BOOST_TEST(ROR1->getSize()==0);
    }
}