//Да се реализира клас Стек<Т>, реализиращ стек с елементи от тип Т
#include <iostream>

const std::size_t MaxStack = 100;
const std::size_t FullStack = MaxStack;
int EmptyStack = -1;

template <class T>
class Stack
{
    private:
        T stack[MaxStack];
        int top;

        void copyFrom(const Stack &other)
        {
            for (std::size_t i = 0; i < other.top; i++)
                this->stack[i] = other.stack[i];

            this->top = other.top;
        }

    public:     
        Stack();
        
        Stack &operator=(const Stack<T> &);
        
        void insert();
        bool empty() const;
        bool full() const;
        void push(T symbol);
        T pop();
        void print();
};

template<class T>
Stack<T>::Stack() : top(EmptyStack) {}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other)
{
    if (this != &other)
        copyFrom(other);

    return *this;
}

// template <class T>
// void Stack<T>::insert()
// {
//     int size = 0;

//     std::cout << "[ insert function genereted ]\n";
//     do {
//         std::cout << "> size of your stack: ";
//         std::cin >> size;
//     } while (size < 0 || MaxStack < size);

//     for (std::size_t i = 0; i < size; i++)
//         std::cin >> stack[i];
    
//     std::cout << '\n';
// }

template <class T>
bool Stack<T>::empty() const {
    return top == EmptyStack;
}

template <class T>
bool Stack<T>::full() const {
    return top == FullStack - 1;
}

template <class T>
void Stack<T>::push(T symbol)
{
    if (!full())
        stack[++top] = symbol;

    else 
        std::cout << "[ stack already full ]\n";
}

template <class T>
T Stack<T>::pop() 
{
    if (empty())
    {
        std::cout << "[ stack's empty ]\n";
        return 0; 
    }

    else
        return stack[top--];
}

template <class T>
void Stack<T>::print()
{
    for (std::size_t i = 0; i <= this->top; i++)
        std::cout << stack[i] << "  ";

    std::cout << '\n';
}

int main ()
{
    std::cout << '\n';
    std::cout << "------------------------------\n";

    Stack<char> first;
    first.push('M');
    first.push('a');
    first.push('r');
    first.push('t');
    first.push('i');
    first.push('!');
    first.print();

    first.pop();
    first.print();
}
//✅