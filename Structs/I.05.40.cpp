//Да се дефинира структура планета, опеределяща планета по име (символен низ), разстояние от слънцето, диаметър и маса (реални числа). Да се дефинира ф-ция, която:
//а) въвежда данните
//б) извежда данните
//в) връща като резултат броя на секунди, които са необходими на светлината да достигне от слънцето до планетата (да се приеме, че светлината има скорост 299 792 км/ч
// и че разстоянието от планетата до слънцето е измерено в километри).

//Да се напише програма, която:
//а) да въвежда множество от планети
//б) извежда данните за планетите от множеството
//в) намира планетата с най-голям диаметър
//г) намира планетата с най-малка маса
//д) намира планетата, до която светлината достига последна (първа)

#include <iostream>
const std::size_t MAX = 10;
const std::size_t SPEED = 299792;

struct Planet 
{
    char name[MAX];
    unsigned long long distance, diameter, mass;
};

void create_Planet (Planet &obj)
{
    std::cout << "Name of the planet: ";
    std::cin >> obj.name;
    std::cout << "Distance between the Sun and " << obj.name << ": ";
    std::cin >> obj.distance;
    std::cout << "Diameter of the planet: ";
    std::cin >> obj.diameter;
    std::cout << "Mass of the planet: ";
    std::cin >> obj.mass;

    std::cout << std::endl;
}

double timeToSun (Planet &obj) {
    return (obj.distance / SPEED) / 3600;
}

void print_InfoForOne (Planet &obj) 
{
    std::cout << "Name > " << obj.name << std::endl;
    std::cout << "Distance to the Sun > " << obj.distance << std::endl;
    std::cout << "Diameter > " << obj.diameter << std::endl;
    std::cout << "Mass > " << obj.mass << std::endl;
    std::cout << "Time for Reaching the Sun in seconds > " << timeToSun(obj) << std::endl;

    std::cout << std::endl;
}

Planet planets[MAX];

void create_System (const std::size_t &MAX, Planet planets[])
{
    for (std::size_t i = 0; i < MAX; i++)
        create_Planet(planets[i]);

    std::cout << std::endl;
}

void print_InfoSystem (const std::size_t &MAX, Planet planets[])
{
    for (std::size_t i = 0; i < MAX; i++)
        print_InfoForOne(planets[i]);

    std::cout << std::endl;
}

void biggestDiameter (const std::size_t &MAX, Planet planets[])
{
    int biggestDia = planets[0].diameter;
    int biggestDis, biggestMass; 
    char biggestName[MAX];

    for (std::size_t i = 1; i < MAX; i++)
    {
        if (biggestDia < planets[i].diameter)
            biggestDia = planets[i].diameter;

        biggestDis = planets[i].distance;
        biggestMass = planets[i].mass;
        strcpy(biggestName, planets[i].name);
    }

    std::cout << "The planet " << biggestName << " is with the biggest diameter in the System: " << biggestDia << ", Mass: " 
    << biggestMass << ", and Distance to the Sun: " << biggestDis << std::endl;

    std::cout << std::endl;
}

void smallesMass (const std::size_t &MAX, Planet planets[])
{
    int smallestMass = planets[0].mass;
    int smallestDis, smallestDia; 
    char smallestName[MAX];

    for (std::size_t i = 1; i < MAX; i++)
    {
        if (smallestMass < planets[i].mass)
            smallestMass = planets[i].diameter;

        smallestDis = planets[i].distance;
        smallestDia = planets[i].diameter;
        strcpy(smallestName, planets[i].name);
    }

    std::cout << "The planet " << smallestName << " is with the smallest mass in the System: " << smallestMass << ", Diameter: " 
    << smallestDia << ", and Distance to the Sun: " << smallestDis << std::endl;

    std::cout << std::endl;
}

void slowest (const std::size_t &MAX, Planet planets[])
{
    int slower = timeToSun(planets[0]);
    char nameSlower[MAX];

    for (std::size_t i = 1; i < MAX; i++)
    {
        if (slower > timeToSun(planets[i]))
            slower = timeToSun(planets[i]);
        
        strcpy(nameSlower, planets[i].name);
    }

    std::cout << "The slowest is: " << nameSlower << ", with speed: " << slower << std::endl;
    std::cout << std::endl;
}

int main () 
{
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;

    Planet first;
    create_Planet(first);
    print_InfoForOne(first);

    create_System(MAX, planets);
    print_InfoSystem(MAX, planets);
    biggestDiameter(MAX, planets);
    smallesMass(MAX, planets);
    slowest(MAX, planets);
}

//i guess it works
