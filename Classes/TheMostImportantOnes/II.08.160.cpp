//Да се дефинира клас речник, който да създава речник между два езика. На всяка дума от един език съответства дума от другия език
//да се реализират методи за:
// - добавяне на двойка думи
// - изтриване на двойка думи
// - търсене на двойка думи
// - метод Превод, който превежда низ чрез заместване на думите в него, които са в речника, със съответните им думи от другия език

#include <iostream>

class Pair
{
    private:
        char *native, *foreign;
        int len1, len2;

        void deallocate() {
            delete [] this->native;
            delete [] this->foreign;
        }

        void copyFrom(const Pair &other)
        {
            this->len1 = strlen(other.native);
            this->len2 = strlen(other.foreign);

            this->native = new char[len1 + 1];
            this->foreign = new char[len2 + 1];

            if (!this->native || !this->foreign)
            {
                std::cout << "[ memoty allocation problem ]\n";
                exit(1);
            }

            strcpy(this->native, other.native);
            strcpy(this->foreign, other.foreign);
        }

    public:
        Pair();
        Pair(const char *, const char *);
        Pair(const Pair &other);
        ~Pair();
        //Pair &operator=(const Pair &);

        const char *getN() const;
        const char *getF() const;

        bool equal (const char *other) const;

        void insert(char *, char*);
        void print() const;
};

Pair::Pair()
{
    this->native = new char[1];
    this->foreign = new char[1];

    this->native[0] = '\0';
    this->foreign[0] = '\0';
}

Pair::Pair(const char *n, const char *f)
{
    this->len1 = strlen(n);
    this->len2 = strlen(f);

    this->native = new char[len1 + 1];
    this->foreign = new char[len2 + 1];

    if (len1 == -1)
    {
        std::cout << "[ no translation of " << f << " ]";
        exit(1);
    }

    else if (len2 == -1)
    {
        std::cout << "[ no translation of " << n << " ]";
        exit(1);
    }

    strcpy(this->native, n);
    strcpy(this->foreign, f);
}

Pair::Pair(const Pair &other)
{
    this->len1 = other.len1;
    this->len2 = other.len2;

    this->native = new char[len1 + 1];
    this->foreign = new char[len2 + 1];

    strcpy(this->native, other.native);
    strcpy(this->foreign, other.foreign);
}

Pair::~Pair() {
    this->deallocate();
}

// Pair &Pair::operator=(const Pair &other)
// {
//     if (this != &other)
//     {
//         this->deallocate();
//         this->copyFrom(other);
//     }

//     return *this;
// }

const char *Pair::getN() const {
    return this->native;
}

const char *Pair::getF() const {
    return this->foreign;
}

bool Pair::equal(const char *other) const {
    return strcmp(this->native, other) == 0 || strcmp(this->foreign, other) == 0;
}

void Pair::insert(char *n, char *f)
{
    strcpy(this->native, n);
    strcpy(this->foreign, f);
}

void Pair::print() const {
    std::cout << this->native << " - " << this->foreign << '\n';
}

class Dictonary
{
    private:
        Pair pairs[100];
        std::size_t count;

    public:  
        Dictonary();
        
        void insert(char *, char *);
        void remove(const char *);
        void translate();
        void print();

        void operator[] (const char *) const;
};

Dictonary::Dictonary() : count(0) {}

void Dictonary::insert(char *n, char *f)
{
    if (count < 100 - 1)
        pairs[count++].insert(n, f);

    else 
        std::cout << "[ error. count should not be greater than limit ]\n";

    std::cout << std::endl;
}

void Dictonary::operator[] (const char *w) const
{
    int index = 0;
    while (index < count)
    {
        if (pairs[index].equal(w))
        {
            pairs[index].print();
            break;

        }

        else 
            index++;

        if (index == count)
            std::cout << "[ " << w << " is not a part of the dictonary ]\n";;
    }
}

void Dictonary::remove(const char *w)
{
    int i = 0;
    while (i < count - 1 && !pairs[i].equal(w))
        i++;

    if (pairs[i].equal(w))
    {
        for (int j = i + 1; j < count; j++)
            pairs[j - 1] = pairs[j];

        count--;
    }

    else    
        std::cout << "[ " << w << " is not a part of the dictonary ]\n";

    std::cout << '\n';
}

void Dictonary::print() {
    for (int i = 0; i < count; i++)
        std::cout << pairs[i].getN() << " - " << pairs[i].getF() << '\n';

    std::cout << '\n';
}

int main()
{
    std::cout << '\n';
    std::cout << "----------------------------\n";

    Pair a("vklyucvam", "einschalten");
    a.print();
    Pair b("izklyucvam", "ausschalten");
    b.print();

    Dictonary c;
    c.insert("baba ", "grossmutter");
    c.insert("bashta", "vater");
    c.insert("mama", "mutti");
    c.insert("sestra", "schwester");
    c.insert("brat", "bruder");
    c.print();

    c["monitor"]; 
    c["mutti"];
    c.remove("vater");
    
    c.print();
}
//✅