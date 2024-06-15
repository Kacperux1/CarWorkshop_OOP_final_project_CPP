#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Car.h"
#include "model/RepairOrder.h"


struct TestCarFixture{
    std::string brand="Daewoo";
    std::string model="Matiz";
    std::string registrationNumber="4202137";
    int yearOfProduction=1999;
    ClientPtr client;
    TestCarFixture(){
        ClientPtr client =std::make_shared<Client>("Stachu", "Jones", 2);
    }
    ~TestCarFixture()= default;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteCar,TestCarFixture)

    BOOST_AUTO_TEST_CASE(CarConstructorTest)
    {
        Car car(brand, model, yearOfProduction, registrationNumber, client);
        BOOST_TEST(car.getBrand()==brand);
        BOOST_TEST(car.getModel()==model);
        BOOST_TEST(car.getProductionYear()==yearOfProduction);
        BOOST_TEST(car.getRegistrationNumber()==registrationNumber);
        BOOST_TEST(car.isRepaired()==false);
        BOOST_TEST(car.getClient()==client);
        BOOST_TEST(car.getOrder()==nullptr);
    }

    BOOST_AUTO_TEST_CASE(CarSetterTest)
    {
        CarPtr car= std::make_shared<Car>(brand, model, yearOfProduction, registrationNumber, client);
        BOOST_TEST(car->getOrder()==nullptr);
        OrderPtr O1 = std::make_shared<RepairOrder>(25, 30, client, car);
        car->setOrder(O1);
        BOOST_TEST(car->getOrder()==O1);
        O1->returnOrder();
        BOOST_TEST(car->getOrder()== nullptr);
    }
}