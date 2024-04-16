#include <iostream>

template <typename T>
class Vector {
private:
    T *vec;
    short size;

    void deallocate() {
        delete [] this->vec;
    }

    void copyFrom(const Vector &other) {
//        this->deallocate();
        this->size = other.size;

        this->vec = new short[this->size];
        for(short i = 0; i < this->size; i++)
            this->vec[i] = other.vec[i];
    }

public:
    Vector();
    Vector(const T *vec, const short size);
    Vector(const Vector &other);
    Vector &operator=(const Vector &other);
    ~Vector();

    short getSize() const;
    T getVec() const;

    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;
    Vector &operator*(const short num);
    Vector operator*(const Vector &other) const;
    Vector &operator/(const short num);
    Vector &operator++();
    Vector &operator--();
    bool operator==(const Vector &other) const;
    bool operator!=(const Vector &other) const;
    short &operator[](const short num);
    short &operator()();
//    bool operator||(const Vector &other) const;
    bool operator^(const Vector &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Vector &obj) {
        for(short i = 0; i < obj.getSize(); i++)
            out << obj.vec[i] << ' ';

        return out;
    }

    friend std::istream &operator>>(std::istream  &in, Vector &obj);
};

template <typename T>
Vector<T>::Vector() : vec(nullptr), size(0) {}

template <typename T>
Vector<T>::Vector(const T *vec, const short size) {
    if(size < 0)
        this->size = 0;

    else this->size = size;
    this->vec = new T[this->size];
    for(short i = 0; i < this->size; i++)
        this->vec[i] = vec[i];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other) {
    if(this != &other)
        this->copyFrom(other);
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
    if(this != &other)
        this->copyFrom(other);

    return *this;
}

template <typename T>
Vector<T>::~Vector() {
    this->deallocate();
}

template <typename T>
short Vector<T>::getSize() const {
    return this->size;
}

template <typename T>
T Vector<T>::getVec() const {
    return this->vec;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &other) const {
    Vector<T> newVec;
    newVec.size = this->size;
    newVec.vec = new T[this->size];

    for(short i = 0; i < this->size; i++)
        newVec.vec[i] = this->vec[i] + other.vec[i];

    return newVec;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &other) const {
    Vector<T> newVec;
    newVec.size = this->size;
    newVec.vec = new T[this->size];

    for(short i = 0; i < this->size; i++)
        newVec.vec[i] = this->vec[i] - other.vec[i];

    return newVec;
}

template <typename T>
Vector<T> &Vector<T>::operator*(const short num) {
    for(short i = 0; i < this->size; i++)
        this->vec[i] = this->vec[i] * num;

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator*(const Vector<T> &other) const {
    Vector<T> newVec;
    newVec.size = this->size;
    newVec.vec = new T[this->size];

    for(short i = 0; i < this->size; i++)
        newVec.vec[i] = (this->vec[i] * other.vec[i]);

    return newVec;
}

template <typename T>
Vector<T> &Vector<T>::operator/(const short num) {
    for(short i = 0; i < this->size; i++)
        this->vec[i] = this->vec[i] / num;

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator++() {
    for(short i = 0; i < this->size; i++)
        this->vec[i] += 1;

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator--() {
    for(short i = 0; i < this->size; i++)
        this->vec[i] -= 1;

    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &other) const {
    bool flag = false;
    for(short i = 0; i < this->size; i++) {
        if(this->vec[i] != other.vec[i]) {
            flag = true;
            break;
        }
    }

    if(!flag)
        return true;

    else return false;
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T> &other) const {
    return !this->operator==(other);
}

template <typename T>
short &Vector<T>::operator[](const short num) {
    return this->vec[num];
}

template <typename T>
short &Vector<T>::operator()() {
    return this->size;
}

//template <typename T>
//bool Vector<T>::operator||(const Vector<T> &other) const {
//
//}

template <typename T>
bool Vector<T>::operator^(const Vector<T> &other) const {
    short num = 0;
    for(short i = 0; i < this->size; i++)
        num += this->vec[i] * other.vec[i];

    return num == -1;
}

template <typename T>
std::istream &operator>>(std::istream &in, const Vector<T> &obj) {
    short num;
    std::cout << "Insert size greater than 0: ";
    in >> num;

    obj.size = num;
    obj.vec = new T[num];
    for(short i = 0; i < num; i++)
        in >> obj.vec[i];

    return in;
}

int main() {
    short arr1[] = {1, 2, 3};
    short arr2[] = {3, 6, 9};

    Vector<short> vec1(arr1, 3);
    Vector<short> vec2(arr2, 3);

    std::cout << "Vector 1: " << vec1 << std::endl;
    std::cout << "Vector 2: " << vec2 << std::endl;

    // Проверка на оператора за събиране
    Vector<short> sumVec = vec1 + vec2;
    std::cout << "Sum of vectors: " << sumVec << std::endl;

    // Проверка на оператора за изваждане
    Vector<short> diffVec = vec1 - vec2;
    std::cout << "Difference of vectors: " << diffVec << std::endl;

    // Проверка на оператора за умножение с число
    Vector<short> scaledVec = vec1 * 2;
    std::cout << "Scaled vector: " << scaledVec << std::endl;

    // Проверка на оператора за умножение на два вектора (поелементно)
    Vector<short> elementWiseProductVec = vec2 * vec1;
    std::cout << "Element-wise product of vectors: " << elementWiseProductVec << std::endl;

    // Проверка на оператора за деление на число
    Vector<short> dividedVec = vec2 / 3;
    std::cout << "Vector2 divided by 3: " << dividedVec << std::endl;

    // Проверка на префиксния оператор ++
    ++vec1;
    std::cout << "Vector 1 after prefix increment: " << vec1 << std::endl;

    // Проверка на префиксния оператор --
    --vec1;
    std::cout << "Vector 1 after prefix decrement: " << vec1 << std::endl;

    // Проверка на оператора за сравнение ==
    if (vec1 == vec2)
        std::cout << "Vectors are equal." << std::endl;

    // Проверка на оператора за сравнение !=
    if (vec1 != vec2)
        std::cout << "Vectors are not equal." << std::endl;

    // Проверка на оператора [], за достъп до елементите на вектора по индекс
    std::cout << "Element at index 1 of vector 1: " << vec1[0] << std::endl;

    std::cout << "Size of vector 1: " << vec1() << std::endl;

    if (vec1 ^ vec2) {
        std::cout << "Vectors are perpendicular." << std::endl;
    } else {
        std::cout << "Vectors are not perpendicular." << std::endl;
    }
}
