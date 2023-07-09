//Да се дефинира структура, определяща точка от равнината с координати (х, у), където х и у приемат за стойност числа от 1 до 100. Да се напише програма, която приема
//координатите на четири точки, представляващи върхувете на четириъгълник в цикличен ред и определя дали фигурата е квадрат, правоъгълник или друго

#include <iostream>

struct Point {
    int x, y;
};

struct Rectangle {
    Point a, b, c, d;
};

void insertPoints (Rectangle &obj)
{
    std::cout << "Please, insert (x, y) for each: " << std::endl;
    do {
            std::cout << "A: " << std::endl;
            std::cin >> obj.a.x >> obj.a.y;
            std::cout << "B: " << std::endl;
            std::cin >> obj.b.x >> obj.b.y;
            std::cout << "C: " << std::endl;
            std::cin >> obj.c.x >> obj.c.y;
            std::cout << "D: " << std::endl;
            std::cin >> obj.d.x >> obj.d.y;
    } while ((0 < obj.a.x && obj.a.y < 101) && (0 < obj.b.x && obj.b.y < 101));

    std::cout << std::endl;
}

int vectorX (Point &p1, Point &p2) {
    return (p2.x - p1.x);
}

int vectorY (Point &p1, Point &p2) {
    return (p2.y - p1.y);
}

int lenght (Point &p1, Point &p2) {
    int sideX = vectorX(p1, p2);
    int sideY = vectorY(p1, p2);

    return sqrt(pow(sideX, 2) + pow(sideY, 2));
}

void create_Rectangle(Rectangle &obj)
{
    int a = lenght(obj.a, obj.b);
    int b = lenght(obj.b, obj.c);
    int c = lenght(obj.c, obj.d);
    int d = lenght(obj.d, obj.a);

    std::cout << "Sides of your rectangle: a = " << a << "; b = " << b << "; c = " << c << "; d = " << d << std::endl;
    std::cout << std::endl;
}

void proof(Rectangle &obj)
{
    if ((lenght(obj.a, obj.b) == lenght(obj.c, obj.d)) && (lenght(obj.b, obj.c) == lenght(obj.d, obj.a)) && (lenght(obj.a, obj.b) != lenght(obj.b, obj.c)))
        std::cout << "Figure Type: Rectangle" << std::endl;

    else if ((lenght(obj.a, obj.b) == lenght(obj.c, obj.d)) && (lenght(obj.b, obj.c) == lenght(obj.d, obj.a)) && (lenght(obj.a, obj.b) == lenght(obj.b, obj.c)))
        std::cout << "Figure Type: Sqare" << std::endl;

    else 
        std::cout << "N/A" << std::endl;
}

int main ()
{
    Rectangle first, second, third;

    insertPoints(first);
    create_Rectangle(first);
    proof(first);

    insertPoints(second);
    create_Rectangle(second);
    proof(second);

    insertPoints(third);
    create_Rectangle(third);
    proof(third);
}

//✅



