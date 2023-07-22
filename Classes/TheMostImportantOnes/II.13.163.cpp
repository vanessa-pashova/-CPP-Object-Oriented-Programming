//Да се дефинира клас Монотон, който проверява дали елементите на непраза редица от цели числа са строго монотонно намаляващи. 
//Създаването на редицата да става чрез подходящ конструктор

#include <iostream>

class Monotone
{
    private:    
        int *arr;
        std::size_t size;

        void deallocate() {
            delete [] this->arr;
        }
    
    public:
        Monotone();
        ~Monotone();

        void insert();
        void print() const;
        void monotone();
};

Monotone::Monotone() : size(0) {}

Monotone::~Monotone() {
    this->deallocate();
}

void Monotone::insert()
{
    int n = 0;
    std::cout << "[ insert how many elements you'll add ]\n> ";
    std::cin >> n;

    this->size = n;

    this->arr = new int[this->size + 1];
    for (std::size_t i = 0; i < this->size; i++)
    {
        std::cout << "> insert value for element[" << i + 1 << "]: ";
        std::cin >> arr[i];
    }

    std::cout << '\n';
}

void Monotone::print() const {
    for (std::size_t i = 0; i < this->size; i++)
        std::cout << arr[i] << ", ";

    std::cout << '\n';
}

void Monotone::monotone()
{
    bool flag = false;
    int diff = 0;
    for (std::size_t i = 0; i < this->size - 1; i++)
    {
        diff = arr[0] - arr[1];
        if ((arr[i] > arr[i + 1]) && (arr[i] - arr[i + 1] == diff))
        {
            flag = true;
            //std::cout << "[ true ]\n";
        }

        else 
        {
            flag = false;
            //std::cout << "[ false ]\n";
        }
    }

    if (flag == true)
        std::cout << "[ true ]\n";

    else
        std::cout << "[ false ]\n";
}

int main ()
{
    std::cout << '\n';
    std::cout << "-----------------------\n";

    Monotone a;
    a.insert();
    a.print();
    a.monotone();
}
//✅