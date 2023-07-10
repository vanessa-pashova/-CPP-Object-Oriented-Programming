//Да се дефинира клас БанкАкаунт, определящ банкова сметка на клиент, съдържаща:
// - име на клиент (символен низ до 32 символа)
// - номер на банковата сметка (символен низ до 15 знака)
// - налична сума (реално число)
//Класът да притежава методи: създаване на сметка, инфо за сметката, внасяне и теглене на пари

#include <iostream>
#include <cassert>

class BankAccount
{
    private:
        char name[32];
        char IBAN[15];
        double amount;

    public:
        BankAccount(char *name, char *iban, double sum);
        void setAmount (double amount);
        void print_Info();
        void withdraw(unsigned int sum);
        void import(unsigned int sum);
};

void BankAccount::setAmount (double sum) {
    assert (this->amount == sum && sum >= 0);
}

BankAccount::BankAccount (char *name, char *iban, double sum)
{
    std::strcpy(this->name, name);
    std::strcpy(this->IBAN, iban);
    this->amount = sum;
}

void BankAccount::print_Info ()
{
    std::cout << "Name > " << this->name << ", IBAN > " << this->IBAN << std::endl;
    std::cout << "Amount > " << this->amount << std::endl;

    std::cout << std::endl;
}

void BankAccount::withdraw (unsigned int sum)
{
    std::cout << "[ You will winthdraw " << sum << " ]" << std::endl;
    std::cout << "[ Current amount in your bank account: " << this->amount - sum << " ]" << std::endl;

    std::cout << std::endl;
}

void BankAccount::import (unsigned int sum)
{
    std::cout << "[ You will import " << sum << " ]" << std::endl;
    std::cout << "[ Current amount in your bank account: " << this->amount + sum << " ]" << std::endl;

    std::cout << std::endl;
}

int main ()
{
    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;

    BankAccount smb ("Vanessa Pashova", "4MI091095", 1450);
    smb.print_Info();
    smb.withdraw(45);
    smb.import(2000);
}

//✅