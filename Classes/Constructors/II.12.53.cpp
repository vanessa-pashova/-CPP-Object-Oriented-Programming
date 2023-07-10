//Да се дефинира клас Факт за намиране на факториела на естествено число.
#include <iostream>

class Fact
{
    private: 
        int num;

    public: 
        Fact(int num);
        int fact ();
};

Fact::Fact(int num) : num(num) {}

int Fact::fact()
{
    int x = 1;
    for (int i = 1; i <= num; i++)
        x *= i;

    return x;
}

int main ()
{
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    
    Fact first(4);
    std::cout << "Fact of the number is: " <<  first.fact();
}

//✅