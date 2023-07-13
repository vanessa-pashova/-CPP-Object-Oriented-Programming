//Да се дефинират класове Cylinder и SqarePyramid, определящи геометричните фигури. Всеки от класовете да притежава конструктор и ф-ции за достъп до
//член-данните му. Да се дефинира приятелска ф-ция IsHigher на двата класа, която да определя дали цилиндър е по-висок от пирамида. 

#include <iostream>

class SqarePyramid;

class Cylinder
{
    private:
        double r, h;

    public:
        double getR () const;
        double getH () const;
        Cylinder (double r, double h);
        friend void IsHigher (const Cylinder &obj, const SqarePyramid &obj2);
};

double Cylinder::getR () const {
    return this->r;
}

double Cylinder::getH () const {
    return this->h;
}

Cylinder::Cylinder (double r, double h) : r(r), h(h) {}

class SqarePyramid
{
    private:    
        double a, i, h;

    public:
        double getA () const;
        double getI () const;
        double getH () const;
        SqarePyramid (double a, double i, double h);
        friend void IsHigher (const Cylinder &obj, const SqarePyramid &obj2); 
};

double SqarePyramid::getA () const {
    return this->a;
}

double SqarePyramid::getI () const {
    return this->i;
}

double SqarePyramid::getH () const {
    return this->h;
}

SqarePyramid::SqarePyramid (double a, double i, double h) : a(a), i(i), h(h) {}

void IsHigher (const Cylinder &obj, const SqarePyramid &obj2)
{
    if (obj.getH() > obj2.getH())
        std::cout << "[ Cylinder is higher than SP ]\n";

    else 
        std::cout << "[ SP is higher than the Culinder ]\n";

    std::cout << '\n';
}

int main ()
{
    std::cout << '\n';
    std::cout << "--------------------------------\n";

    SqarePyramid firstSP(3, 4, 5);
    Cylinder firstCylinder(34, 45);
    IsHigher(firstCylinder, firstSP);

    SqarePyramid secondSP(34, 45, 56);
    Cylinder secondCylinder(3, 4);
    IsHigher(secondCylinder, secondSP);
}
//✅