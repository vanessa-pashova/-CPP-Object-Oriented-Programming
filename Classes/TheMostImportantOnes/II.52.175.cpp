//Да се дефинира клас Кръг, описващ кръг в равнината. Класът да съдържа:
// - конструктор по подразбиране, създаващ кръг център началото на координатната система и радиус 1
// - оператор за събиране на два кръга, който създава нов кръг с радиус, равен на сумата на двата радиуса и център сума от координатите на центровете на двата кръга
// - оператор += 
// - метод bool isIn(double, double), проверяващ дали дадена точка лежи в кръг
// - оператори == и !=
// - оператори за сравнение < и > 
#include <iostream>
#include <cmath>

class Point
{
    private:
        friend class Circle;
        int x, y;

    public:
        Point();
        Point(int, int);

        int getX () const;
        int getY () const;

        void insert();
        void print();

        bool operator==(const Point &) const;
        bool operator!=(const Point &) const;
        bool operator<(const Point &) const;
        bool operator>(const Point &) const;

        Point operator+(const Point &other) const;
};

Point Point::operator+(const Point &other) const {
    return Point(this->x + other.x, this->y + other.y);
}

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX () const {
    return this->x;
}

int Point::getY () const {
    return this->y;
}

void Point::insert() 
{
    std::cout << "[ insert coordinates for a point (x, y) ] --> /n";
    std::cin >> this->x >> this->y;

    std::cout << '\n';
}

void Point::print() {
    std::cout << '(' << this->x << ", " << this->y << ')' << std::endl;
}

bool Point::operator==(const Point &other) const {
    return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point &other) const {
    return this->x != other.x && this->y != other.y;
}

bool Point::operator<(const Point &other) const {
    return this->x > other.x && this->y > other.y;
}

bool Point::operator>(const Point &other) const {
    return this->x < other.x && this->y < other.y;
}

class Circle
{
    private: 
        Point center;
        int radius;

        void copyFrom(const Circle &other)
        {
            this->radius = other.radius;
            this->center.x = other.center.x;
            this->center.y = other.center.y;
        }

    public:
        Circle();
        Circle(Point center, int radius);
        Circle &operator=(const Circle &);

        bool isIn(int, int);

        Circle operator+=(const Circle &);
        Circle sum(const Circle &) const;

        bool operator==(const Circle &) const;
        bool operator!=(const Circle &) const;
        bool operator<(const Circle &) const;
        bool operator>(const Circle &) const;

        void print();
};

Circle Circle::sum(const Circle &other) const {
    return Circle(this->center + other.center, this->radius + other.radius);
}
        
Circle operator+(const Circle &obj1, const Circle &obj2) {
    return obj1.sum(obj2);
}
 
Circle::Circle() : center(Point(0, 0)), radius(0) {}
Circle::Circle(Point center, int radius) : center(center), radius(radius) {}

Circle &Circle::operator=(const Circle &other)
{
    if (this != &other)
        this->copyFrom(other);

    return *this;
}

bool Circle::isIn(int px, int py)
{
    int new_rad_x = px - this->center.x;
    int new_rad_y = py - this->center.y;
    int new_rad = sqrt(pow(new_rad_x, 2) + pow(new_rad_y, 2));

    return this->radius >= new_rad;
}

Circle Circle::operator+=(const Circle &obj)
{
    this->center = this->center + obj.center;
    this->radius += obj.radius;

    return *this;
}

bool Circle::operator==(const Circle &other) const {
    return this->center == other.center && this->radius == other.radius;
}

bool Circle::operator!=(const Circle &other) const {
    return !(*this == other);
}

bool Circle::operator<(const Circle &other) const {
    return this->radius < other.radius;
}

bool Circle::operator>(const Circle &other) const {
    return this->radius > other.radius;
}

void Circle::print() {
    std::cout << "[ your circle information ]\n> center: "; this->center.print();
    std::cout << "> radius: " << this->radius << "\n\n";
}

int main()
{
    // Демонстрация на клас Point
    std::cout << "=== Point Class ===\n";
    Point p1(3, 5);
    Point p2(7, 2);
    Point p3;

    std::cout << "Point p1: ";
    p1.print();

    std::cout << "Point p2: ";
    p2.print();

    std::cout << "Point p3: ";
    p3.print();

    std::cout << "p1 == p2: " << (p1 == p2) << '\n';
    std::cout << "p1 != p2: " << (p1 != p2) << '\n';
    std::cout << "p1 < p2: " << (p1 < p2) << '\n';
    std::cout << "p1 > p2: " << (p1 > p2) << '\n';

    // Демонстрация на клас Circle
    std::cout << "\n=== Circle Class ===\n";
    Circle c1(p1, 5);
    Circle c2(p2, 3);
    Circle c3;

    std::cout << "Circle c1: Center ";
    c1.print();

    std::cout << "Circle c2: Center ";
    c2.print();

    std::cout << "Circle c3: Center ";
    c3.print();

    std::cout << "c1 == c2: " << (c1 == c2) << '\n';
    std::cout << "c1 != c2: " << (c1 != c2) << '\n';
    std::cout << "c1 < c2: " << (c1 < c2) << '\n';
    std::cout << "c1 > c2: " << (c1 > c2) << '\n';

    std::cout << "Is point (4, 5) inside c1? " << c1.isIn(4, 5) << '\n';
    std::cout << "Is point (8, 2) inside c2? " << c2.isIn(8, 2) << '\n';

    // Демонстрация на оператори за събиране
    std::cout << "\n=== Circle Addition ===\n";
    Circle c4 = c1 + c2;
    std::cout << "Circle c4 (c1 + c2): Center ";
    c4.print();

    // Демонстрация на оператор +=
    std::cout << "\n=== Circle += ===\n";
    c4 += c3;
    std::cout << "Circle c4 (c4 += c3): Center ";
    c4.print();

    return 0;
}
//✅

