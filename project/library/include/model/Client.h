

#ifndef CARWORKSHOP_CLIENT_H
#define CARWORKSHOP_CLIENT_H


#include <string>
#include <deque>
#include "typedefs.h"
#include "Car.h"
#include "model/RepairOrder.h"
#include "cereal/cereal.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/memory.hpp"

class Client {
    /**
     * @brief Client class's fields.
     */
    std::string name;
    std::string surname;
    int clientID;
public:

    /**
 * Parameter constructor.
 * @param name = client's first name - string argument.
 * @param surname = client's surname - strign argument;
 * @param client ID = an unique identification number for the client -  integer argument.
 * */
    Client(const std::string &name, const std::string &surname, int clientId);

    /**
     * destructor.
     */
    virtual ~Client();

    /**
     * getter returning the client's ID number.
     * @return
     */
    int getClientId() const;

    /**
     * getter returning the surname of the client.
     * @return
     */
    const std::string &getSurname() const;

    /**
     * getter returning the name of the client.
     * @return
     */
    const std::string &getName() const;

    /**
 * getter returning the basic informations of the client.
 * @return
 */
    std::string getClientInfo() const;

    template <class Archive>
    void serialize(Archive& archive) {
        archive(name, surname,clientID);
    }

};


#endif //CARWORKSHOP_CLIENT_H
