//Да се дефинира клас IsFraction, съдържащ две цели член-данни n и d≠0, конструктор и ф-ции за достъп до компонентите. Да се дефинира приятелска ф-ция 
//IsFraction на класа, която определя дали n не се дели целочислено на d
#include <iostream>

class IsFraction
{
    private:
        int n, d;

    public: 
        int getN () const;
        int getD () const;
        void setD (int d);

        IsFraction(int n, int d);    
        friend bool is_Fraction (const IsFraction &obj);
        void print_Info (const IsFraction &obj);
};

int IsFraction::getD () const {
    return this->d;
}

int IsFraction::getN () const {
    return this->n;
}

void IsFraction::setD(int d)
{
    if (d == 0)
    {
        std::cout << "[ d should not be equal to 0 ]\n";
        exit(1);
    }

    this->d = d;
}

IsFraction::IsFraction(int n, int d)
{
    this->n = n;
    this->d = d;
}

bool is_Fraction (const IsFraction &obj)
{
    if (obj.n % obj.d == 0)
        return true;

    return false;
}

void IsFraction::print_Info (const IsFraction &obj)
{
    std::cout << "[ info genereted ]\n";
    if (!is_Fraction(obj))
        std::cout << "[ n cannot be devided by d ]\n";

    else 
        std::cout << "[ n CAN be devided by d ]\n";

    std::cout << std::endl;
}

int main ()
{
    std::cout << std::endl;
    std::cout << "--------------------------------\n";

    int a, b;
    std::cout << "a = ";
    std::cin >> a;
    do {
        std::cout << "b = ";
        std::cin >> b;
    } while (b == 0);

    IsFraction first(a, b);
    first.print_Info(first);
}
//✅