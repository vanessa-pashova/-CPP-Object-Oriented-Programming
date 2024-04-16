#include <iostream>
const short MAX_SIZE = 10;

class RatNums {
private:
    float* arr = new float[MAX_SIZE];
    short size;

    void deallocate(){
        delete [] this->arr;
    }

    void copyFrom(const RatNums &other) {
        this->deallocate();

        this->size = other.size;
        this->arr = new float[this->size];

        for(short i = 0; i < this->size; i++)
            this->arr[i] = other.arr[i];
    }

    bool validIndex(short x) const {
        return 0 <= x && x < this->size;
    }

    bool validSize(short x) const {
        return 0 <= x && x < MAX_SIZE;
    }

    bool fullCap() const {
        return this->size == MAX_SIZE - 1;
    }

    bool empty() const {
        return this->size == 0;
    }

    void print() const {
        for(short i = 0; i < this->size; i++)
            std::cout << this->arr[i] << ' ';

        std::cout << '\n';
    }

public:
    RatNums();
    RatNums(const float*, const short);
    RatNums &operator=(const RatNums &);
    ~RatNums();

    float *getArr() const;
    short getSize() const;

    void setArrElemByElem(const float, const short);
    void setSize(const short);

    void showValueByIndex(const short);
    short len();
    void printSet() const;

    void addElemByIndex(const short,const float);
    void removeElemByIndex(const short);
};

RatNums::RatNums() : size(0) {
    this->arr = new float[1];
    this->arr[0] = 0;
}

RatNums::RatNums(const float *arr, const short size) {
    if(!this->validSize(size))
        this->size = MAX_SIZE;

    this->size = size;

    this->arr = new float[this->size];
    for(short i = 0; i < this->size; i++)
        this->arr[i] = arr[i];
}

RatNums &RatNums::operator=(const RatNums &other) {
    if(this != &other)
        this->copyFrom(other);

    return *this;
}

RatNums::~RatNums() {
    this->deallocate();
}

void RatNums::setSize(const short num) {
    if(num < 0)
        this->size = 0;

    this->size = num;
}

void RatNums::setArrElemByElem(const float value, const short index) {
    this->arr[index] = value;
}

short RatNums::getSize() const {
    return this->size;
}

float *RatNums::getArr() const {
    return this->arr;
}

void RatNums::showValueByIndex(const short num) {
    if(!this->validIndex(num))
        return;

    std::cout << this->arr[num] << '\n';
}

short RatNums::len() {
    return this->size;
}

void RatNums::printSet() const {
    this->print();
}

void RatNums::addElemByIndex(const short index, const float value) {
    if(this->fullCap())
        return;

    if(!this->validIndex(index))
        return;

    if(this->empty())
        this->arr[0] = value;

    RatNums temp = *this;
    this->deallocate();

    this->size++;
    this->arr = new float[this->size];

    for(short i = 0; i < index; i++)
        this->arr[i] = temp.arr[i];

    this->arr[index] = value;
    short i = index + 1;

    while(i < this->size) {
        this->arr[i] = temp.arr[i - 1];
        i++;
    }
}

void RatNums::removeElemByIndex(const short index) {
    if(this->empty())
        return;

    for(short i = index; i < this->size - 1; i++)
        this->arr[i] = this->arr[i + 1];

    this->size--;
}

void UnionSets(const RatNums &arr1, const RatNums &arr2) {
    RatNums set;
    set.setSize(arr1.getSize() + arr2.getSize());

    short i = 0;
    while(i < arr1.getSize()) {
        set.setArrElemByElem(arr1.getArr()[i], i);
        i++;
    }

    for(short j = 0; j < arr2.getSize(); j++) {
        set.setArrElemByElem(arr2.getArr()[j], i);
        i++;
    }

    set.printSet();
}

int main() {
    float arr1[] = {1.1, 2.2, 3.3};
    RatNums set1(arr1, 3);

    float arr2[] = {4.4, 5.5, 6.6};
    RatNums set2(arr2, 3);

    UnionSets(set1, set2);

    std::cout << "Element at index 1: ";
    set1.showValueByIndex(1);

    set1.removeElemByIndex(1);

    std::cout << "Remaining elements: ";
    set1.printSet();
}
