#include <boost/test/unit_test.hpp>
#include "managers//CarManager.h"
#include "model/Car.h"
#include "model//Client.h"

struct TestCarManagerFixture{
    std::string brand1 = "BMW";
    std::string brand2 = "Audi";
    std::string model1 = "X";
    std::string model2 = "Q4";
    int productionYear1 = 1872;
    int productionYear2 = 1998;
    std::string reg1 = "EL 0772";
    std::string reg2 = "WWA 537";
    std::string reg3 = "nic";
    ClientPtr client1;
    ClientPtr client2;

    TestCarManagerFixture() {
        client1 =std::make_shared<Client>("Stachu", "Jones", 2);
        client2 =std::make_shared<Client>("Robciu", "Kubicek", 8);
    }

    ~TestCarManagerFixture()= default;
};



BOOST_FIXTURE_TEST_SUITE(TestSuiteCarManager,TestCarManagerFixture)

    BOOST_AUTO_TEST_CASE(CarManagerFunctionsTest)
    {
        std::unique_ptr<CarManager> CM1 = std::make_unique<CarManager>();

        CM1->addCar(reg1, brand1, model1, productionYear1, client1);
        BOOST_TEST(CM1->count()==1);
        BOOST_CHECK_NO_THROW(CM1->findCarOwner(reg1));
        BOOST_TEST(CM1->findCarOwner(reg1)==client1);

        CM1->addCar(reg2, brand2, model2, productionYear2, client2);
        BOOST_CHECK_NO_THROW(CM1->findCarOwner(reg1));
        BOOST_CHECK_NO_THROW(CM1->findCarOwner(reg2));
        BOOST_TEST(CM1->findCarOwner(reg1)==client1);
        BOOST_TEST(CM1->findCarOwner(reg2)==client2);
        BOOST_TEST(CM1->count()==2);
        BOOST_CHECK_THROW(CM1->findCarOwner(reg3), std::logic_error);
    }
}