//Да се дефинира клас Абсолют, чрез който да се намира абсолютна стойност на цяло и реално число
#include <iostream>
#include <cmath>

class Absolute 
{
    public: 
        int absolute(int);
        double absolute(double);
};

int Absolute::absolute(int num) {
    return abs(num);
}

double Absolute::absolute(double num) {
    return abs(num);
}

int main ()
{
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;

    Absolute num;
    std::cout << "Abs value of -873 is: " << num.absolute(-873) << std::endl;
    std::cout << "Abs value of -340.56 is: " << num.absolute(-340.56) << std::endl;
}
//✅
