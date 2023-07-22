//Индексирана съвкупност е наредена съвкупност от елементи от един и същ тип. Всеки елемент на индексирана съвкупност има пореден номер. Номерацията започва
//от 0. Достъпът до елемент е пряк и се осъществява чрез индекс. Да се дефинира клас Индексиран, който да реализира индексирана съвкупност от цели числа и методи:
// - създаване на индексирана съвкупност
// - включване на нов елемент към съвкупността пред и след указан чрез индекс елемент
// - изключване на елемент от съвкупността
// - намиране на сечение и обединение на две съвкупности

#include <iostream>

class Indexed
{
    private:
        int *arr;
        std::size_t size;

        void deallocate() {
            delete [] this->arr;
        }

        void copyFrom(const Indexed &other)
        {
            this->size = other.size;
            this->arr = new int[this->size];
            if (!this->arr)
            {
                std::cout << "[ memory allocation problem ]\n";
                exit(1);
            }

            for (std::size_t i = 0; i < other.size; i++)
                this->arr[i] = other.arr[i];
        }

    public:
        Indexed();
        Indexed(const Indexed &);
        ~Indexed();

        Indexed &operator= (const Indexed &);

        bool validIndex(int);

        void creation();
        void add();
        void remove(int);
        void Intersection(const Indexed &);
        void Union(const Indexed &);
        void print();
};

Indexed::Indexed() : size(1)
{
    this->arr = new int[this->size];
    this->arr[0] = '\0';
}

Indexed::Indexed(const Indexed &other)
{
    this->deallocate();
    this->copyFrom(other);
}

Indexed &Indexed::operator=(const Indexed &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }

    return *this;
}

Indexed::~Indexed() {
    this->deallocate();
}

void Indexed::creation() 
{
    std::cout << "[ creation genereted. insert how many elements you will create ]\n> ";
    int count = 0;
    std::cin >> count;
    this->size = count;

    for (std::size_t i = 0; i < count; i++)
        std::cin >> this->arr[i];

    std::cout << '\n';
}

bool Indexed::validIndex(int x)
{
    int i = 0;
    while (i < this->size - 2 && x != this->arr[i])
        i++;

    if (x == this->arr[i])
        return true;

    else 
        return false;
}

void Indexed::add()
{
    int i = 0;
    std::cout << "[ add function created. tell us the index of the element you want in front of and behind ]\n> ";
    std::cin >> i;

    if(validIndex(i))
    {
        int k = 0, num;
        this->size += 2;

        Indexed temp;  
        temp.size = this->size;
        temp.arr = new int[temp.size + 1];

        for (std::size_t i = 0; i < this->size; i++)
            temp.arr[i] = this->arr[i];

        this->deallocate();
        this->arr = new int[this->size];

        while (k < i)
        {
            this->arr[k] = temp.arr[k];
            k++;
        }

        std::cout << "[ insert your number ]\n> ";
        std::cin >> num;
        this->arr[i] = num;
        this->arr[i + 2] = num;
        this->arr[i + 1] = temp.arr[i];

        k = i + 1;
        while (k < this->size)
        {
            this->arr[k + 2] = temp.arr[k];
            k++;
        }
    }

    else 
    {
        std::cout << "[ your index does not exist ]\n";
        exit(1);
    }
}

void Indexed::remove(int i)
{
    std::cout << "[ remove function genereted ]\n";
    int k, swap = this->arr[i];

    for (k = i; k < this->size; k++)
    {
        this->arr[k] = this->arr[k + 1];
        this->arr[k + 1] = swap;
    }

    this->arr[size--];
}

void Indexed::Intersection(const Indexed &obj)
{
    std::cout << "[ Intersection ]\n> ";
    for (int i = 0; i < this->size; i++) 
    {
        for (int j = 0; j < obj.size; j++) 
        {
            if (this->arr[i] == obj.arr[j]) 
            {
                std::cout << this->arr[i] << " ";
                break;
            }
        }
    }
    std::cout << "\n\n";
}

void Indexed::Union(const Indexed &obj)
{
    std::cout << "[ Union ]\n> ";

    for (int i = 0; i < this->size; i++) 
        std::cout << this->arr[i] << " ";
    
    for (int i = 0; i < obj.size; i++) 
    {
        bool found = false;
        for (int j = 0; j < this->size; j++) 
        {
            if (obj.arr[i] == this->arr[j]) 
            {
                found = true;
                break;
            }
        }

        if (!found) 
            std::cout << obj.arr[i] << " ";
    }

    std::cout << "\n\n";
}

void Indexed::print()
{
    for (std::size_t i = 0; i < this->size - 1; i++)
        std::cout << this->arr[i] << ", ";

    std::cout << this->arr[this->size - 1] << "\n\n";
}

int main ()
{
    std::cout << '\n';
    std::cout << "-------------------------\n";

    Indexed a, b;
    a.creation();
    a.print();
    //a.add();
    //a.print();

    // a.remove(1);
    // a.print();

    b.creation();
    b.print();

    a.Intersection(b);
    a.Union(b);
}