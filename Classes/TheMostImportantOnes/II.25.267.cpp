//Сортирана във възходящ ред съвкупност е наредена. Всеки елемент от редицата има пореден номер, започвайки от 0. Достъпът е пряк и се осъществява чрез индекс.
//Да се дефинира клас Сортиран, който реализира сортирана редица във възходящ ред и методи:
// - създаване на сортирана редица и извеждане
// - включване на нов елемент в редицата
// - намиране на сечението на две сортирани редици
// - намиране на обединението на две сортирани редици
// - намиране на разликата на две сортирани редици

#include <iostream>

class Sorted
{
    private:
        int *arr;
        std::size_t size;

        void deallocate () {
            delete [] this->arr;
        }

        void selectingSort ()
        {
            int k, min;
            for (std::size_t i = 0; i < this->size - 1; i++)
            {
                k = i; 
                min = this->arr[k];

                for (std::size_t j = i + 1; j < this->size; j++)
                {
                    if (this->arr[j] < min)
                    {
                        k = j;
                        min = arr[k];
                    }

                }

                this->arr[k] = this->arr[i];
                this->arr[i] = min;
            }
        }

        void copyFrom(const Sorted &other)
        {
            this->size = other.size;
            this->arr = new int[this->size + 1];

            for (std::size_t i = 0; i < this->size; i++)
                this->arr[i] = other.arr[i];
        }

    public:
        Sorted();
        //Sorted(const Sorted &);
        ~Sorted();

        Sorted &operator=(const Sorted &);

        int *getArray() const;
        std::size_t getSize() const;

        void creation();
        void print();
        void add(int);
        void intersection(const Sorted &);
        void union_(const Sorted &);
        void substraction(const Sorted &);
};

Sorted::Sorted() : size(1)
{
    this->arr = new int[size];
    this->arr[0] = '\0';
}

Sorted::~Sorted() {
    this->deallocate();
}

Sorted &Sorted::operator=(const Sorted &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }

    return *this;
}

int *Sorted::getArray() const {
    return this->arr;
}
// Getter за размера на масива
std::size_t Sorted::getSize() const {
    return this->size;
}

void Sorted::creation()
{
    int count;
    std::cout << "[ creation genereted; how many elements you'll create ]\n> ";
    std::cin >> count;

    this->size = count;
    this->arr = new int[this->size + 1];

    for (std::size_t i = 0; i < size; i++)
        std::cin >> this->arr[i];

    std::cout << '\n';
}

void Sorted::print()
{
    selectingSort();

    for (std::size_t i = 0; i < this->size - 1; i++)
        std::cout << this->arr[i] << ", ";

    std::cout << this->arr[this->size - 1] << "\n\n";
}

void Sorted::add(int num)
{
    Sorted temp;
    temp.size = this->size;
    temp.arr = new int[temp.size];

    for (std::size_t i = 0; i < temp.size; i++)
        temp.arr[i] = this->arr[i];

    this->deallocate();

    this->size += 1;
    this->arr = new int[this->size];
    
    for(std::size_t i = 0; i < this->size - 1; i++)
        this->arr[i] = temp.arr[i];

    this->arr[this->size - 1] = num;

    this->selectingSort();
    this->print();
}

void Sorted::intersection(const Sorted &obj)
{
    std::cout << "[ Intersection ]\n> ";
    for (std::size_t i = 0; i < this->size; i++)
    {
        for (std::size_t j = 0; j < obj.size; j++)
        {
            if (this->arr[i] == obj.arr[j])
            {
                std::cout << this->arr[i] << "  ";
                break;
            }
        }
    }
    std::cout << "\n\n";
}

void Sorted::union_(const Sorted &obj)
{
    std::cout << "[ Union ]\n> ";
    for (std::size_t i = 0; i < this->size; i++)
        std::cout << this->arr[i] << "  ";

    for (std::size_t i = 0; i < obj.size; i++)
    {
        bool found = false;
        for (std::size_t j = 0; j < this->size; j++)
        {
            if (obj.arr[i] == this->arr[j])
            {
                found = true;
                break;
            }
        }
        
        if(!found)
            std::cout << obj.arr[i] << "  ";
    }

    std::cout << "\n\n";
}

void Sorted::substraction(const Sorted &obj)
{
    Sorted temp;
    temp.size = 0;
    temp.arr = new int[this->size + 1];

    for (int i = 0; i < this->size; i++) 
    {
        bool found = false;
        for (int j = 0; j < obj.size; j++) 
        {
            if (this->arr[i] == obj.arr[j]) 
            {
                found = true;
                break;
            }
        }

        if (!found) 
        {
            temp.arr[i] = this->arr[i];
            temp.size++;
        }
    }

    temp.selectingSort();
    temp.print();
}

int main ()
{
    std::cout << '\n';
    std::cout << "-----------------------\n";

    Sorted a, b;
    a.creation();
    a.print();
    a.add(3);

    b.creation();
    a.intersection(b);
    a.union_(b);
    a.substraction(b);
}
//✅

