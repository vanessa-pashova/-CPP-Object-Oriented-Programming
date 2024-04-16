#include <iostream>

class Imperial {
private:
    short yards, feet, inches;

public:
    Imperial();
    Imperial(short, short, short);

    void add(const Imperial &);
    void mul(short);
    void print() const;

    const short getYards() const;
    const short getFeet() const;
    const short getInches() const;
};

Imperial::Imperial() : yards(0), feet(0), inches(0) {}

Imperial::Imperial(short y, short f, short i) {
    this->yards = y;
    this->feet = f;
    this->inches = i;
}

void Imperial::add(const Imperial &other) {
    this->yards += other.yards;
    this->feet += other.feet;
    this->inches += other.inches;
}

void Imperial::mul(short num) {
    this->yards *= num;
    this->feet *= num;
    this->inches *= num;
}

void Imperial::print() const {
    std::cout << "Yards: " << this->inches << ", Feet: " << this->feet << ", Inches: " << this->inches << '\n';
}

const short Imperial::getYards() const {
    return this->yards;
}

const short Imperial::getFeet() const {
    return this->feet;
}

const short Imperial::getInches() const {
    return this->inches;
}

int main() {
    Imperial obj, obj2(2, 2, 2);
    obj.print();
    obj2.print();

    obj.add(obj2);
    obj.print();

    obj.mul(3);
    obj.print();
}