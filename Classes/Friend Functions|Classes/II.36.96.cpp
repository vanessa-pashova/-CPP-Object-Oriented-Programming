//Клас итератор е клас, чийто обекти могат да сканират елементите на някаква съвкупност. Да се дефинира клас Итератор на класа Стек, реализиращ стек от символи

#include <iostream>

const std::size_t MAX_SIZE = 100;
const std::size_t FullStack = MAX_SIZE;
const std::size_t EmptyStack = -1;

class StackIterator;

class Stack
{
    private:
        friend StackIterator;
        char items[MAX_SIZE];
        int top;

        void copyFrom (const Stack &other)
        {
            for (std::size_t i = 0; i <= other.top; i++)
                this->items[i] = other.items[i];

            this->top = other.top;
        }

        public:
            Stack();
            Stack &operator= (const Stack &other);
            void push (char c);
            char pop ();
            bool empty () const;
            bool full () const;
            void print ();
};

Stack::Stack () {
    top = EmptyStack;
}

Stack &Stack::operator= (const Stack &other)
{
    if (this != &other)
        copyFrom(other);

    return *this;   
}

bool Stack::empty() const
{
    if (top == EmptyStack)
        return true;

    return false;
}

bool Stack::full () const 
{
    if (top == MAX_SIZE - 1)
        return true;

    else 
        return false;
}

void Stack::push (char c)
{
    std::cout << "[ push function genereted, choose a symbol to add at the end of the array ]\n> ";

    if (!full())
    {
        items[++top] = c;
        std::cout << "[ Your symbol was successflly added ]\n";
    }

    else
        std::cout << "[ not possible - stack's full ]\n";

    std::cout << std::endl;
}

char Stack::pop ()
{
    std::cout << "[ pop function genereted ]\n";
    if (empty())
    {
        std::cout << "[ stack already empty ]\n";
        return '\0';
    }
    
    else 
        std::cout << "[ last symbol deleted from stack ]\n";
        return items[top--];

    std::cout << std::endl;
}

void Stack::print()
{
    for (std::size_t i = top; i >= 0; i--)
        std::cout << items[i] << std::endl;

    std::cout << std::endl;
}


//клас StackIterator, който служи за итериране през обекти от класа Stack
class StackIterator
{
    private:
        Stack *st;      //итератор

    public:
        //Конструкторът StackIterator(Stack &obj) приема референция към обект от класа Stack и инициализира член-данната st с адреса на подадения обект.
        StackIterator (Stack &obj) {
            st = &obj;
        }

        char *getNext ();
};

//Методът getNext() връща указател към следващия елемент в стека. Проверява се дали стекът е празен (има стойност EmptyStack за top), 
//и ако е така, се връща нулев указател (0). В противен случай, се връща указател към елемента на върха на стека (&st->items[st->top]).
char *StackIterator::getNext()
{
    if (st->top == EmptyStack)
        return 0;

    return &st->items[st->top];
}

int main ()
{
    Stack s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');

    Stack t = s;
    s.print();

    StackIterator it(t);        //създаване на итератор it за стека t
    char *ptr = NULL;

    while (ptr = it.getNext())
        std::cout << *ptr << std::endl;
}

//нещо се е скапал