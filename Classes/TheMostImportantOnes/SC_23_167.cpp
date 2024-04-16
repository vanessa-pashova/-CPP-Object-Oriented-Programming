#include <iostream>
const short MAX_SIZE = 15;

class Bag {
private:
    short arr[MAX_SIZE];
    short size;

    bool isSmallerThanMaxSize() {
        return this->size < MAX_SIZE;
    }

    bool isEmpty() {
        return this->size == 0;
    }

    bool existingElement(short x) {
        bool flag = false;
        for(short i = 0; i < this->size; i++) {
            if(this->arr[i] == x) {
                flag = true;
                break;
            }
        }

        return flag;
    };

    void printBag() const {
        for(short i = 0; i < this->size; i++)
            std::cout << this->arr[i] << ' ';
    }

public:
    Bag();

    void creation(const short*, const short);
    void addElement(short);
    void removeElement(short);
    short countOfElements();

    void intersection(const Bag &);
    void unionSet(const Bag &);
    void substraction(const Bag &);
    void symetricSubstraction(const Bag &);
    void print() const;
};

Bag::Bag() : size(1) {
    this->arr[0] = 0;
}

void Bag::creation(const short *arr, const short size) {
    if(size > MAX_SIZE)
        this->size = MAX_SIZE;

    else this->size = size;

    for(short i = 0; i < this->size; i++)
        this->arr[i] = arr[i];
}

void Bag::addElement(short num) {
    if(this->isSmallerThanMaxSize()) {
        this->size++;
        this->arr[this->size--] = num;
    }

    else std::cout << "------------- task failed [not enough space] -------------\n";
}

void Bag::removeElement(short num) {
    if(this->isEmpty())
        std::cout << "------------- task failed [arr is empty] -------------\n";

    else {
        if(!this->existingElement(num))
            std::cout << "------------- task failed [element does not exists in the arr] -------------\n";

        this->size--;
        for(short i = 0; i < this->size; i++) {
            if(this->arr[i] == num)
                this->arr[i] = this->arr[i++];
        }
    }
}

short Bag::countOfElements() {
    return this->size;
}

void Bag::intersection(const Bag &other) {
    for(short i = 0; i < this->size; i++) {
        for(short j = 0; j < other.size; j++) {
            if(this->arr[i] == other.arr[j])
                std::cout << this->arr[i] << ' ';
        }
    }
}

void Bag::unionSet(const Bag &other) {
    short limit = 0;
    for(short i = 0; i < this->size; i++) {
        std::cout << this->arr[i] << ' ';
        limit++;
    }

    short i = 0;
    while(i < other.size && limit < MAX_SIZE) {
        std::cout << other.arr[i] << ' ';
        i++;
    }
}

void Bag::substraction(const Bag &other) {
    for(short i = 0; i < this->size; i++) {
        bool found = false;

        for(short j = 0; j < other.size; j++) {
            if(this->arr[i] == other.arr[j]) {
                found = true;
                break;
            }
        }

        if(!found)
            std::cout << this->arr[i] << ' ';
    }
}

void Bag::symetricSubstraction(const Bag &other) {
    for(short i = 0; i < this->size; i++) {
        bool found = false;

        for(short j = 0; j < other.size; j++) {
            if(this->arr[i] == other.arr[j]) {
                found = true;
                break;
            }
        }

        if(!found)
            std::cout << this->arr[i] << ' ';
    }

    for(short j = 0; j < other.size; j++) {
        bool found = false;

        for(short i = 0; i < this->size; i++) {
            if(other.arr[j] == this->arr[i]) {
                found = true;
                break;
            }
        }

        if(!found)
            std::cout << other.arr[j] << ' ';
    }
}

void Bag::print() const {
    this->printBag();
}

int main() {
    short arr1[] = {1, 2, 3, 4, 5};
    short arr2[] = {4, 5, 6, 7, 8};

    Bag bag1, bag2;

    bag1.creation(arr1, sizeof(arr1) / sizeof(arr1[0]));
    bag2.creation(arr2, sizeof(arr2) / sizeof(arr2[0]));

    std::cout << "Bag 1: ";
    bag1.print();
    std::cout << std::endl;

    std::cout << "Bag 2: ";
    bag2.print();
    std::cout << std::endl;

    std::cout << "Intersection of Bag 1 and Bag 2: ";
    bag1.intersection(bag2);
    std::cout << std::endl;

    std::cout << "Union of Bag 1 and Bag 2: ";
    bag1.unionSet(bag2);
    std::cout << std::endl;

    std::cout << "Subtraction of Bag 1 from Bag 2: ";
    bag1.substraction(bag2);
    std::cout << std::endl;

    std::cout << "Symmetric Subtraction of Bag 1 and Bag 2: ";
    bag1.symetricSubstraction(bag2);
    std::cout << std::endl;

    return 0;
}
