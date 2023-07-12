//Да се напише програма, която заделя памет за масив от 10 указателя към точки в тримерното пространство с цели координати. Инициализира се заделента памет и намира точките
//в тримерното протранство, към които сочат указателите на създадения масив, които са на най-малко и на най-голямо разстояние до координатното начало

#include <iostream>
#include <cmath>

class Point3 
{
    private:
        int x, y, z;

    public:
        int getX() const;
        int getY() const;
        int getZ() const;

        Point3 (int x, int y, int z);

        int distance (Point3 **array);

        void create_List (Point3 **array);
        void smallestDistance (Point3 **array);
        void biggestDistance (Point3 **array);
        void deallocate (Point3 **arr);
};

int Point3::getX () const {
    return this->x;
}

int Point3::getY () const {
    return this->y;
}

int Point3::getZ () const {
    return this->z;
}

Point3::Point3(int x, int y, int z) : x(x), y(y), z(z) {}

int Point3::distance (Point3 **array) {
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

void Point3::create_List (Point3 **array) 
{
    std::cout << "[ Creation of List generated ]" << std::endl;
    for (std::size_t i = 0; i < 10; i++)
    {
        int x, y, z;
        std::cout << "[ Insert (x, y, z) for point " << i + 1 << " ]" << std::endl;
        std::cin >> x >> y >> z;

        array[i] = new Point3(x, y, z);        //заделяне на памет
        std::cout << std::endl;
    }
}

void Point3::smallestDistance (Point3 **array)
{
    int min = array[0]->distance(array);
    for (std::size_t i = 1; i < 10; i++)
    {
        if (min > array[i]->distance(array))
            min = array[i]->distance(array);
    }

    std::cout << "> Smallest distance: " << min << std::endl;
}

void Point3::biggestDistance (Point3 **array)
{
    int max = array[0]->distance(array);
    for (std::size_t i = 1; i < 10; i++)
    {
        if (max < array[i]->distance(array))
            max = array[i]->distance(array);
    }

    std::cout << "> Biggest distance: " << max << std::endl;
}

void Point3::deallocate (Point3 **arr) 
{
    for (std::size_t i = 0; i < 10; i++)
        delete arr[i];
    delete [] arr;
}

int main ()
{
    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;

    Point3 **array = new Point3*[10];
    array[10]->create_List(array);
    array[10]->biggestDistance(array);
    array[10]->smallestDistance(array);
    array[10]->deallocate(array);
}

//✅