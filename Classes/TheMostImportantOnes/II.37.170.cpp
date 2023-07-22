//Да се напише програма, която заделя памет в хийпа за масив от n (1 <= n <= 20) указателя към стекове от символи. Програмата да сортира в низходящ ред елементите
//на масива отновно дължините (броя на елементите) на стековете
#include <iostream>
const std::size_t MaxStack = 100;
const std::size_t MaxArray = 20;

class OneStack
{
    private:
        char items[MaxStack];
        std::size_t top;

        void erase() 
        {
            for (std::size_t i = 0; i < this->top; i++) 
                this->items[i] = ' ';
        }

        void copyFrom(const OneStack &other)
        {
            this->top = other.top;
            strcpy(this->items, other.items);
        }

    public:
        OneStack();
        OneStack &operator=(const OneStack &);

        std::size_t getSize () const;

        void input();
        void print();
};

OneStack::OneStack() : top(0) 
{
    this->items[0] = '\0';
}

OneStack &OneStack::operator=(const OneStack &other)
{
    if (this != &other)
    {
        this->erase();
        this->copyFrom(other);
    }

    return *this;
}

std::size_t OneStack::getSize () const {
    return this->top;
}

void OneStack::input()
{
    char buffer[MaxStack];
    std::cin.getline(buffer, MaxStack);

    this->top = strlen(buffer);
    strcpy(this->items, buffer);

    std::cout << '\n';
}

void OneStack::print() 
{
    for (std::size_t i = 0; i < this->top; i++)
        std::cout << this->items[i] << " ";

    std::cout << '\n';
}

void selectionSort(OneStack **arr, std::size_t size)
{
    for (std::size_t i = 0; i < size - 1; i++)
    {
        std::size_t minIndex = i;
        for (std::size_t j = i + 1; j < size; j++)
        {
            if (arr[j]->getSize() > arr[minIndex]->getSize())
                minIndex = j;
        }

        if (minIndex != i)
            std::swap(arr[i], arr[minIndex]);
    }
}

int main ()
{
    std::cout << '\n';
    std::cout << "--------------------\n";

    // OneStack f;
    // f.input();
    // f.print();

    int count = 0;
    do 
    {
        std::cout << "[ insert how many elements between 1 and 20 ]\n";
        std::cin >> count;
    } while (count < 1 || 20 < count);

    OneStack *arr[count];

    for (std::size_t i = 0; i < count; i++)
    {
        arr[i] = new OneStack();
        arr[i]->input();
    }

    for (std::size_t i = 0; i < count; i++)
    {
        selectionSort(arr, count);
        arr[i]->print();
    }
}
//✅