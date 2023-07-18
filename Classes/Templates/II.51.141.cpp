//Да се дефинира шаблон на клас Низ<Т>, реализиращ масив с елементи от тип Т
#include <iostream>
const std::size_t MAX_SIZE = 100;

template <class T>
class Array
{
    private:
        T *array;
        std::size_t size;

        void deallocate () {
            delete [] array;
        }

        void copyFrom (const Array &other)
        {
            this->array = new T [other.size + 1];
            strcpy (this->array, other.array);
            this->size = other.size;
        }

    public:
        Array(int);
        ~Array();

        int getSize () const;
       
        Array &operator=(const Array<T> &);
        T &operator[] (int);

        void insert();
        void print();
};

template <class T>
Array<T>::Array(int n)
{
    if (n > MAX_SIZE || n < 0)
    {
        std::cout << "[ size out of the limit ]\n";
        exit(1);
    }

    else 
    {
        this->size = n;
        this->array = new T [n];

        if (!this->array)
        {
            std::cout << "[ memory allocation problem ]\n";
            exit(1);
        }
    }
}

template <class T>
Array<T>::~Array() {
    this->deallocate();
}

template <class T>
int Array<T>::getSize() const {
    return this->size;
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }

    return *this;
}

template <class T>
T &Array<T>::operator[] (int sub)
{
    if (sub < 0 || sub >= MAX_SIZE)
    {
        std::cout << "[ index out of limit ]\n";
        exit(1);
    }

    else 
        return array[sub];
} 

template <class T>
void Array<T>::insert() 
{
    std::cout << "[ input function genereted ]\n";
        
    for (std::size_t i = 0; i < this->size; i++)
    {
        std::cout << "> ";
        std::cin >> array[i];
    }

    std::cout << '\n';
}

template <class T>
void Array<T>::print() 
{
    std::cout << "[ print function genereted ]\n";
        
    for (std::size_t i = 0; i < this->size; i++)
        std::cout << this->array[i] << "  ";

    std::cout << "\n\n";
}

int main() 
{
    std::cout << '\n';
    std::cout << "--------------------------------\n";

    int size1 = 0;
    std::cout << "[ insert size1 for the first int arr ]\n> size1: ";
    std::cin >> size1;

    Array<int> first(size1);
    first.insert();
    first.print();

    int size2 = 0;
    std::cout << "[ insert size1 for the first int arr ]\n> size2: ";
    std::cin >> size2;

    Array<char> second(size2);
    second.insert();
    second.print();
}
//✅

