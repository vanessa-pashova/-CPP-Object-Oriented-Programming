//АБСТРАКЦИЯ С ДАННИ

//Да се дефинира АТД Вектор, който определя вектор в тримерното пространство и притежава ф-ции за:
//а) създаване на вектор и извеждане
//б) намиране на сумата на два вектора
//в) намиране на разликата на два вектора
//г) намиране на произведението на вектор с число
//д) намиране на скаларното произведение на два вектора
//е) намиране на вектортното произведение на два вектора

#include <iostream>
#include <cmath>
const std::size_t size = 3;

struct Vector 
{
    int x, y, z;
};

void create_OneVector (Vector &obj)
{
    std::cout << "[ Creation of a Vector genereted ]" << std::endl;
    std::cout << "x = ";
    std::cin >> obj.x;
    std::cout << "y = ";
    std::cin >> obj.y;
    std::cout << "z = ";
    std::cin >> obj.z;

    std::cout << std::endl;
}

void print_InfoForOne (Vector &obj)
{
    std::cout << "[ Your Vector was successfully genereted ]" << std::endl;
    std::cout << "(x, y, z) = (" << obj.x << ", " << obj.y << ", " << obj.z << ")." << std::endl; 

    std::cout << std::endl;
}

Vector vectors[size];

void Sum_OfTwo (Vector &obj1, Vector &obj2)
{
    std::cout << "[ Sum of both vectors genereted ]\n> ";
    
    Vector vec;
    vec.x = obj1.x + obj2.x;
    vec.y = obj1.y + obj2.y;
    vec.z = obj1.z + obj2.z;
    std::cout << '(' << vec.x << ", " << vec.y << ", " << vec.z << ")." << std::endl;
    
    std::cout << std::endl;
}

void Substraction_OfTwo (Vector &obj1, Vector &obj2)
{
    std::cout << "[ Substraction of both vectors genereted ]\n> ";
    
    Vector vec;
    vec.x = obj1.x - obj2.x;
    vec.y = obj1.y - obj2.y;
    vec.z = obj1.z - obj2.z;
    std::cout << '(' << vec.x << ", " << vec.y << ", " << vec.z << ")." << std::endl;

    std::cout << std::endl;
}

void Multiplication_VectorAndNumber (Vector &obj)
{
    int num = 0;
    std::cout << "[ Insert a number for the multiplication ]\n> ";
    std::cin >> num;

    Vector vec;
    vec.x = obj.x * num;
    vec.y = obj.y * num;
    vec.z = obj.z * num;
    std::cout << '(' << vec.x << ", " << vec.y << ", " << vec.z << ")." << std::endl;

    std::cout << std::endl;
}

int Lenght_OfVector (Vector &obj) {
    return sqrt(pow(obj.x, 2) + pow(obj.y, 2) + pow(obj.z, 2));
}

void ScalarMultiplication_OfTwo (Vector &obj1, Vector &obj2)
{
    std::cout << "[ Sum of both vectors genereted ]" << std::endl;
    double cos = 0;
    do {
        std::cout << "[ Choose cos between 1/2, (2^1/2)/2, (3^1/2)/2, 0, 1 ]\n> ";
        std::cin >> cos;
    } while (cos != 1 && cos != 2 && cos != 3 && cos !=  4 && cos !=  5);
    
    double a = Lenght_OfVector(obj1);
    double b = Lenght_OfVector(obj2);

    double result = a * b * cos;
    std::cout << "[ Result ]\n> " << result << std::endl;
    std::cout << std::endl;
}

void VectorMultiplication_OfTwo (Vector &obj1, Vector &obj2)
{
    std::cout << "[ Sum of both vectors genereted ]" << std::endl;
    double sin = 0;
    do {
        std::cout << "[ Choose cos between 1/2, (2^1/2)/2, (3^1/2)/2, 0, 1 ]\n> ";
        std::cin >> sin;
    } while (sin != 1 && sin != 2 && sin != 3 && sin != 4 && sin != 5);
    
    double a = Lenght_OfVector(obj1);
    double b = Lenght_OfVector(obj2);

    double result = a * b * sin;
    std::cout << "[ Result ]\n> " << result << std::endl;
    std::cout << std::endl;
}

int main ()
{
    std::cout << std::endl;
    std::cout << "----------------------" << std::endl;

    Vector first, second;
    create_OneVector(first);
    create_OneVector(second);

    print_InfoForOne(first);
    print_InfoForOne(first);

    Sum_OfTwo(first, second);
    Substraction_OfTwo(first, second);

    Multiplication_VectorAndNumber(first);
    Multiplication_VectorAndNumber(second);

    ScalarMultiplication_OfTwo(first, second);
    VectorMultiplication_OfTwo(first, second);
}

//✅