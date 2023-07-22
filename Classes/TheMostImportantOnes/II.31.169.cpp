//Да се напише програма, която създава едномерен масив от стекове с елементи от тип чар и извършва:
// - проверява дали съществуват два еднакви стека
// - намира и изважда броя на елементите на всеки от стековете в масива
// - намира изречението, което се получава, след като се изведат елементите на всеки от стековете
// *** Символите на всеки от стековете образува дума на изречението и между думите има интервал

#include <iostream>
const std::size_t MaxWord = 16;
const std::size_t MaxSentence = 128;

class OneStack
{
    private:  
        char *word;
        std::size_t size;
        friend class MultipleStacks;

        void deallocate() {
            delete [] this->word;
        }

        void copyFrom(const OneStack &other)
        {
            this->size = other.size;
            this->word = new char[this->size];

            strcpy(this->word, other.word);
        }

    public:  
        OneStack();
        OneStack(const OneStack &);
        ~OneStack();
        OneStack &operator=(const OneStack &);

        void deepCopyFrom(const OneStack &);

        const char *getWord () const;
        std::size_t getSize () const;

        bool equal(const OneStack &);

        void insert();
        void printWord();
        void printSize();

        OneStack* clone() const;
};

OneStack::OneStack() : size(0)
{
    this->word = new char[1];
    this->word[0] = '\0';
}

OneStack::OneStack(const OneStack &other)
{
    this->deallocate();
    this->copyFrom(other);
}

OneStack::~OneStack() {
    this->deallocate();
}

OneStack &OneStack::operator=(const OneStack &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }

    return *this;
}

void OneStack::deepCopyFrom(const OneStack &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }
}

const char *OneStack::getWord () const {
    return this->word;
}
 
std::size_t OneStack::getSize () const {
    return this->size;
}

bool OneStack::equal(const OneStack &other) {
    return strcmp(this->word, other.word) == 0;
}

OneStack *OneStack::clone() const 
{
    OneStack* cloned = new OneStack;

    cloned->size = this->size;
    cloned->word = new char[cloned->size + 1];
    strcpy(cloned->word, this->word);

    return cloned;
}

void OneStack::insert()
{
    std::cout << "[ insert function genereted; type the word (up to " << MaxWord - 1 << " characters) ]\n> ";

    char buffer[MaxWord];
    std::cin.getline(buffer, MaxWord);

    this->size = strlen(buffer);
    this->word = new char[this->size + 1];
    strcpy(this->word, buffer);

    std::cout << '\n';
}

void OneStack::printWord()
{
    for (std::size_t i = 0; i < this->size; i++)
        std::cout << this->word[i];

    std::cout << ' ';
}

void OneStack::printSize() {
    std::cout << "> size of the word: " << getSize() << '\n';
}

class MultipleStacks
{
    private:    
        OneStack sentence[MaxSentence];
        std::size_t sizeSentence;

        void destroy() {
            for (std::size_t i = 0; i < MaxSentence; i++)
                this->sentence[i].deallocate();
        }

        void copyFrom(const MultipleStacks &other)
        {
            this->sizeSentence = other.sizeSentence;
            for (std::size_t i = 0; i < this->sizeSentence; i++)
                this->sentence[i] = other.sentence[i];
        }

    public:
        MultipleStacks();
        MultipleStacks &operator=(const MultipleStacks &);

        void input();
        void equalSentences(const MultipleStacks &);
        void getSizes();
        void printSentence();
};

MultipleStacks::MultipleStacks() : sizeSentence(0)
{
    for (std::size_t i = 0; i < MaxSentence; i++)
        this->sentence[i] = OneStack();
}

MultipleStacks &MultipleStacks::operator=(const MultipleStacks &other)
{
    if (this != &other)
    {
        this->destroy();
        this->sizeSentence = other.sizeSentence;

        for (std::size_t i = 0; i < this->sizeSentence; i++)
            this->sentence[i] = *other.sentence[i].clone();
    }
    return *this;
}

void MultipleStacks::input()
{
    std::size_t count = 0;
    std::cout << "[ input function genereted. how many words you will insert ]\n> ";
    do {
        std::cin >> count;
        std::cin.ignore(); // Изчистване на буфера
    } while (count < 0 || MaxSentence <= count);
    
    this->sizeSentence = count;
    std::cout << '\n';

    for (std::size_t i = 0; i < this->sizeSentence; i++)
        this->sentence[i].insert();
}


void MultipleStacks::equalSentences(const MultipleStacks &other)
{
    bool flag = false;
    for (std::size_t i = 0; i < this->sizeSentence; i++)
    {
        if (!this->sentence[i].equal(other.sentence[i]))
            flag = false;
    }

    if (flag == false)
        std::cout << "[ they are NOT the same ]\n";

    else
        std::cout << "[ they are the same ]\n";
}

void MultipleStacks::getSizes()
{
    for (std::size_t i = 0; i < this->sizeSentence; i++)
        this->sentence[i].printSize();

    std::cout << '\n';
}

void MultipleStacks::printSentence()
{
    for (std::size_t i = 0; i < this->sizeSentence; i++)
    {
        if (this->sentence[i].getSize() > 0)
            this->sentence[i].printWord();
    }

    std::cout << "\n\n";
}

int main ()
{
    std::cout << '\n';
    std::cout << "---------------------------\n";

    // OneStack a;
    // a.insert();
    // a.printWord();
    // a.printSize();

    MultipleStacks first, second, third;
    first.input();
    first.printSentence();
    //second.input();

    first.getSizes();
    //second.getSizes();

    third = first;
    //third.printSentence();
    first.equalSentences(third);
    // second.equalSentences(first);
}
//почти, но не напълно