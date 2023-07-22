//Да се дефинират класовете Кола и Бус, определящи лек автомобил и автобус. Всеки от класовете да има реална член-данна скорост, определяща скоростта на превозното средство,
//както и конструктори и методи за достъп. Да се дефинира приятелска ф-ция, която определя чия скорост е по-голяма

#include <iostream>
class Car
{
    private:
        unsigned int speed;
    
    public:
        Car();
        Car(unsigned int);
        Car &operator=(const Car &);

        int getSpeed() const;
};

Car::Car() : speed(0) {}
Car::Car(unsigned int speed)
{
    if (240 < speed)
    {
        speed = 240;
        std::cout << "[ max value for car speed is 240; set by default ]\n";
    }

    this->speed = speed;
}

Car &Car::operator=(const Car &other) 
{
    this->speed = other.speed;
    return *this;
}

int Car::getSpeed () const {
    return this->speed;
}

class Bus
{
    private:
        unsigned int speed;

    public:
        Bus();
        Bus(unsigned int);
        Bus &operator=(const Bus &);

        int getSpeed() const;

        friend void greaterSpeed(const Car &obj, const Bus &obj1);
};

Bus::Bus() : speed(0) {}
Bus::Bus(unsigned int speed)
{
    if (150 < speed)
    {
        speed = 150;
        std::cout << "[ max value for bus speed is 150; set by default ]\n\n";
    }

    this->speed = speed;
}

Bus &Bus::operator=(const Bus &other) 
{
    this->speed = other.speed;
    return *this;
}

int Bus::getSpeed() const {
    return this->speed;
}

void greaterSpeed(const Car &car, const Bus &bus)
{
    if (car.getSpeed() < bus.getSpeed())
        std::cout << "[ the bus has greater speed than the car ]\n";

    else 
        std::cout << "[ the car has greater speed than the bus ]\n";
}

int main ()
{
    std::cout << '\n';
    std::cout << "----------------------------\n";

    Car car1(34), car2(234), car3(256);
    Bus bus1(90), bus2(100), bus3 = bus1;

    greaterSpeed(car1, bus1);
    greaterSpeed(car2, bus2);
}
//✅
