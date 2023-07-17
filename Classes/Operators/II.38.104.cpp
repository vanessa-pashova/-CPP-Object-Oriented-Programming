//За класа Рат от предната задача, да се дефинират:
// - член-функция, която предефинира оператора за преобразуване на типове така, че да може да се преобразува рационално число в реално число
// - член-функции, които да предефинират операторитте +, -, *, /, така, че да работят с рационални числа 
// - член-функции или приятелски функции, които да предефинират операторитте +, -, *, /, така, че да могат да рационални с цели числа и цели числа с рационални числа

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
        Rat();
        Rat(int x, int y);
        Rat &operator= (const Rat &other);

        int getX () const;
        int getY () const;

        void print_Info ();

        operator double () const;

        //операторни-функции за рационално-числова аритметика на две рационални числа
        Rat operator+ (const Rat &) const;
        Rat operator- (const Rat &) const;
        Rat operator* (const Rat &) const;
        Rat operator/ (const Rat &) const;
        
        //операторни-функции за рационално-числова на аритметика на рационално с цяло число
        Rat operator+ (int) const;
        Rat operator- (int) const;
        Rat operator* (int) const;
        Rat operator/ (int) const;

        //приятелски ф-ции, реализиращи рационално-числова на аритметика на цяло число с рационално число
        friend Rat operator+ (int, const Rat &);
        friend Rat operator- (int, const Rat &);
        friend Rat operator* (int, const Rat &);
        friend Rat operator/ (int, const Rat &);
}; 

Rat::Rat () : x(0), y(1) {}
Rat::Rat(int x, int y) : x(x), y(y) {}

Rat &Rat::operator= (const Rat &other)
{
    if (this != &other)
        copyFrom(other);

    return *this;
}

int Rat::getX () const {
    return this->x;
}

int Rat::getY () const {
    return this->y;
}

void Rat::print_Info () {
    std::cout << "[ Your number is ] -> " << this->x << '/' << this->y;
}

//оператор, който променя целочислен в десетичен вид
Rat::operator double () const {
    return (double)x / y;
}

//оператори за две рационални числа
Rat Rat::operator+ (const Rat &other) const {
    return Rat (this->x * other.y + this->y * other.x, this->y * other.y);
}

Rat Rat::operator- (const Rat &other) const {
    return Rat (this->x * other.y - this->y * other.x, this->y * other.y);
}

Rat Rat::operator* (const Rat &other) const {
    return Rat (this->x * other.x, this->y * other.y);
}

Rat Rat::operator/ (const Rat &other) const {
    return Rat (this->x * other.y, this->y * other.x);
}

//оператори за рационално с цяло число
Rat Rat::operator+ (int num) const {
    return Rat (num * this->y + this->x, this->y);
}

Rat Rat::operator- (int num) const {
    return Rat (num * this->y - this->x, this->y);
}

Rat Rat::operator* (int num) const {
    return Rat (num * this->x, this->y);
}

Rat Rat::operator/ (int num) const {
    return Rat (num, this->x * this->y);
}

Rat operator+ (int num, const Rat &other) {
    return Rat (num * other.y + other.x, other.y);
}

Rat operator- (int num, const Rat &other) {
    return Rat (num * other.y - other.x, other.y);
}

Rat operator* (int num, const Rat &other) {
    return Rat (num * other.x, other.y);
}

Rat operator/ (int num, const Rat &other) {
    return Rat (num * other.y, other.x);
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
    third.print_Info();

    Rat forth = first * second;
    forth.print_Info();

    Rat fifth = first - second;
    fifth.print_Info();

    Rat sixth = first / second;
    sixth.print_Info();
}