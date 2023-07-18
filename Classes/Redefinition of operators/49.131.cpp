#include <iostream>

class String
{
    private:
        char* string;
        int lenght;

        void deallocate() {
            if (lenght != 0)
                delete [] this->string;
        }

        void copyFrom (const String &other)
        {
            //първо заделяме памет, после копираме
            this->string = new char[other.lenght + 1];
            std::strcpy(this->string, other.string);
            this->lenght = other.lenght;
        }

    public:
        String();
        String(const char *);
        ~String();

        int getLenght () const;
        const char *getString () const;
        
        String &operator= (const String &);
        
        const char *operator=(const char*);

        bool operator==(const String &) const;
        bool operator==(const char*);

        bool operator!=(const String &) const;
        bool operator!=(const char*);

        bool operator<(const String &) const;
        bool operator<(const char*);

        bool operator>(const String &) const;
        bool operator>(const char*);

        bool operator<=(const String &) const;
        bool operator<=(const char*);

        bool operator>=(const String &) const;
        bool operator>=(const char*);

        friend bool operator==(const String &, const char*);
        friend bool operator!=(const String &, const char*);
        friend bool operator>(const String &, const char*);
        friend bool operator<(const String &, const char*);
        friend bool operator<=(const String &, const char*);
        friend bool operator>=(const String &, const char*);

        void print();
};

String::String() : string(nullptr) {}

String::String(const char *string)
{
    if (string)
    {
        lenght = strlen(string);
        this->string = new char[lenght + 1];

        if (!this->string)
        {
            std::cout << "[ memory not correctly allocated ]\n";
            exit(1);
        }

        else 
           strcpy(this->string, string);
    }
}

String::~String() { 
    this->deallocate();
}

int String::getLenght () const {
    return this->lenght;
}

const char *String::getString () const {
    return this->string;
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }

    return *this;
}

const char* String::operator=(const char *str)
{
    if (str)
    {
        if (this->string != str)
        {
            if (this->string)
                this->deallocate();

            this->lenght = strlen(str);
            this->string = new char[this->lenght + 1];

            if (!this->string)
            {
                std::cout << "[ memory allocation problem ]\n";
                exit(1);
            }
            
            strcpy(this->string, str);
        }
    }

    else if (this->string)
    {
        this->deallocate();
        this->string = NULL;
        this->lenght = 0;
    }

    return this->string;
}

bool String::operator==(const String &other) const {
    return !strcmp(this->string, other.string);
}

bool String::operator==(const char *other) {
    return !strcmp(this->string, other);
}

bool String::operator!=(const String &other) const {
    return strcmp(this->string, other.getString()) != 0;
}

bool String::operator!=(const char *other) {
    return strcmp(this->string, other) != 0;
}

bool String::operator<(const String &other) const {
    return strcmp(this->string, other.getString()) < 0;
}

bool String::operator<(const char *other) {
    return strcmp(this->string, other) < 0;
}

bool String::operator>(const String &other) const {
    return strcmp(this->string, other.getString()) > 0;
}

bool String::operator>(const char *other) {
    return strcmp(this->string, other) > 0;
}

bool String::operator<=(const String &other) const {
    return strcmp(this->string, other.getString()) <= 0;
}

bool String::operator<=(const char* other) {
    return strcmp(this->string, other) <= 0;
}

bool String::operator>=(const String &other) const {
    return strcmp(this->string, other.getString()) >= 0;
}

bool String::operator>=(const char *other) {
    return strcmp(this->string, other) >= 0;
}

bool operator==(const String &obj, const char *str) {
    return !strcmp(obj.string, str);
}

bool operator!=(const String &obj, const char *str) {
    return strcmp(obj.string, str) != 0;
}

bool operator<(const String &obj, const char *str) {
    return strcmp(obj.string, str) < 0;
}

bool operator>(const String &obj, const char *str) {
    return strcmp(obj.string, str) > 0;
}

bool operator<=(const String &obj, const char *str) {
    return strcmp(obj.string, str) <= 0;
}

bool operator>=(const String &obj, const char *str) {
    return strcmp(obj.string, str) >= 0;
}

void String::print() {
    std::cout << this->string << "\n\n";
}

int main ()
{
    std::cout << '\n';
    std::cout << "-------------------------------\n";

    String a("Hi "), b;
    b = a;
    b.print();

    b = "Martin and ";
    b.print();

    char str[] = "Vanesa";
    b = str;
    b.print();

    String c("Dani"), d("Dani"), g("Rositsa");

    c.print();
    d.print();
    if (c == d)
        std::cout << "[ these two names are equal ]\n\n";

    d.print();
    g.print();

    if (g < d)
        std::cout << "[ first name is longer than the second one ]\n";

    else 
        std::cout << "[ second name is greater than the first one ]\n";
}
