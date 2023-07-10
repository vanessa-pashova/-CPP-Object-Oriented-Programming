//Стек е редица от 0 или повече елементи, в която е включено и изключването на елемент се осъществява в единия край на редицата, известен като връх на стека. 
//Да се дефинира клас, който създава стек от символи

#include <iostream>

const std::size_t MaxStack = 100;
const std::size_t FullStack = MaxStack;

class Stack 
{
    private:
        char stack[MaxStack];
        int top;

        int lenght (char *stack) const
        {
            int i = 0;
            while (stack[i] != '\0')
                i++;

            return i;
        }

    public: 
        Stack();
        Stack(char *stack);
        Stack &operator= (const Stack &other);

        int setTop();

        void push (char c);
        void pop ();
        bool empty ();
        bool full ();
        void print_Info ();
};

Stack::Stack () 
{
    for (int i = 0; i < MaxStack; i++) {
        this->stack[i] = ' ';
    }

    this->top = 0;
}

Stack::Stack (char *stack) {
    strcpy (this->stack, stack);
    this->top = lenght(stack);
}

Stack& Stack::operator= (const Stack &other)
{
    if (this == &other)
        return *this;

    strcpy (this->stack, other.stack);
    this->top = other.top;
    return *this;
}

int Stack::setTop () 
{
    this->top = lenght(stack);
    return this->top;
}

bool Stack::empty () 
{
    if (top == 0)
        return true;

    return false;
}

bool Stack::full ()
{
    if (top == FullStack)
        return true;

    return false;
}

void Stack::push (char c)
{
    bool flag = this->full();

    if (top < FullStack)
    {
        stack[top] = c;
        top++;
        std::cout << "[ Symbol added to the stack ]" << std::endl;
    }

    else
        flag = true;
}

void Stack::pop () 
{
    bool flag = this->empty();
    if (top > 0)
    {
        top--;
        std::cout << "[ Last element deleted ]" << std::endl;
        print_Info();
    }

    else
    {
        flag = true;
        std::cout << "[ Stack's empty ]" << std::endl;
    }

    std::cout << std::endl;
}

void Stack::print_Info()
{
    std::cout << "[ Info about your stack genereted ]" << std::endl;
    for (std::size_t i = 0; i < this->top; i++)
        std::cout << stack[i] << " - ";
    
    std::cout << "[ Top : " << this->top << " ]" << std::endl;
    std::cout << std::endl;
}

int main ()
{
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;

    Stack first("VANESSA obicha MARTIN"), second, third("idk");
    first.print_Info();
    //first.empty();
    //first.full();

    first.push('!');
    first.print_Info();

    first.pop();

    second = third;
    second.print_Info();
}
//✅