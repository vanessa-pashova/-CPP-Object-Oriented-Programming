//Да се дефинира клас Rat, който да реализира АТД "рационално число". Освен конструктори, класът да съдържа методи за:
// - достъп до числителя и знаменателя
// - извеждане на числото
// - промяна на числителя и знаменателя
// - рационално-числова аритметика
//Да се реализират външни ф-ции, които да предефинират операторите +, -, * и /
#include <iostream>

class Rat
{
    private:
        int x, y;

        void copyFrom (const Rat &other)
        {
            this->x = other.x;
            this->y = other.y;
        }

    public:
        int getX () const;
        int getY () const;

        void setX (int);
        void setY (int);

        Rat ();
        Rat(int x, int y);
        Rat &operator= (const Rat &other);

        void print_Number ();
        void chengeNumber ();

        Rat sum (const Rat &) const;
        Rat sub (const Rat &) const;
        Rat mult (const Rat &) const;
        Rat dev (const Rat &) const;
};

Rat operator+ (const Rat &obj1, const Rat obj2);
Rat operator- (const Rat &obj1, const Rat obj2);
Rat operator* (const Rat &obj1, const Rat obj2);
Rat operator/ (const Rat &obj1, const Rat obj2);

Rat::Rat () : x(0), y(1) {}
Rat::Rat (int x, int y) : x(x), y(y) {}

Rat &Rat::operator= (const Rat &other)
{
    if (this != &other)
        this->copyFrom(other);

    return *this;
}

void Rat::print_Number ()
{
    std::cout << "[ print function genereted ]\n> Your number is: " << this->x << '/' << this->y << '\n';
    std::cout << std::endl;
}

void Rat::chengeNumber ()
{
    int a, b;
    this->x = a; this->y = b;
    std::cout << "[ change number function genereted. Insert new values for x and y]\n> x: ";
    std::cin >> a;
    std::cout << "> y: ";
    std::cin >> b;

    std::cout << std::endl;
    print_Number();
}

int Rat::getX () const {
    return this->x;
}

int Rat::getY () const {
    return this->y;
}

void Rat::setX (int x) {
    this->x = x;
}

void Rat::setY (int y) 
{
    if (y == 0)
    {
        std::cout << "[ y cannot be equal to 0, value changed to 1 ]\n";
        y = 1;
    }

    this->y = y;
}

//създадаваме нов обект от тип Rat с помощта на конструктора Rat(int, int) и да го връщаме
Rat Rat::sum (const Rat &other) const {
    return Rat(this->x * other.y + other.x * this->y, this->y * other.y);
}

Rat Rat::sub (const Rat &other) const {
    return Rat(this->x * other.y - other.x *this->y, this->y * other.y);
}

Rat Rat::mult (const Rat &other) const {
    return Rat(this->x * other.x, this->y * other.y);
}

Rat Rat::dev (const Rat &other) const {
    return Rat(this->x * other.y, this->y * other.x);
}

Rat operator+ (const Rat &obj1, const Rat obj2) {
    return obj1.sum(obj2);
}

Rat operator- (const Rat &obj1, const Rat obj2) {
    return obj1.sub(obj2);
}

Rat operator/ (const Rat &obj1, const Rat obj2) {
    return obj1.dev(obj2);
}

Rat operator* (const Rat &obj1, const Rat obj2) {
    return obj1.mult(obj2);
}

int main ()
{
    std::cout << '\n';
    std::cout << "------------------------\n";

    int a, b, c, d;
    do {
        std::cout << "> a = ";
        std::cin >> a;
        std::cout << "> b = ";
        std::cin >> b;

        std::cout << "> c = ";
        std::cin >> c;
        std::cout << "> d = ";
        std::cin >> d;
    } while (b == 0 || d == 0);
    
    Rat first (a, b), second(c, d);
    Rat third = first + second;
    third.print_Number();

    Rat forth = first * second;
    forth.print_Number();

    Rat fifth = first - second;
    fifth.print_Number();

    Rat sixth = first / second;
    sixth.print_Number();
}
//✅