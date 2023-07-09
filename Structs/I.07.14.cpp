//Да се дефинира функция, която намира разстоянието между две точки в равнина. Като се използва тази ф-ция, да се напише програма, която въвежда координатите на 
//n точки от равнината (2 <= n <= 100), намира и извежда най-голямото разстояние между тях. За целта да се дефинира структура, определяща точка 
//от равнината с декартови координати. Сортирайте

#include <iostream>
const std::size_t MAX = 101;

struct Point {
    int x, y;
};

struct Vector {
    Point a, b;
};

void create_Vector (Vector &obj)
{
    std::cout << "Insert four coordinates (following x, y): " << std::endl;
    std::cin >> obj.a.x >> obj.a.y;
    std::cin >> obj.b.x >> obj.b.y;

    int first = obj.b.x - obj.a.x;
    int second = obj.b.y - obj.a.y;
    std::cout << "x of Vector: " << first << std::endl;
    std::cout << "y of Vector: " << second << std::endl;
}

double lenght (Vector &obj)
{
    int first = obj.b.x - obj.a.x;
    int second = obj.b.y - obj.a.y;
    int lenght = sqrt(pow(first, 2) + pow(second, 2));
    return lenght;
}

Vector vectors[MAX];

void print_AllVectors(int &count, Vector vectors[])
{
    for (std::size_t i = 0; i < count; i++)
        std::cout << "Lenght of Vector[" << i + 1 << "]: " << lenght(vectors[i]) << std::endl;
}

void create_MultipleVectors(int &count, Vector vectors[])
{
    for (std::size_t i = 0; i < count; i++)
        create_Vector(vectors[i]);
}

int find_TheGreatestVector(int &count, Vector vectors[])
{
    int max = 0;

    for (std::size_t i = 0; i < count; i++)
    {
        int temp = lenght(vectors[i]);
        
        if (temp > max)
            max = temp;
    }

    return max;
}

void sort (int &count, Vector vectors[])
{
    for (std::size_t i = 0; i < count - 1; i++)
    {
        int k = i;
        Vector min = vectors[i];

        for (std::size_t j = i + 1; j < count; j++)
        {
            if (lenght(vectors[j]) > lenght(vectors[i]))
            {
                min = vectors[i];
                k = j;
            }
        }

        vectors[k] = vectors[i];
        vectors[i] = min;
    }

    for (std::size_t i = 0; i < count; i++)
        std::cout << lenght(vectors[i]) << " ";

    std::cout << std::endl;
}

int main ()
{
    std::cout << std::endl;
    std::cout << "-------------------------------" << std::endl;

    int count = 0;
    do
    {
        std::cout << "Please, insert how many vectors you will make between 2 and 100: ";
        std::cin >> count;
    } while (count < 2 || 100 < count);

    create_MultipleVectors(count, vectors);
    print_AllVectors(count,vectors);
    sort(count, vectors);
    std::cout << "The greatest vector of them all is: " << find_TheGreatestVector(count, vectors);
}

//✅
