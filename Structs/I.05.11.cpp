//Да се дефинират структурите Person, определяща лице по собстевено име и фамилия и Client, определяща клиент като лице, притежаващо банкова сметка с дадена сума. 
//Да се дефинират функции, които въвеждат и извеждат данни за лице и клиент. Да се напише програма, която:
//  а) въвежда се имената и банковите сметки на множество клиенти, зададено чрез едномерен масив
//  б) извежда имената и банковите сметки на клиентите от множеството

#include <iostream>
#include <string>
const std::size_t MAX = 51;

struct Person         
{
    std::string name;
    std::string surname;
};

struct Client
{
    Person name;
    double money;
};

Client clients[MAX];

void create_Person (Person &obj)
{
    std::cout << "Please, insert following data... " << std::endl;
    std::cout << "Name: ";
    std::cin >> obj.name;
    std::cout << "Surname: ";
    std::cin >> obj.surname;
    
    std::cout << std::endl;
}

void create_Client (Client &obj)
{
    create_Person(obj.name);
    std::cout << "Capital: ";
    std::cin >> obj.money;

    std::cout << std::endl;
}

void print_Person (Person &obj)
{
    std::cout << "Name: " << obj.name << std::endl;
    std::cout << "Surname: " << obj.surname << std::endl;
}

void print_BankDeatails (Client &obj) 
{
    print_Person(obj.name);
    std::cout << "Amount: " << obj.money << std::endl; 
    std::cout << std::endl;
}

void create_APIS (int &count, Client clients[])
{
    for (std::size_t i = 0; i < count; i++) 
        create_Client(clients[i]);
}

void printApis (int &count, Client clients[])
{
    for (std::size_t i = 0; i < count; i++)
        print_BankDeatails(clients[i]);
}

int main ()
{
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;

    int count = 0;
    std::cout << "How many new clients: ";
    std::cin >> count;

    Client first;
    create_APIS(count, clients);
    printApis(count, clients);
}

//✅