//Да се дефинира функция, която сортира лексикографски във възходящ ред редица от точки в пространството. За целта да се използва класът Точка3, определящ пространството
//с целочислени координати

#include <iostream>
class Point3
{
    private:
        int x, y, z;

    public:
        Point3();
        Point3(int x, int y, int z);
        Point3 &operator= (const Point3 &other);

        void modifier ();
        void print_Info();

        friend std::istream& operator>>(std::istream& input, Point3& point);
        friend void create_Array (int size, Point3 points[]);
        bool lexix (Point3 p1, Point3 p2);
        void sort (int size, Point3 points[]);

        int getX () const;
        int getY () const;
        int getZ () const;

        void setX (int x);
        void setY (int y);
        void setZ (int z);
}; 

Point3 points[10];

int Point3::getX () const {
    return this->x;
}

int Point3::getY () const {
    return y;
}

int Point3::getZ () const {
    return z;
}

void Point3::setX (int x) {
    this->x = x;
}

void Point3::setY (int y) {
    this->y = y;
}

void Point3::setZ (int z) {
    this->z = z;
}

Point3::Point3 () : x(0), y(0), z(0) {}

Point3::Point3(int x, int y, int z) : x(x), y(y), z(z) {}

Point3& Point3::operator=(const Point3 &other)
{
    if(this == &other)
        return *this;
    
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;

    return *this;
}

void Point3::modifier()
{
    this->x += 1;
    this->y += 2;
    this->z +=3;

    std::cout << "[ Your point has coordinates -> (" << this->x << ", " << this->y << ", " << this->z << ") ]" << std::endl;
    std::cout << std::endl;
}

void Point3::print_Info () 
{
    std::cout << "[ Your point has coordinates -> (" << this->x << ", " << this->y << ", " << this->y << ") ]" << std::endl;
    std::cout << std::endl;
}

std::istream& operator>>(std::istream& input, Point3& point)
{
    input >> point.x >> point.y >> point.z;
    return input;
}

void create_Array (int size, Point3 points[])
{
    for (std::size_t i = 0 ; i < size; i++)
    {
        std::cout << "Element[" << i + 1 <<"] (x, y, z) -> " << std::endl;
        std::cin >> points[i].x >> points[i].y >> points[i].z;
    }
} 

bool lexix (Point3 p1, Point3 p2) {
    return p1.getX() < p2.getX() || p1.getX() == p2.getX() && p1.getY() < p2.getY() || p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() < p2.getZ();
}

void sort (int size, Point3 points[])
{
    for (std::size_t i = 0; i < size - 1; i++)
    {
        int k = i;
        Point3 min = points[i];

        for (std::size_t j = i + 1; j < size; j++)
        {
            if (lexix(points[j], min))
            {
                min = points[j];
                k = j;
            }

            points[k] = points[i];
            points[i] = min;
        }
    }
}

int main ()
{
    std::cout << std::endl;
    std::cout << "-------------------------" << std::endl;

    Point3 first (2, 3, 4);
    std::cout << "[ Your point has coordinates -> (" << first.getX() << ", " << first.getY() << ", " << first.getZ() << ") ]" << std::endl;
    first.modifier();

    Point3 secont (10, 11, 12), third(45, 46, 47);
    secont.print_Info();
    third.print_Info();
    
    std::cout << "-------------------------" << std::endl;
    secont = third;
    secont.print_Info();
    third.print_Info();
}
//✅