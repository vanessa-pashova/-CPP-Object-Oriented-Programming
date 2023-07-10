//Да се дефинира клас GDC, който да намира най-големия общ делител на две неотрицателни числа, от които поне едно не е 0.
#include <iostream>

class GDC {
    private:
        unsigned int num1, num2;

    public:
        GDC (unsigned int x, unsigned int y);
        unsigned int gdc ();
};

GDC::GDC (unsigned int x, unsigned int y) : num1(x), num2(y) {}

unsigned int GDC::gdc()
{
    if (num1 == 0)
        return num2;
    
    if (num2 == 0)
        return num1;

    unsigned int result = num1 > num2 ? num1 : num2;
    //В случая num1 > num2 ? num1 : num2 проверява дали num1 е по-голямо от num2. 
    //Ако условието е истина, то се връща стойността на num1, ако е лъжа, се връща стойността на num2.

    while (num1 != 0 && num2 != 0)
    {
        unsigned int remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;

        result = num1;
    }

    return result;
}

//В този пример използваме алгоритъма на Евклид, който повтаря делението между две числа, докато не достигне делителя 0.
//Последният ненулев делител е най-големият общ делител на двата входни числа.

int main ()
{
    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;

    GDC first(4, 10);
    std::cout << "GDC of the numbers: " << first.gdc() << std::endl;
}
//✅