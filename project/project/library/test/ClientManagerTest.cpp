#include <boost/test/unit_test.hpp>
#include "managers//ClientManager.h"

struct TestClientManagerFixture{
    std::string name1 = "janek";
    std::string name2 = "Ola";
    std::string surname1 = "szpak";
    std::string surname2 = "but";
    int id1 = 1872;
    int id2 = 1998;
    TestClientManagerFixture() = default;

    ~TestClientManagerFixture()= default;
};



BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager,TestClientManagerFixture)

    BOOST_AUTO_TEST_CASE(CarManagerFunctionsTest)
    {
        std::unique_ptr<ClientManager> ClM1 = std::make_unique<ClientManager>();

        ClM1->addClient(id1, name1, surname1);
        BOOST_TEST(ClM1->count()==1);
        ClM1->addClient(id2, name2, surname2);
        BOOST_TEST(ClM1->count()==2);
    }
}