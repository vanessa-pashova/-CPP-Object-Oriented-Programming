#include <iostream>
#include <cstring>

const short NAME_LEN = 20;

class Card {
private:
    char booksName[NAME_LEN], autor[NAME_LEN];
    short stock;

    void copyFrom(const Card &other) {
        strcpy(this->booksName, other.booksName);
        strcpy(this->autor, other.autor);
        this->stock = other.stock;
    }

public:
    Card();
    Card(const char*, const char*, const short);
    Card &operator=(const Card &);

    const char* getBooksName() const;
    const char* getAutor() const;
    const short getStock() const;

    void setStock(short);

    void create();
    void print() const;
};

Card::Card() : stock(0) {
    booksName[0] = '\0';
    autor[0] = '\0';
}

Card::Card(const char *name, const char *autor, const short stock) {
    strcpy(this->booksName, name);
    strcpy(this->autor, autor);
    this->setStock(stock);
}

Card &Card::operator=(const Card &other) {
    if(this != &other)
        this->copyFrom(other);

    return *this;
}

const char* Card::getBooksName() const {
    return this->booksName;
}

const char* Card::getAutor() const {
    return this->autor;
}

const short Card::getStock() const {
    return this->stock;
}

void Card::setStock(short num) {
    if(num < 0)
        this->stock = 0;

    else this->stock = num;
}

void Card::create() {
    char name[NAME_LEN], autor[NAME_LEN];
    short stock;

    std::cout << "--------------------- Creation of Card Genereted Successfully ---------------------\nName -> ";
    std::cin.getline(name, NAME_LEN);
    std::cout << "Autor -> ";
    std::cin.getline(autor, NAME_LEN);
    std::cout << "Available Copies -> ";
    std::cin >> stock;

    *this = Card(name, autor, stock);
    std::cout << "--------------------- Creation of Card Done ---------------------\n";
}

void Card::print() const {
    std::cout << "\n--------------------- Information of Card Genereted Successfully ---------------------\n[ Name " << this->getBooksName() << " ]\n";
    std::cout << "[ Autor " << this->getAutor() << " ]\n[ Available Copies " << this->getStock() << " ]\n";
    std::cout << "--------------------- Information of Card Done ---------------------\n";
}

int main() {
    Card card;
    card.create();
    card.print();
}
//✅
