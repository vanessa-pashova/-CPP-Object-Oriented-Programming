#include <iostream>

struct Destination 
{
    char city[32];
    int kilometers;
};

Destination empty[50] = {' ', 0};
Destination trips[10];

void create_Destination (Destination &obj)
{
    std::cout << "Insert name of the city > ";
    std::cin >> obj.city;
    std::cout << "Insert distance to it > ";
    std::cin >> obj.kilometers;

    std::cout << std::endl;
}

void create_Trips(int &count, Destination trips[])
{
    for (std::size_t i = 0; i < count; i++)
        create_Destination(trips[i]);

    std::cout << std::endl;
}

void print_Trips (int &count, Destination trips[])
{
    for (std::size_t i = 0; i < count; i++)
        std::cout << trips[i].city << "  ---  " << trips[i].kilometers << std::endl;

    std::cout << std::endl;
}

int main ()
{
    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;

    int count = 0;
    do
    {  
        std::cout << "Please, insert how many trips you have: ";
        std::cin >> count;
    } while (count < 1 || 10 < count);

    create_Trips(count, trips);
    print_Trips(count, trips);
}

//✅