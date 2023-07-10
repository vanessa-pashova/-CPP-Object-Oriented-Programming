//Да се дефинира клас Работник, който пресмята заплата на чиновник, дефиниран чрез:
// - име, зададено чрез структура с полета first(осбствено име) и last (фмаилно име) и
// - работа, зададена чрез структура с полета часове и заплащане за 1 час
#include <iostream>
const std::size_t MAX = 10;

class Employee
{
    private:
        struct {
            char first[MAX], last[MAX];
        } name;

        struct {
            int hours;
            double salary;
        } work;
    
    public:
        void Input ();
        void print_Info () const;
};

void Employee::Input()
{
    std::cout << "[ First Name ]\n> ";
    std::cin >> name.first;
    std::cout << "[ Last Name ]\n> ";
    std::cin >> name.last;
    std::cout << "[ Work Hours ]\n> ";
    std::cin >> work.hours;
    std::cout << "[ Salary per Hour ]\n> ";
    std::cin >> work.salary; 

    std::cout << std::endl;
}

void Employee::print_Info() const
{
    std::cout << "Employee: " << name.first << ' ' << name.last << std::endl;
    std::cout << "Salary: " << work.salary * work.hours << std::endl;
}

int main ()
{
    Employee worker;
    worker.Input();
    worker.print_Info();
}

//✅


