#include <iostream>
#include <cstring>

class String {
private:
    char *str;
    std::size_t size;

public:
    String();
    String(const String &);
    String(const char*);
    ~String();

    String &operator=(const String &);
    friend std::ostream &operator<<(std::ostream &, const String &);

    char &at(std::size_t);
    std::size_t len();
    char compareTo(const String &);
    const String &insert(const String &, short);
    const String &remove(short, short);
};

String::String() : str(nullptr), size(0) {}

String::String(const char *s) {
    this->size = strlen(s) + 1;
    this->str = new char[this->size];
    strcpy(this->str, s);
}

String::String(const String &other) : size(other.size), str(new char[other.size]) {
    strcpy(this->str, other.str);
}

String::~String() {
    delete[] this->str;
}

String &String::operator=(const String &other) {
    if (this != &other) {
        delete[] this->str;
        this->size = other.size;
        this->str = new char[other.size];
        strcpy(this->str, other.str);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const String &s) {
    out << s.str;
    return out;
}

char &String::at(std::size_t index) {
    if (index < size)
        return str[index];

    else throw std::out_of_range("Index out of bounds");
}

std::size_t String::len() {
    return size - 1;
}

char String::compareTo(const String &other) {
    if((strcmp(this->str, other.str) == 0) && this->size == other.size)
        return 'y';

    return 'n';
}

const String &String::insert(const String &s, short index) {
    if (index < 0 || index > size)
        throw std::out_of_range("Index out of bounds");

    std::size_t newSize = size + s.size - 1;
    char *temp = new char[newSize];

    strncpy(temp, str, index);
    strncpy(temp + index, s.str, s.size);
    strncpy(temp + index + s.size - 1, str + index, size - index);

    delete[] str;
    str = temp;
    size = newSize;

    return *this;
}

const String &String::remove(short start, short end) {
    if (start < 0 || end >= size || start > end)
        throw std::out_of_range("Invalid indices!");

    std::size_t substringLength = end - start + 1;
    std::size_t newSize = size - substringLength;
    char *temp = new char[newSize];

    strncpy(temp, str, start);
    strncpy(temp + start, str + end + 1, size - end);

    delete[] str;
    str = temp;
    size = newSize;

    return *this;
}

int main() {
    String s1("Hello");
    std::cout << "s1: " << s1 << ", Length: " << s1.len() << std::endl;

    String s2(s1);
    std::cout << "s2: " << s2 << ", Length: " << s2.len() << std::endl;

    String s3;
    s3 = s1;
    std::cout << "s3: " << s3 << ", Length: " << s3.len() << std::endl;

    try {
        std::cout << "Character at index 1 of s1: " << s1.at(1) << std::endl;
        std::cout << "Character at index 6 of s1: " << s1.at(4) << std::endl;
    }

    catch (const std::out_of_range &ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    String s4("baby");
    s1.insert(s4, 5);
    std::cout << "After inserting s4 into s1: " << s1 << ", Length: " << s1.len() << std::endl;
}