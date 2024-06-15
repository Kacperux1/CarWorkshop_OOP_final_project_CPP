#include <iostream>
#include <filesystem>
#include "model/Client.h"
#include "cereal/archives/json.hpp"
#include "managers/CarManager.h"
#include "managers/ClientManager.h"
#include "managers/RepairOrderManager.h"
#include <sstream>

using namespace std;
std::unique_ptr<CarManager> carMgr;
std::unique_ptr<ClientManager> clientMgr;
std::unique_ptr<RepairOrderManager> orderMgr;

typeOfRepair changeTypeMenu(){
    typeOfRepair type;
    char repair;
    bool flag = true;
    while(flag) {
        std::cout << "Possible options:" << std::endl;
        std::cout << "enter '1' if you want to change engine" << std::endl;
        std::cout << "enter '2' if you want general inspection the car" << std::endl;
        std::cout << "enter '3' if you want to repair gearbox" << std::endl;
        std::cout << "enter '4' if you want to install LPG in the car" << std::endl;
        std::cout << "Chose what repair you want to be made: ";
        std::cin >> repair;
        cout<<endl;
        switch (repair) {
            case '1':
                type = engineChange;
                flag = false;
                break;
            case '2':
                type = generalInspection;
                flag = false;
                break;
            case '3':
                type = gearboxRepair;
                flag = false;
                break;
            case '4':
                type = lPGInstallation;
                flag = false;
                break;
            default:
                std::cout << "Unknown option. Please try again."<<endl;
                break;
        }
    }
    return type;
}

void createNewClient(){
    int clientId;
    cout << "You are creating new client."<<endl;
    int flag=true;
    while(flag)
    {
        cout<<"Enter identification number for Client: ";
        cin >> clientId;
        cout<<endl;
        try{
            clientMgr->findClient(clientId);
        }
        catch(logic_error &e)
        {
            flag = false;
        }
    }

    string name;
    cout<<"Enter client name: ";
    cin>>name;
    cout<<endl;

    string surname;
    cout<<"Enter client name: ";
    cin>>surname;
    cout<<endl;
    clientMgr->addClient(clientId, name, surname);
}

void createNewCar(){
    cout << "You are creating new car."<<endl;
    string registrationNumber;
    cout<<endl;
    int flag=true;
    while(flag)
    {
        cout<<"Enter registration number for Car: ";
        cin >> registrationNumber;
        cout<<endl;
        try{
            carMgr->findCar(registrationNumber);
        }
        catch(logic_error &e)
        {
            flag = false;
        }
    }

    int id;
    cout << "Enter identification number of client who is the owner of the car: ";
    cin >> id;
    cout<<endl;

    clientMgr->findClient(id);

    string brand;
    cout<<"Enter cars brand: ";
    cin >> brand;
    cout<<endl;

    string model;
    cout<<"Enter cars model: ";
    cin >> model;
    cout<<endl;

    int productionYear;
    cout<<"Enter car production year";
    productionYear=enterData();

    carMgr->addCar(registrationNumber, brand, model, productionYear, (clientMgr->findClient(id)));
}

void createNewOrder(){
    cout << "You are creating new repair order."<<endl;
    int id;
    int flag=true;
    while(flag)
    {
        cout<<"Enter identification number for order: ";
        cin >> id;
        cout<<endl;
        try{
            orderMgr->findOrder(id);
        }
        catch(logic_error &e)
        {
            flag = false;
        }
    }

    string carId;
    cout << "Enter registration number of car you want to repair: ";
    cin >> carId;
    cout<<endl;

    carMgr->findCar(carId);

    std::cout << "NOTE: Type of repair is currently empty. You need to change it now." << std::endl;

    typeOfRepair type;
    type = changeTypeMenu();

    int daysForRepair;
    cout<<"Enter how many days will it take to repair this car: ";
    daysForRepair=enterData();

    orderMgr->createOrder(id, daysForRepair, (carMgr->findCar(carId))->getClient(), carMgr->findCar(carId), type);
}

void changeRepairType(){
    cout << "You are changing type of repair."<<endl;
    int id;
    cout<<"Enter id of order you want to change type of: ";
    cin >> id;
    cout<<endl;

    orderMgr->findOrder(id);

    typeOfRepair type;
    type = changeTypeMenu();

    orderMgr->changeRepairType(orderMgr->findOrder(id), type);
}

void archivization(){
    cout<<"You are archiving order,"<<endl;
    int id;
    cout<<"Enter id of order you want to archive ";
    cin >> id;
    cout<<endl;
    orderMgr->archive(orderMgr->findOrder(id));
}

void returnOrder(){
    cout<<"You are returning car to client."<<endl;
    int id;
    cout<<"Enter id of order you want to return: ";
    cin >> id;
    cout<<endl;

    orderMgr->returnOrder(id);
}

string findAllClientInfo() {
    cout << "You are looking for all information about client.";
    int id;
    cout << "Enter clients id: ";
    cin >> id;
    cout << endl;

    stringstream s;
    s << "Client:" << endl;
    s << clientMgr->findClient(id)->getClientInfo() << endl;
    s<<"Is owner of cars:"<<endl;
    if((carMgr->findAllClientsCar(clientMgr->findClient(id))).empty())
        s<<"Client currently has no cars."<<endl;
    else {
        s << carMgr->findAllClientsCar(clientMgr->findClient(id)) << endl;
        s << "And his repair orders are:" << endl;
        if((orderMgr->findAllClientsOrders(clientMgr->findClient(id))).empty())
            s<<"Client currently has no repair orders."<<endl;
        else
            s << orderMgr->findAllClientsOrders(clientMgr->findClient(id)) << endl;
    }

    return s.str();
}

