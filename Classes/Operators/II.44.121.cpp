//Да се дефинира клас Речник, който създава тълковен речник, реализиран като масив от двойки дума-тълкуване и методи за:
// - създаване на речник
// - извецдане на елементите на речник
// - включвае на нова двойка дума-тълкуване в речник
// - изключвне на двойка дума-тълкуване от речник
// - предефиниране на оператор[], който търси дадена дума в речник и в случай, че я намери, извежда думата и тълкуването ѝ
//Да се дефинира клас ДиктИтер, изпълняващ ф-циите на клас итератор на класа Речник. Да се предефинира операторът () за използването му като итератор
//(да връща указател към елемент на масива, съдържащ речниика)

#include <iostream>
const std::size_t MAX_SIZE_WORD = 15;
const std::size_t MAX_SIZE_INTERPRETATION = 100;
const std::size_t MAXPAIRS = 300;

class Pair 
{
    private:
        char word[MAX_SIZE_WORD + 1];
        char interpretation[MAX_SIZE_INTERPRETATION + 1];

    public:
        Pair ();
        
        void insert(char *, char *);
        void print() const;

        bool equal (const char *other) const;
};

Pair::Pair () 
{
    strcpy (word, "");
    strcpy(interpretation, "");
}

void Pair::insert (char *w, char *i)
{
    strcpy (this->word, w);
    strcpy(this->interpretation, i);

    std::cout << '\n';
}

void Pair::print () const {
    std::cout << "[ print function genereted ] Pair -> " << this->word << " - " << this->interpretation << "\n\n";
}

bool Pair::equal (const char *other) const {
    return strcmp (this->word, other) == 0;
}

class Dictonary
{
    private: 
        friend class DictIter;
        Pair dictonary[MAXPAIRS + 1];
        std::size_t count;

    public:
        Dictonary ();

        void insert(char *, char *);
        void print() const;
        void remove (const char *);

        //оператор [] за търсене на дума в речник
        void operator[] (const char*) const;
};

Dictonary::Dictonary () : count(0) {}

void Dictonary::insert(char *w, char *i)
{
    if (count < MAXPAIRS)
        dictonary[count++].insert(w, i);

    else 
        std::cout << "[ error. count should not be greater than limit ]\n";

    std::cout << std::endl;
}

void Dictonary::print () const
{
    for (std::size_t i = 0; i < count; i++)
    {
        dictonary[i].print();
        std::cout << '\n';
    }
}

void Dictonary::remove (const char *w)
{
    int i = 0;
    while (i < count - 1 && !dictonary[i].equal(w))
        i++;

    if (dictonary[i].equal(w))
    {
        for (std::size_t j = i + 1; j < count; j++)
            dictonary[j - 1] = dictonary[j];
        count--;
    }

    else    
        std::cout << "[ " << w << " is not a part of the dictonary ]\n";

    std::cout << '\n';
}

void Dictonary::operator[] (const char *w) const 
{
    int index = 0;
    while (index < count)
    {
        if (dictonary[index].equal(w))
        {
            dictonary[index].print();
            break;

        }

        else 
            index++;

        if (index == count)
            std::cout << "[ " << w << " is not a part of the dictonary ]\n";;
    }
}

class DictIter
{
    private: 
        int current;
        Dictonary *dict;

    public: 
        DictIter (Dictonary &obj)
        {
            dict = &obj;
            current = 0;
        }

        Pair *operator () ();
};

Pair *DictIter::operator() ()
{
    if (current >= dict->count)
        return NULL;

    return &dict->dictonary[current++];
}

int main ()
{
    std::cout << '\n';
    std::cout << "-------------------------------\n";

    Dictonary d;
    d.insert("pixel", "a pixel is the smallest piece of information in an image");
    d.insert("diode", "a diode is two-terminal device");
    d.insert("recursion", "recursion is a method od defining functions in which the function being defined is applied within");
    d.insert("monitor", "a computer monitor is an electronic device that shows pictures");
    d.insert("computer", "the computer is a machine that manipulates data according to a list of instructions");

    d.print();
    d["monitor"];
    d["diodes"];

    d.remove("diode");
    d.remove("pixel");

    d.print();
}
//✅