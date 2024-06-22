#include <boost/test/unit_test.hpp>
#include "repositories/CarRepository.h"
#include "model/Car.h"
#include "model/Client.h"

struct TestCarRepositoryFixture{
    std::string reg1 = "EL 0772";
    std::string reg2 = "WWA 537";
    ClientPtr client;
    CarPtr car1;
    CarPtr car2;
    TestCarRepositoryFixture() {
        client =std::make_shared<Client>("Stachu", "Jones", 2);
        car1 = std::make_shared<Car>("BMW", "X", 1872, reg1, client);
        car2 = std::make_shared<Car>("Audi", "Q4", 1998, reg2, client);
    }

    ~TestCarRepositoryFixture()= default;
};



BOOST_FIXTURE_TEST_SUITE(TestSuiteCarRepository,TestCarRepositoryFixture)

    BOOST_AUTO_TEST_CASE(CarRepositoryFunctionsTest)
    {
        std::unique_ptr<CarRepository> CR1 = std::make_unique<CarRepository>();

        CR1->add(car1);
        BOOST_CHECK_NO_THROW(CR1->findByNumber(reg1));
        BOOST_TEST(CR1->findByNumber(reg1)==car1);
        BOOST_TEST(CR1->getSize()==1);

        CR1->add(car2);
        BOOST_CHECK_NO_THROW(CR1->findByNumber(reg1));
        BOOST_CHECK_NO_THROW(CR1->findByNumber(reg2));
        BOOST_TEST(CR1->findByNumber(reg1)==car1);
        BOOST_TEST(CR1->findByNumber(reg2)==car2);
        BOOST_TEST(CR1->getSize()==2);

        CR1->remove(car1);
        BOOST_CHECK_THROW(CR1->findByNumber(reg1), std::logic_error);
        BOOST_CHECK_NO_THROW(CR1->findByNumber(reg2));
        BOOST_TEST(CR1->getSize()==1);
        BOOST_TEST(CR1->findByNumber(reg2)==car2);

        CR1->remove(CR1->findByNumber(reg2));
        BOOST_CHECK_THROW(CR1->findByNumber(reg1), std::logic_error);
        BOOST_CHECK_THROW(CR1->findByNumber(reg2), std::logic_error);
        BOOST_TEST(CR1->getSize()==0);
    }
}