string findAllCarInfo(){
    cout<<"You are looking for all information about car.";
    string id;
    cout<<"Enter registration number of the car: ";
    cin >> id;
    cout<<endl;
    while(carMgr->findCar(id)==nullptr)
    {
        cout<<"there is no car with this registration number. Please try again: ";
        cin >> id;
        cout<<endl;
    }

    stringstream s;
    s<<"The car:"<<endl;
    s<<(carMgr->findCar(id))->getInfo()<<endl;
    s<<"Is owned by:"<<endl;
    s<<(carMgr->findCarOwner(id)->getClientInfo())<<endl;
    s<<"And its repair order is:"<<endl;
    if(carMgr->findCarOrder(id)==nullptr)
        s<<"Currently no repair orders."<<endl;
    else
        s<<carMgr->findCarOrder(id)->getInfo()<<endl;

    return s.str();
}

string findAllOrderInfo(){
    cout<<"You are looking for all information about repair order.";
    int id;
    cout<<"Enter id of the order: ";
    cin >> id;
    cout<<endl;
    while(orderMgr->findOrder(id)==nullptr)
    {
        cout<<"there is no repair order with this id. Please try again: ";
        cin >> id;
        cout<<endl;
    }

    stringstream s;
    s<<"This order:"<<endl;
    s<<orderMgr->findOrder(id)->getInfo()<<endl;
    s<<"Is for car:"<<endl;
    s<<orderMgr->findCar(id)->getInfo()<<endl;
    s<<"which is owned by:"<<endl;
    s<<orderMgr->findClient(id)->getClientInfo()<<endl;

    return s.str();
}

int main()
{
    cout<<"Welcome to car workshop! Choose what you want to do:"<<endl;
    carMgr=std::make_unique<CarManager>();
    clientMgr=std::make_unique<ClientManager>();
    orderMgr=std::make_unique<RepairOrderManager>();
    int choice=0;
    int choice2;
    bool flag=true;
    while(flag)
    {
        cout<<"Choose option from below, enter the number of the option:"<<endl;
        cout<<"1. Add client to application"<<endl<<"2. Add car to app"<<endl<<"3. Create repair order"
        <<endl<<"4. Change the repair type of certain order"<<endl<<"5. Get info about all cars, orders, or clients"<<endl<<"6. Save info about cars, order or clients to file"
        <<endl<<"7. Find certain car, client or order by id/plate number"<<endl<<"8. archive the repair order"<<endl<<"9. "<<endl<<
        "10. Return an order to the client"<<endl<<"11. Exit program.";
        cin>>choice;
        switch(choice) {
            case 1:
                createNewClient();
                break;
            case 2:
                try {
                    createNewCar();
                }
                catch (logic_error &e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                try {
                    createNewOrder();
                }
                catch (logic_error &e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                try {
                    changeRepairType();
                }
                catch (logic_error &e) {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                cout << "You want info about clients, cars or orders? Enter the number subsequently from 1 to 3:";
                cin >> choice2;
                switch (choice2) {
                    case 1:
                        if (clientMgr->count() == 0)
                            cout << "There are currently no clients." << endl;
                        clientMgr->getAllClientInfo();
                        break;
                    case 2:
                        if (carMgr->count() == 0)
                            cout << "There are currently no cars." << endl;
                        carMgr->getAllCarInfo();
                    case 3:
                        if (orderMgr->count() == 0)
                            cout << "There are currently no orders." << endl;
                        orderMgr->getAllOrderInfo();
                    default:
                        cout << "Wrong number." << endl;
                }
                break;
            case 6:
                cout
                        << "You want to save info to file about clients, cars of clients? Enter the number subsequently from 1 to 3:";
                cin >> choice2;
                switch (choice2) {
                    case 1:
                        clientMgr->writeToFile();
                        break;
                    case 2:
                        carMgr->writeToFile();
                    case 3:
                        orderMgr->writeToFile();
                    default:
                        cout << "Wrong number." << endl;
                }
                break;
            case 7:
                cout
                        << "You want information about client, car or repair order? Enter the number subsequently from 1 to 3:";
                cin >> choice2;
                switch (choice2) {
                    case 1:
                        try {
                            findAllClientInfo();
                        }
                        catch (logic_error &e) {
                            cout << e.what() << endl;
                        }
                        break;
                    case 2:
                        try {
                            findAllCarInfo();
                        }
                        catch (logic_error &e) {
                            cout << e.what() << endl;
                        }
                        break;
                    case 3:
                        try {
                            findAllOrderInfo();
                        }
                        catch (logic_error &e) {
                            cout << e.what() << endl;
                        }
                        break;
                    default:
                        cout << "Wrong number." << endl;
                        break;
                }
                break;
            case 8:
                try{
                    archivization();
                }
                catch (logic_error &e) {
                    cout << e.what() << endl;
                    }
                break;
            case 9:
                break;
            case 10:
                try {
                    returnOrder();
                }
                catch (logic_error &e) {
                    cout << e.what() << endl;
                }
                break;
            case 11:
                flag=false;
                cout<<"Exiting the program"<<endl;
                break;
            default:
                cout<<"Unknown option. Please try again"<<endl;
        }
    }

    return 0;
}


