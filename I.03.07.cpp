// Да се дефинира структура, която да задава триъгълник чрез трите му страни. Да се дефинират функции, които да създават и извеждат триъгълник,
//периметъра и лицето му. Да се напише програма, която създава триъгълник по зададени страни, да се изведе лицето и периметъра му.

#include <iostream>
#include <cmath>

struct Triangle {
    double a, b, c;
};

void creation (Triangle &obj)
{
    bool exists;

    do {
        std::cout << "Insert values for a, b and c :) " << std::endl;
        std::cout << "a = ";
        std::cin >> obj.a;
        std::cout << "b = ";
        std::cin >> obj.b;
        std::cout << "c = ";
        std::cin >> obj.c;

        exists = (obj.a + obj.b > obj.c) && (obj.a + obj.c > obj.b) && (obj.b + obj.c > obj.a) && (obj.a > 0) && (obj.b > 0) && (obj.c > 0);
    } while (!exists);
}

void Perimeter (Triangle &obj)
{
    double Perimeter = obj.a + obj.b + obj.c;
    std::cout << "Perimeter of the Triangle: " << Perimeter << std::endl;
}

double perimeter (Triangle &obj) {
    return (obj.a + obj.b + obj.c) / 2;
}

void Area (Triangle &obj)
{
    double p = perimeter(obj);
    double Area = p * (p - obj.a) * (p - obj.b) * (p - obj.c);
    std::cout << "Area of Triangle: " << Area << std::endl;
}

int main ()
{
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;

    Triangle firstT;
    creation(firstT);
    Perimeter(firstT);
    Area(firstT);

    Triangle secondT;
    creation(secondT);
    Perimeter(secondT);
    Area(secondT);
}

//✅