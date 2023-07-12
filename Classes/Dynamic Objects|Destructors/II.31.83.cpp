//Да се дефинира клас БанкАкаунт, определящ банкова сметка на клиент, състояща се от: 
// - име на клиент (символен низ)
// - номер на банковата сметка (символен низ)
// - налична сума (реално число)
//Името на клиента и номерът на банковата му сметка да се реализират в динамична памет, като за всяка от тях се отдели толкова памет, колкото е необходимо.
//Класът да притежава методи:
// - създава банкова сметка
// - извежда на екрана банкова сметка
// - внася и тегли пари от банковата сметка

#include <iostream>
const std::size_t MAX_SIZE = 20;

class BankAccount
{
    private:
        char *name, *iban;
        unsigned int amount;

        void deallocate () {
            delete [] this->name;
            delete [] this->iban;
        }

    public: 
        BankAccount (const char *name, const char *isbn, unsigned int amount);
        ~BankAccount();

        void print_Info ();

        void import ();
        void withdraw ();
};

BankAccount::BankAccount (const char *name, const char *iban, unsigned int amount)
{
    this->name = new char[strlen(name) + 1];
    if (!name)
    {
        std::cout << "[ Error! ]" << std::endl;
        exit(1);
    }
    strcpy(this->name, name);

    this->iban = new char[strlen(iban) + 1];
    if (!iban)
    {
        std::cout << "[ Error! ]" << std::endl;
        exit(1);
    }
    strcpy(this->iban, iban);

    this->amount = amount;
}

BankAccount::~BankAccount () {
    this->deallocate();
}

void BankAccount::print_Info ()
{
    std::cout << "[ Information about Client - " << this->name << " genereted ]" << std::endl;
    std::cout << "> IBAN: " << this->iban << " has amount of " << this->amount << std::endl;
    std::cout << std::endl;
}

void BankAccount::import ()
{
    int sum = 0;
    std::cout << "[ Import function genereted ]\n[ How much will you import? ]\n> ";
    std::cin >> sum;
    this->amount += sum;
    std::cout << "[ Amount of client with IBAN now: " << this->iban << " is: " << this->amount << " ]\n\n";
}

void BankAccount::withdraw ()
{
    int sum = 0;
    std::cout << "[ Withdraw function genereted ]\n[ How much will you need? ]\n> ";
    std::cin >> sum;
    this->amount -= sum;
    std::cout << "[ Amount of client with IBAN now: " << this->iban << " is: " << this->amount << " ]\n\n";
}

int main ()
{
    std::cout << std::endl;
    std::cout << "---------------------------" << std::endl;

    BankAccount first("Vanessa|Pashova", "4mi091065", 10), second("Martin|Doychev", "6mi180103", 345);
    first.print_Info();
    second.print_Info();

    first.import();
    second.withdraw();
}

//✅