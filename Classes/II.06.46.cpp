//Да се дефинира клас Ъгъл, чрез който се намират синусът, косинусът и тангендът на ъгъл, зададен с градуси
#include <iostream>
const double degToRad = 3.14159265 / 180;

class Angle
{
    private:
        double degrees;
    
    public:
        void setValue (double a);
        double getSin() const;
        double getCos() const;
        double getTan() const;
};

void Angle::setValue (double a) {
    degrees  = a;
}

double Angle::getSin () const {
    return degToRad * degrees;
}

double Angle::getCos () const {
    return degToRad * degrees;
}

double Angle::getTan () const {
    return degToRad * degrees;
}

int main ()
{
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;

    Angle first;
    first.setValue(45);
    
    std::cout << "sin(45) = " << first.getSin() << '.' << std::endl;
    std::cout << "cos(45) = " << first.getCos() << '.' << std::endl;
    std::cout << "tan(45) = " << first.getTan() << '.' << std::endl;
}

//✅



