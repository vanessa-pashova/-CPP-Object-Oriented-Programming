//Да се дефинира клас, представящ множество от цели числа. Освен методи, реализиращи канонично представяне, да се предефинират операторите:
// + - добавя елемент към множество
// - - изключва елемент от множеството

// + - намира обединение на две множества
// - - намира разликата на две множества
// * - намира сечението на две множества
// () - булев оператор с аргумент цяло число и проверяващ дали даден елемент се съдържа в множеството
// == - сравнява равенство на две множества
// != - сравнява различие на две множества
// < - проверява дали левия аргумент е подмножество на десния аргумент
// > - проверява дали левия аргумент е надмножество на десния аргумент
#include <iostream>

class Array
{
    private:
        int *arr;
        std::size_t size;

        void copyFrom(const Array &other)
        {
            this->size = other.size;
            this->arr = new int[this->size];

            for (std::size_t i = 0; i < this->size; i++)
                this->arr[i] = other.arr[i];
        }

        void deallocate() {
            delete [] this->arr;
        }

    public:
        Array();
        Array(std::size_t);
        Array(const Array &);
        ~Array();

        Array &operator=(const Array &);

        Array operator+(int);
        Array operator-(int);

        Array operator+(const Array &) const;
        Array operator-(const Array &) const;
        Array operator*(const Array &) const;

        bool operator() (int);
        bool operator==(const Array &) const;
        bool operator!=(const Array &) const;
        bool operator<(const Array &) const;
        bool operator>(const Array &) const;

        void print();
};

Array::Array() : size(0) 
{
    this->arr = new int[1];
    this->arr[0] = '\0';
}

Array::Array(std::size_t size)
{
    if (size <= 0)
    {
        std::cout << "[ error. size cannot be smaller than or equal to 0 ]\n[ size will be set to 4 by default in this case ]\n";
        size = 4;
    }

    this->size = size;
    this->arr = new int[this->size];

    std::cout << "[ insert the values of each element (int) ]\n";
    for (std::size_t i = 0; i < this->size; i++)
        std::cin >> this->arr[i];

    std::cout << "\n\n";
}

Array::Array(const Array &other) {
    this->copyFrom(other);
}

Array &Array::operator=(const Array &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }

    return *this;
}

Array::~Array() {
    this->deallocate();
}

Array Array::operator+(int num)
{
    Array temp;
    temp.copyFrom(*this);

    this->deallocate();
    this->size = temp.size + 1;
    this->arr = new int[this->size];

    for (std::size_t i = 0; i < this->size - 1; i++)
        this->arr[i] = temp.arr[i];

    this->arr[this->size - 1] = num;

    return *this;
}

Array Array::operator-(int num) 
{
    if (this->size == 0) 
    {
        std::cout << "[ the array is empty, cannot remove element ]\n";
        exit(1);
    }

    bool found = false;
    for (std::size_t i = 0; i < this->size; i++)
    {
        if (num == this->arr[i]) 
        {
            found = true;
            // Преместваме всички следващи елементи наляво за да запълним празното място
            for (std::size_t j = i; j < this->size - 1; j++) 
                this->arr[j] = this->arr[j + 1];

            this->size--;
            break;
        }
    }

    if (!found)
        std::cout << "[ the element does not exist in the array ]\n";

    return *this;
}

Array Array::operator+(const Array &other) const
{
    Array temp;
    temp.size = this->size + other.size;
    temp.arr = new int[temp.size];

    for (std::size_t i = 0; i < this->size; i++)
        temp.arr[i] = this->arr[i];

    std::size_t plusIndex = this->size;
    for (std::size_t i = 0; i < other.size; i++)
    {
        bool found = false;
        for (std::size_t j = 0; j < this->size; j++)
        {
            if (other.arr[i] == this->arr[j])
            {
                found = true;
                break;
            }
        }
        
        if (!found)
        {
            temp.arr[plusIndex] = other.arr[i];
            plusIndex++;
        }
    }

    return temp;
}

Array Array::operator-(const Array &other) const
{
    Array temp;
    temp.size = this->size;
    temp.arr = new int[temp.size];

    std::size_t minusIndex = 0;
    for (std::size_t i = 0; i < this->size; i++)
    {
        bool found = false;
        for (std::size_t j = 0; j < other.size; j++)
        {
            if (this->arr[i] == other.arr[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            temp.arr[minusIndex] = this->arr[i];
            minusIndex++;
        }
    }

    temp.size = minusIndex;

    return temp;
}

Array Array::operator*(const Array &other) const
{
    Array temp;
    temp.size = 0;
    temp.arr = new int[this->size];

    for (std::size_t i = 0; i < this->size; i++)
    {
        for (std::size_t j = 0; j < other.size; j++)
        {
            if (this->arr[i] == other.arr[j])
            {
                temp.arr[temp.size] = this->arr[i];
                temp.size++;
            }
        }
    }

    return temp;
}

bool Array::operator() (int num)
{
    for (std::size_t i = 0; i < this->size; i++)
    {
        if (this->arr[i] == num)
            return true;
    }

    return false;
}

void Array::print() {
    for (std::size_t i = 0; i < this->size - 1; i++)
        std::cout << this->arr[i] << ", ";

    std::cout << this->arr[this->size - 1] << "\n\n";
}

bool Array::operator==(const Array &other) const {
    return *this == other;
}

bool Array::operator!=(const Array &other) const {
    return !(*this == other);
}

bool Array::operator<(const Array &other) const 
{
    if (this->size > other.size)
        return false;

    for (std::size_t i = 0; i < this->size; i++)
    {
        bool found = false;
        for (std::size_t j = 0; j < other.size; j++)
        {
            if (this->arr[i] == other.arr[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
            return false;
    }

    return true;
}

bool Array::operator>(const Array &other) const 
{
    if (this->size < other.size)
        return false;

    for (std::size_t i = 0; i < other.size; i++)
    {
        bool found = false;
        for (std::size_t j = 0; j < this->size; j++)
        {
            if (other.arr[i] == this->arr[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
            return false;
    }

    return true;
}

int main ()
{
    // std::cout << '\n';
    // std::cout << "------------------\n";

    //Array a(0), 
    // Array c(3); c.print(); 
    // c + 6; c.print(); 
    // c - 5; c.print();

    // Array a(4), b(3);
    // if (a < b)
    //     std::cout << "[ b is greater than a ]\n";
    
    // else if (a > b)
    //     std::cout << "[ a is greater than b ]\n";

    // else if (a == b)
    //     std::cout << "[ both are equal ]\n";

    // else if (a != b)
        // std::cout << "[ they are different ]\n";

    // Array c(4);
    // c = a - b;
    // c = a * b;
    // c.print();
    // if (c(10))
    //     std::cout << "[ exists ]\n";

    // else    
    //     std::cout << "[ does not exist ]\n" ;
}
//