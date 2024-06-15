#include <boost/test/unit_test.hpp>
#include "repositories/ClientRepository.h"
#include "model/Client.h"

struct TestClientRepositoryFixture{
    int id1 = 2;
    int id2 = 5;
    ClientPtr client1;
    ClientPtr client2;
    TestClientRepositoryFixture() {
        client1 = std::make_shared<Client>("Stachu", "Jones", id1);
        client2 = std::make_shared<Client>("Robert", "Kubica", id2);
    }
    ~TestClientRepositoryFixture()=default;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientRepository,TestClientRepositoryFixture)

    BOOST_AUTO_TEST_CASE(ClientRepositoryFunctionsTest)
    {
        std::unique_ptr<ClientRepository> CRep1 = std::make_unique<ClientRepository>();

        CRep1->add(client1);
        BOOST_CHECK_NO_THROW(CRep1->findById(id1));
        BOOST_TEST(CRep1->findById(id1)==client1);
        BOOST_TEST(CRep1->getSize()==1);

        CRep1->add(client2);
        BOOST_CHECK_NO_THROW(CRep1->findById(id1));
        BOOST_CHECK_NO_THROW(CRep1->findById(id2));
        BOOST_TEST(CRep1->findById(id1)==client1);
        BOOST_TEST(CRep1->findById(id2)==client2);
        BOOST_TEST(CRep1->getSize()==2);

        CRep1->remove(client1);
        BOOST_CHECK_THROW(CRep1->findById(id1), std::logic_error);
        BOOST_TEST(CRep1->findById(id2)==client2);
        BOOST_TEST(CRep1->getSize()==1);

        CRep1->remove(CRep1->findById(id2));
        BOOST_CHECK_THROW(CRep1->findById(id1), std::logic_error);
        BOOST_CHECK_THROW(CRep1->findById(id2), std::logic_error);
        BOOST_TEST(CRep1->getSize()==0);
    }
}