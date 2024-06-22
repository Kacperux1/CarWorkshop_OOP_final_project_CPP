#include <boost/test/unit_test.hpp>
#include <model/Client.h>
#include "model/Car.h"

struct TestSuiteClientFixture {
    std::string name="Stanislaw";
    std::string surname="Wokulski";
    int id=1;
    CarPtr car;
    TestSuiteClientFixture() {

    }

    ~TestSuiteClientFixture() {
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)
//! Test case testing if the constructor works correctly.
    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
    Client client(name,surname,id);
    BOOST_TEST(client.getName()==name);
    BOOST_TEST(client.getSurname()==surname);
    BOOST_TEST(client.getClientId()==id);
    }

    BOOST_AUTO_TEST_CASE(ClientAddCarTest) {
    }
}