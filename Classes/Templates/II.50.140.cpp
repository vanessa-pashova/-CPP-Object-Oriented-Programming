//Да се дефинира шаблон на процедура, която разменя стойностите на две променливи от тип Т. Да се използва дефинираният шаблон, за да се разменят стойности от тип:
// инт, дабъл, чар

#include <iostream>

template <class T>
void swap (T &obj, T &obj2)
{
    T temp = obj;
    obj = obj2;
    obj2 = temp;
}

template <class T>
void print (T &obj, T &obj2) {
    std::cout << "[ after swap function: ] -> " << obj << " -- " << obj2 << '\n';
}

int main ()
{
    std::cout << '\n';
    std::cout << "-------------------------\n";

    int a = 45, b = 70;
    swap(a, b);
    print(a, b);

    double f = 4.5, g = 5.67543;
    swap(f, g);
    print(f, g);

    char c = 'V', d = 'M';
    swap(c, d);
    print(c, d);
}
//✅