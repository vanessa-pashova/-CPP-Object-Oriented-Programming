//Да се предефинират оператори:

#include <iostream>
#include <cmath>

class Point3 
{
    private:
        int x, y, z;

        void copyFrom (const Point3 &other)
        {
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
        }

    public:
        int getX() const;
        int getY() const;
        int getZ() const;

        Point3 ();
        Point3 (int x, int y, int z);
        Point3 &operator= (const Point3 &);

        Point3 operator- () const;
        Point3 operator- (const Point3 &) const;

        friend Point3 operator+ (const Point3 &);
        friend Point3 operator+ (const Point3 &, const Point3 &);

        Point3 &operator-- ();
        Point3 operator-- (int);

        friend Point3 &operator++ (Point3 &);
        friend Point3 operator++ (Point3 &, int);

        void print ();
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

Point3::Point3() : x(0), y(0), z(0) {}
Point3::Point3(int x, int y, int z) : x(x), y(y), z(z) {}

Point3 &Point3::operator= (const Point3 &other) 
{
    if (this != &other)
        copyFrom(other);

    return *this;
}

//унарен оператор -
Point3 Point3::operator- () const 
{
    Point3 new_p;
    new_p.x = -x;
    new_p .y = -y;
    new_p.z = -z;

    return new_p;
}

//бинарен оператор -
Point3 Point3::operator- (const Point3 &other) const
{
    Point3 new_p;
    new_p.x = this->x - other.x;
    new_p.y = this->y - other.y;
    new_p.z = this->z - other.z;

    return new_p;
}

Point3 operator+ (const Point3 &other)
{
    Point3 new_p;
    new_p.x = other.x + 1;
    new_p.y = other.y + 1;
    new_p.z = other.z + 1;

    return new_p;
}

Point3 operator+ (const Point3 &obj1, const Point3 &obj2)
{
    Point3 new_p;
    new_p.x = obj1.x + obj2.x;
    new_p.y = obj1.y + obj2.y;
    new_p.z = obj1.z + obj2.z;

    return new_p;
}

Point3 &Point3::operator-- ()
{
    --x;
    --y;
    --z;

    return *this;
}

Point3 Point3::operator-- (int num)
{
    Point3 temp(x, y, z);
    x--;
    y--;
    z--;

    return temp;
}

Point3 &operator++ (Point3 &obj)
{
    ++obj.x;
    ++obj.y;
    ++obj.z;

    return obj;
}

Point3 operator++ (Point3 &obj, int num)
{
    Point3 temp(obj);
    temp.x++;
    temp.y++;
    temp.z++;

    return temp;
}

void Point3::print () {
    std::cout << "[ Your point genereted ] --> (" << this->x << ", " << this->y << ", " << this->z << ')' << std::endl;
    std::cout << '\n';
}

int main ()
{
    std::cout << '\n';
    std::cout << "---------------------------\n";

    Point3 p1(4, 3, 1), p2(10, 34, 46), p3, p4, p5, p6;
    p1.print();
    p2.print();

    p3 = p1 - p2;
    p3.print();

    p4 = -p1;
    p4.print();

    p5 = +p1;
    p5.print();

    p6 = p4 + p5;
    p6.print();
}
//✅