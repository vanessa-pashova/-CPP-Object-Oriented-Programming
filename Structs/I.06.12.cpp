//Да се дефинира структура Triangle, която определя триъгълник, разположен в равнина чрез двумерните декартови координати на върховете му.
//Да се дефинират функции, които създават и извеждат триъгълник, намират периметъра и лицето му. Да се напише програма, която демонстрира дефинираните функции.

#include <iostream>
#include <cmath>

struct Point 
{
    int x, y;
};

struct Triangle 
{
    Point point1, point2, point3;
};

void create_Triangle (Triangle &obj)
{
    std::cout << "Please, insert values for all six points: " << std::endl;
    std::cin >> obj.point1.x >> obj.point1.y;
    std::cin >> obj.point2.x >> obj.point2.y;
    std::cin >> obj.point3.x >> obj.point3.y;
}

void generete_Operations (Triangle &obj)
{
    int a = sqrt(pow((obj.point2.x - obj.point1.x), 2) + pow((obj.point2.y - obj.point1.y), 2));
    std::cout << "a = " << a << std::endl;
    int b = sqrt(pow((obj.point3.x - obj.point2.x), 2) + pow((obj.point2.y - obj.point2.y), 2));
    std::cout << "b = " << b << std::endl;
    int c = sqrt(pow((obj.point3.x - obj.point1.x), 2) + pow((obj.point3.y - obj.point1.y), 2));
    std::cout << "c = " << c << std::endl;

    int Perimeter = a + b + c;
    std::cout << "Perimeter = " << Perimeter << std::endl;

    int p = Perimeter / 2;
    int Area = sqrt(p * (p - a) * (p - b) * (p - c));
    std::cout << "Area = " << Area << std::endl;
}


int main ()
{
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;

    Triangle first;
    create_Triangle(first);
    generete_Operations(first);
}

