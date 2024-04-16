#include <iostream>

class Student {
private:
    int FN;
    char *firstName;
    char *lastName;
    short term;
    float  credits, gpa;

    void deallocate() {
        delete [] this->firstName;
        delete [] this->lastName;
    }

    void copyFrom(const Student &other) {
        this->deallocate();

        this->firstName = new char[strlen(other.getFirstName()) + 1];
        this->lastName = new char[strlen(other.getLastName()) + 1];

        strcpy(this->firstName, other.firstName);
        strcpy(this->lastName, other.lastName);

        this->FN = other.FN;
        this->term = other.term;
        this->credits = other.credits;
        this->gpa = other.gpa;
    }

public:
    Student();
    Student(const int fn, const char* name, const char* lastName, const short term, const float credits, const float gpa);
    ~Student();
    Student(const Student &);
    Student &operator=(const Student &);

    int getFN() const;
    const char *getFirstName() const;
    const char *getLastName() const;
    short getTerm() const;
    float getCredits() const;
    float getGPA() const;

    bool operator==(const Student &) const;
    bool operator!=(const Student &) const;
    bool operator<(const Student &) const;
    bool operator<=(const Student &) const;
    bool operator>(const Student &) const;
    bool operator>=(const Student &) const;
};

Student::Student() : FN(0), firstName(nullptr), lastName(nullptr), term(0), credits(0), gpa(0) {}

Student::Student(const int fn, const char *name, const char *lastName, const short term, const float credits,
                 const float gpa) {
    if(fn > 10000)
        this->FN = 10000;

    else this->FN = fn;

    this->firstName = new char[strlen(name) + 1];
    this->lastName = new char[strlen(lastName) + 1];

    strcpy(this->firstName, name);
    strcpy(this->lastName, lastName);

    if(term < 0)
        this->term = 1;

    else this->term = term;

    if(credits < 0)
        this->credits = 0;

    this->credits = credits;

    if(gpa < 0)
        this->gpa = 0;

    else this->gpa = gpa;
}

Student::~Student() {
    this->deallocate();
}

Student::Student(const Student &other) {
    if(this != &other)
        this->copyFrom(other);
}

Student &Student::operator=(const Student &other) {
    if(this != &other)
        this->copyFrom(other);

    return *this;
}

int Student::getFN() const {
    return this->FN;
}

const char *Student::getFirstName() const {
    return this->firstName;
}

const char *Student::getLastName() const {
    return this->lastName;
}

short Student::getTerm() const {
    return this->term;
}

float Student::getCredits() const {
    return this->credits;
}

float Student::getGPA() const {
    return this->gpa;
}

bool Student::operator==(const Student &other) const {
    return (strcmp(this->firstName, other.firstName) == 0) && (strcmp(this->lastName, other.lastName) == 0) && (this->FN == other.FN) &&
            (this->term == other.term) && (this->credits == other.credits) && (this->gpa == other.gpa);
}

bool Student::operator!=(const Student &other) const {
    return !operator==(other);
}

bool Student::operator<(const Student &other) const {
    return ((strcmp(this->firstName, other.firstName)) < 0) && ((strcmp(this->lastName, other.lastName)) < 0) && (this->FN < other.FN) &&
            (this->term < other.term) && (this->credits < other.credits) && (this->gpa < other.gpa);
}

bool Student::operator<=(const Student &other) const {
    return ((strcmp(this->firstName, other.firstName)) <= 0) && ((strcmp(this->lastName, other.lastName)) <= 0) && (this->FN <= other.FN) &&
           (this->term <= other.term) && (this->credits <= other.credits) && (this->gpa <= other.gpa);
}

bool Student::operator>(const Student &other) const {
    return ((strcmp(this->firstName, other.firstName)) > 0) && ((strcmp(this->lastName, other.lastName)) > 0) && (this->FN > other.FN) &&
           (this->term > other.term) && (this->credits > other.credits) && (this->gpa > other.gpa);
}

bool Student::operator>=(const Student &other) const {
    return ((strcmp(this->firstName, other.firstName)) >= 0) && ((strcmp(this->lastName, other.lastName)) >= 0) && (this->FN >= other.FN) &&
           (this->term >= other.term) && (this->credits >= other.credits) && (this->gpa >= other.gpa);
}

int main() {
    Student student1(345, "John", "Doe", 2, 60, 4.5);
    Student student2(201, "Alice", "Smith", 3, 45, 3.8);
    Student student3(206, "Bob", "Johnson", 1, 30, 3.2);
    Student student4 = student2;

    std::cout << "Student 1: FN " << student1.getFN() << ", Name: " << student1.getFirstName() << " " << student1.getLastName() << ", Term: " << student1.getTerm() << ", Credits: " << student1.getCredits() << ", GPA: " << student1.getGPA() << std::endl;
    std::cout << "Student 2: FN " << student2.getFN() << ", Name: " << student2.getFirstName() << " " << student2.getLastName() << ", Term: " << student2.getTerm() << ", Credits: " << student2.getCredits() << ", GPA: " << student2.getGPA() << std::endl;
    std::cout << "Student 3: FN " << student3.getFN() << ", Name: " << student3.getFirstName() << " " << student3.getLastName() << ", Term: " << student3.getTerm() << ", Credits: " << student3.getCredits() << ", GPA: " << student3.getGPA() << std::endl;
    std::cout << "Student 4: FN " << student4.getFN() << ", Name: " << student4.getFirstName() << " " << student4.getLastName() << ", Term: " << student4.getTerm() << ", Credits: " << student4.getCredits() << ", GPA: " << student4.getGPA() << std::endl;

    if (student2 == student4)
        std::cout << "Student 2 is equal to Student 4" << std::endl;
    else std::cout << "Student 2 is not equal to Student 4" << std::endl;


    if (student2 != student3)
        std::cout << "Student 2 is not equal to Student 3" << std::endl;

    else std::cout << "Student 2 is equal to Student 3" << std::endl;


    if (student1 < student3)
        std::cout << "Student 1 has fewer credits than Student 3" << std::endl;

    else std::cout << "Student 1 does not have fewer credits than Student 3" << std::endl;

    if (student2 > student3)
        std::cout << "Student 2 has more credits than Student 3" << std::endl;

    else std::cout << "Student 2 does not have more credits than Student 3" << std::endl;

    return 0;
}
