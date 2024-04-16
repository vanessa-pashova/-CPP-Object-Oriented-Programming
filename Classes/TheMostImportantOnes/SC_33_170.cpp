//! incomplete
#include <iostream>

const short MAX_SIZE = 10;

class PointsArr {
public:
    struct Point {
        short x, y;

        short getX() const {
            return this->x;
        }

        short getY() const {
            return this->y;
        }

        void setPoint(short numX, short numY) {
            this->x = numX;
            this->y = numY;
        }
    };

private:
    Point *arr = new Point[MAX_SIZE];
    short size;

    void deallocate() {
        delete [] this->arr;
    }

public:
    PointsArr();
    PointsArr(const Point*, const short);
    ~PointsArr();

    void setSize(short);
    Point* getArr() const { return arr; }
    short getSize() const { return size; }
};

PointsArr::PointsArr() : arr(nullptr), size(0) {}

PointsArr::PointsArr(const Point *points, const short size) {
    this->setSize(size);

    this->arr = new Point[this->size];
    for(short i = 0; i < this->size; i++) {
        this->arr[i] = points[i];
    }
}

PointsArr::~PointsArr() {
    this->deallocate();
}

void PointsArr::setSize(short num) {
    if(num > MAX_SIZE)
        this->size = MAX_SIZE;

    else if(num < 0)
        this->size = 0;

    else
        this->size = num;
}

int main() {
    PointsArr::Point points[] = {{1, 2}, {3, 4}, {5, 6}};
    short numPoints = sizeof(points) / sizeof(points[0]);

    PointsArr pointsArray(points, numPoints);

    std::cout << "Size of points array: " << pointsArray.getSize() << std::endl;

    std::cout << "Points array:" << std::endl;
    for (short i = 0; i < pointsArray.getSize(); ++i) {
        std::cout << "Point " << i + 1 << ": (" << pointsArray.getArr()[i].x << ", " << pointsArray.getArr()[i].y << ")" << std::endl;
    }
}
