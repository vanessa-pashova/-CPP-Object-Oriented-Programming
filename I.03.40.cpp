//Да се дефинира структура, която определя правоъгълник по двете му страни. Да се дефинират функции, които създават и извеждат правоъгълник, 
//намират радиуса на описаната окръжност около него, както и лицето и периметъра на правоъгълника. 

#include <iostream>
#include <cmath>

struct Rectangle 
{
    int a, b;
};

void create_Rectangle (Rectangle &obj) 
{
    std::cout << "Insert value for a > ";
    std::cin >> obj.a;
    std::cout << "Insedt value for b > ";
    std::cin >> obj.b;

    std::cout << std::endl;
}

int perimeter (Rectangle &obj) {
    return (2 * obj.a) + (2 * obj.b);
}

double area (Rectangle &obj) {
    return obj.a * obj.b;
}

double radius (Rectangle &obj) {
    return sqrt((obj.a * obj.a) + (obj.b * obj.b));
}

void print_Info (Rectangle &obj)
{
    std::cout << "Perimeter: " << perimeter(obj) << std::endl;
    std::cout << "Area: " << area(obj) << std::endl;
    std::cout << "Radius: " << radius(obj) << std::endl;

    std::cout << std::endl;
}

void draw (Rectangle &obj)
{
    for (int i = 0; i < obj.b; i++) 
    {
        for (int j = 0; j < obj.a; j++) 
        {
            if (i == 0 || i == obj.b - 1 || j == 0 || j == obj.a - 1) 
                std::cout << "-";

            else 
                std::cout << " ";
            
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;

    Rectangle first;
    create_Rectangle(first);
    print_Info(first);
    draw(first);
}


