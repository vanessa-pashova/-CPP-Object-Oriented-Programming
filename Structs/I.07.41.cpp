//УКАЗАТЕЛИ КЪМ СТРУКТУРИ

//Да се дефинира структура Планета, определяща планета по име (символен низ), растояние до Слънцето, диаметър и маса (реални числа). Да се напише програма, която:
//а) създава едномерен масив от указатели към структури, задаващи планети
//б) сортира в низходящ ред по разстояние до Слънцето и диаметър планетите, зададени чрез масива
//в) извежда данните за планетите, зададени чреч масива, след сортирането има

#include <iostream>
const std::size_t MAX = 10;

struct Planet 
{
    char name[MAX];
    unsigned long distance, diameter, mass;
};

Planet *planets[MAX];

//В функцията create_Planet(Planet** obj) имаме два пойнтъра, тъй като променливата obj е указател към указател. 
//Това е необходимо, за да можем да променим стойността на указателя obj и да му зададем новата паметна адресация, 
//когато заделяме памет за нов обект от тип Planet.
void create_Planet(Planet** obj) 
{
    *obj = new Planet;
    //В реда *obj = new Planet; се извършва заделяне на памет за нов обект от тип Planet и се записва адресът на тази памет в указателя, сочен от obj. 
    //Това е необходимо, за да присвоим върнатата памет на указателя, който е подаден като параметър на функцията.
    
    std::cout << "Name > ";
    std::cin >> (*obj)->name;
    //Изразът (*obj)->name се използва, тъй като obj е указател към указател към структурата Planet. 
    //За да достъпим членовете на структурата, трябва първо да "раздираме" двойното ниво на указателите. 
    //Операторът -> се използва за достъп до членовете на структура, сочена от указател. 
    //В този случай (*obj)->name достъпва членът name на структурата Planet, на която сочи указателят *obj. 
    //Това позволява въвеждането на символния низ name чрез std::cin за новосъздадения обект от тип Planet.

    std::cout << "Distance to the Sun > ";
    std::cin >> (*obj)->distance;
    std::cout << "Diameter > ";
    std::cin >> (*obj)->diameter;
    std::cout << "Mass > ";
    std::cin >> (*obj)->mass;

    std::cout << std::endl;
}

void create_System(int count, Planet* planets[]) 
{
    for (std::size_t i = 0; i < count; i++)
        create_Planet(&planets[i]);

    std::cout << std::endl;
}

void sort(int count, Planet* planets[]) 
{
    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            if (planets[j]->distance > planets[i]->distance || (planets[j]->distance == planets[i]->distance && planets[j]->diameter > planets[i]->diameter)) 
            {
                Planet* temp = planets[i];
                planets[i] = planets[j];
                planets[j] = temp;
            }
        }
    }
}
//Функцията sort използва алгоритъма на сортиране "Selection Sort" (сортиране по избор), 
//за да сортира планетите в низходящ ред според разстоянието до Слънцето и диаметъра.

void print_InfoSystem (int &count, Planet *planets[])
{
    for (std::size_t i = 0; i < count; i++)
    {
        std::cout << "Name > " << planets[i]->name << ", Distance to the Sun > " << planets[i]->distance << ", Diameter > " << planets[i]->diameter 
            << ", and Mass > " << planets[i]->mass << '.' << std::endl;
    }
}

//const Planet* const* planets: Този параметър е константен указател към константен указател към Planet. 
//Това означава, че planets е указател, който е константен и не може да променя соченото от него. Също така, указателят, 
//към който сочи planets, е също константен и не може да бъде променян. Това гарантира, че данните на планетите не могат да бъдат променени през този указател.
void print_InfoSystem(int count, const Planet* const* planets) 
{
    for (std::size_t i = 0; i < count; i++) 
    {
        std::cout << "Name: " << planets[i]->name << ", Distance to the Sun: " << planets[i]->distance
                  << ", Diameter: " << planets[i]->diameter << ", Mass: " << planets[i]->mass << std::endl;
    }
}


int main ()
{
    std::cout << std::endl;
    std::cout << "---------------------------" << std::endl;

    int count = 0;
    do {
        std::cout << "How many planets in the system between 0 and 11 > ";
        std::cin >> count;
    } while (count < 1 || 10 < count);

    // Planet first;
    // create_Planet(first);

    create_System(count, planets);
    sort(count, planets);
    print_InfoSystem(count, planets);
}
//✅