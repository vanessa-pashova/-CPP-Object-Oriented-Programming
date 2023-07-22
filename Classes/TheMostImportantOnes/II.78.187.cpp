//Множество е ненаредена съвкупност от 0 или повече елементи, която не съдържа дублиращи се елементи. 
//Да се дефинира шаблон на клас Сет, койот реализира множество от елементи тип Т. Шаблонът да притежава методи за:
// - създаване на множество с елементи от тип Т

// - включване на елемент
// - изключване на нов елемент
//----------------------------------------------------------------------
// - намиране на сечението на две множества
// - намиране на обединението на две множества
// - намиране на разликата на две множества
#include <iostream>
const std::size_t MaxSize = 32;

template <class T>
class Set
{
    private:
        T *arr;
        std::size_t size;

        void copyFrom(const Set &other)
        {
            this->size = other.size;
            this->arr = new T[this->size];

            for (std::size_t i = 0; i < this->size; i++)
                this->arr[i] = other.arr[i];
        }

        void deallocate() {
            delete [] this->arr;
        }

    public:
        Set();
        ~Set();

        Set &operator=(const Set &);

        void creation();
        void print();
        void count();

        Set &operator+(T);
        Set operator-(T);
        
        Set operator^(const Set &) const;
        Set operator+(const Set &) const;
        Set operator-(const Set &) const;
};

template <class T>
Set<T>::Set() : size(0)
{
    this->arr = new T[1];
    this->arr[0] = '\0';
}

template <class T>
Set<T>::~Set() {
    this->deallocate();
}

template <class T>
Set<T> &Set<T>::operator=(const Set &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }

    return *this;
}

template <class T>
void Set<T>::creation()
{
    int count = 0;
    do {
        std::cout << "[ insert how many elements you'll insert ]\n> ";
        std::cin >> count;
        std::cout << '\n';
    } while (count < 0 || MaxSize < count);

    this->size = count;
    this->arr = new T[this->size];

    std::cout << "[ insert value for each element ]\n";
    for (std::size_t i = 0; i < this->size; i++)
        std::cin >> this->arr[i];

    std::cout << '\n';
}

template <class T>
void Set<T>::print()
{
    for (std::size_t i = 0; i < this->size - 1; i++)
        std::cout << this->arr[i] << ", ";

    std::cout << this->arr[this->size - 1] << "\n\n";
}

template <class T>
Set<T> &Set<T>::operator+(T element)
{
    this->size++;
    T* tempArr = new T[this->size];

    for (std::size_t i = 0; i < this->size - 1; i++)
        tempArr[i] = this->arr[i];

    tempArr[this->size - 1] = element;
    
    delete[] this->arr;
    this->arr = tempArr;

    return *this;
}

template <class T>
Set<T> Set<T>::operator-(T element)
{
    if (this->size == 0)
    {
        std::cout << "[ array already empty ]\n";
        exit(1);
    }

    bool found = false;
    for (std::size_t i = 0; i < this->size; i++)
    {
        if (element == this->arr[i])
        {
            found = true;
            --this->size;

            for(std::size_t j = i; j < this->size; j++)
                this->arr[j] = this->arr[j + 1];
        }
    }

    if (!found)
        std::cout << "[ the element does not exist in the set ]\n";

    return *this;
}
//това тук не работи съвсем добре, но работи поне

template <class T>
Set<T> Set<T>::operator^(const Set &other) const 
{
    Set<T> temp;
    temp.size = 0;
    
    // Алокираме памет само за толкова елементи, колкото е възможно максималното сечение
    temp.arr = new T[this->size < other.size ? this->size : other.size];

    for (std::size_t i = 0; i < this->size; i++)
    {
        for (std::size_t j = 0; j < other.size; j++)
        {
            if (this->arr[i] == other.arr[j])
            {
                // Записваме елементите на различни места в масива
                temp.arr[temp.size] = this->arr[i];
                temp.size++;
            }
        }
    }

    return temp;
}

template <class T>
Set<T> Set<T>::operator+(const Set &other) const
{
    Set<T> temp;
    temp.size = this->size + other.size - 2;
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

template <class T>
Set<T> Set<T>::operator-(const Set &other) const
{
    Set<T> temp;
    temp.size = this->size;
    temp.arr = new T[temp.size];

    int index = 0;
    for (std::size_t i = 0; i < this->size; i++)
    {
        bool found = false;
        for (std::size_t j = 0; j < other.size; j++)
        {
            if (this->arr[i] == other.arr[i])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            temp.arr[index] = this->arr[i];
            index++;
        }
    }

    temp.size = index;
    return temp;
}
 
int main ()
{
    std::cout << '\n';
    std::cout << "--------------------------------------\n";

    Set<int> a;
    a.creation();
    a.print();

    Set<int> b = a - 4;
    b.print();
    a.print(); // Тук a ще запази оригиналното си състояние

    Set<int> c, d, e;
    c.creation();
    d.creation();
    e = c ^ d;
    e.print();

    Set<int> f, g, h;
    f.creation();
    g.creation();
    h = f - g;
    h.print();

    Set<int> j, k, l;
    j.creation();
    k.creation();
    l = j - k;
    l.print();
}
//✅
