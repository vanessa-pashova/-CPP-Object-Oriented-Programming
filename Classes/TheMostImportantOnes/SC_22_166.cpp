#include <iostream>
const short MAX_SIZE = 15;

class Set {
private:
    short arr[MAX_SIZE];
    short size;

    void copyFrom(const Set &other) {
        this->size = other.size;

        for(short i = 0; i < this->size; i++)
            this->arr[i] = other.arr[i];
    }

    bool checkSize() {
        return this->size < MAX_SIZE;
    }

    bool checkIfExists(short x) {
        bool found = false;
        for(short i = 0; i < this->size; i++) {
            if(this->arr[i] == x) {
                found = true;
                break;
            }
        }

        return found;
    }

    bool checkSubstractionSize(const Set &other) {
        return this->size >= other.size;
    }

    void sort() {
        for (short i = 0; i < this->size - 1; i++) {
            short minIndex = i;

            for (short j = i + 1; j < this->size; j++) {
                if (this->arr[j] < this->arr[minIndex])
                    minIndex = j;
            }

            std::swap(this->arr[i], this->arr[minIndex]);
        }
    }

public:
    Set();
    Set(const short *,const short);
    Set(const Set &);
//    Set &operator=(const Set &);

    void addElement(short);
    void removeElemnt(short);
    short countOfElements();
    void intersection(const Set &);
    void unionSets(const Set &);
    void substraction(const Set &);
    void symetricSubstracion(const Set &);
    void print() const;
};

Set::Set() : size(0) {
    this->arr[0] = '\0';
}

Set::Set(const short *arr,const short len) {
    if(len > MAX_SIZE)
        this->size = MAX_SIZE;

    else
        this->size = len;

    for(short i = 0; i < this->size; i++)
        this->arr[i] = arr[i];
}

Set::Set(const Set &other) {
    if(this != &other)
        this->copyFrom(other);
}

//Set &Set::operator=(const Set &other) {
//    if(this != &other)
//        this->copyFrom(other);
//
//    return *this;
//}

void Set::addElement(short num) {
    if(this->checkSize()) {
        this->size++;
        this->arr[this->size-1] = num;
    }

    else std::cout << "----------- task failed [no memory left] -----------\n";
}

void Set::removeElemnt(short num) {
    if(this->checkIfExists(num)) {
        this->size--;
        short i = 0;

        while (this->arr[i] != num)
            i++;

        while(this->arr[i] != '\0')
            this->arr[i] = this->arr[i + 1];
    }

    else std::cout << "----------- task failed [element not found] -----------\n";
}

short Set::countOfElements() {
    this->checkSize();
}

void Set::intersection(const Set &other) {
    for(short i = 0; i < this->size; i++) {
        for(short j = 0; j < other.size; j++) {
            if(this->arr[i] == other.arr[j]) {
                std::cout << this->arr[i] << " ";
                break;
            }
        }
    }
}

void Set::unionSets(const Set &other) {
    if (this->size + other.size <= MAX_SIZE) {

        short index = 0;
        while (index < this->size) {
            std::cout << this->arr[index] << " ";
            index++;
        }

        for(short i = 0; i < other.size; i++) {
            bool flag = false;

            for(short j = 0; j < this->size; j++) {
                if(other.arr[i] == this->arr[j]) {
                    flag = true;
                    break;
                }
            }

            if(!flag)
                std::cout << other.arr[i] << " ";
        }
    }
}

void Set::substraction(const Set &other) {
    if(this->checkSubstractionSize(other)) {

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

    else std::cout << "----------- task failed [second set has greater size - not allowed] -----------\n";
}

void Set::symetricSubstracion(const Set &other) {
    Set newSet;

    for (short i = 0; i < this->size; i++) {
        bool found = false;

        for (short j = 0; j < other.size; j++) {
            if (this->arr[i] == other.arr[j]) {
                found = true;
                break;
            }
        }

        if (!found)
            newSet.addElement(this->arr[i]);
    }

    for (short i = 0; i < other.size; i++) {
        bool found = false;

        for (short j = 0; j < this->size; j++) {
            if (other.arr[i] == this->arr[j]) {
                found = true;
                break;
            }
        }

        if (!found)
            newSet.addElement(other.arr[i]);
    }

//    newSet.sort();
    newSet.print();
}


void Set::print() const {
    std::cout << "[ Size " << this->size << " ]\n[ Elements ";
    for(short i = 0; i < this->size; i++)
        std::cout << this->arr[i] << " ";
    std::cout << " ]\n";
}

int main() {
    short arr1[] = {1, 2, 3, 4, 5};
    short arr2[] = {4, 5, 6, 7, 8};
    short arr3[] = {-2, -1, 0, 1, 2};

    Set set1(arr1, 5);
    Set set2(arr2, 5);
    Set set3(arr3, 5);

    std::cout << "Set 1:\n";
    set1.print();

    std::cout << "\nSet 2:\n";
    set2.print();

    set1.addElement(6);
    std::cout << "\nSet 1 after adding element:\n";
    set1.print();

    set2.removeElemnt(8);
    std::cout << "\nSet 2 after removing element:\n";
    set2.print();

    set2.addElement(10);
    set2.addElement(11);
    set2.addElement(12);
    std::cout << "\nSet 2 after adding element:\n";
    set2.print();

    std::cout << "\nIntersection of Set 1 and Set 2:\n";
    set1.intersection(set2);

    std::cout << "\n\nUnion of Set 1 and Set 2:\n";
    set1.unionSets(set2);

    std::cout << "\n\nDifference between Set 1 and Set 3:\n";
    set1.substraction(set3);

    std::cout << "\n\nSymmetric difference between Set 1 and Set 2:\n";
    set1.symetricSubstracion(set3);

    return 0;
}
