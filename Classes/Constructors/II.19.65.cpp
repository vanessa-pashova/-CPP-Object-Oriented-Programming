//Да се напише програма, която дефинира клас Точка3, определящ точка в пространството с целочислени координати; класът да притежава:
// - конструктор с параметри, определящ координатите на точката, като се подразбира точката (0, 0, 0)
// - конструктор за присвояване
// - ф-ции за достъп до координатите на точката
// - мутатори на координатите на точка
//Като се използват двата конструкура, в главната ф-ция да се дефинират няколко точки и да се изведат координатите им. Като се използват мутаторите на координатите
//на точка да се променят координатите на указания като формален параметър обект, увеличени с 1, 2 и 3 съответно

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

        int getX () const;
        int getY () const;
        int getZ () const;

        void setX (int x);
        void setY (int y);
        void setZ (int z);
}; 

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

void Point3::print_Info () {
    std::cout << "[ Your point has coordinates -> (" << this->x << ", " << this->y << ", " << this->y << ") ]" << std::endl;
    std::cout << std::endl;
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