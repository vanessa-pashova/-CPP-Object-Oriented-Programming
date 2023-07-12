//Лекар трябва да поддържа статистика за броя на посещенията, които са направили пациентите му. За всекик пациент лекаря записва името, датата на раждане
//и броя на посещенията, които е направил пациента за една календарна година. Да се напише програма, която лекар да създава:
// - списък от пациентите му
// - намира средния борй посещения на пациентите
// - нaмира пациентите, които са направили повече посещения от зададен брой

#include <iostream>
const std::size_t MAX_SIZE = 30;

class Patient
{
    private:
        char name[MAX_SIZE];
        int day, month, year;
        int visits;

    public:
        const char *getName () const;
        int getDay () const;
        int getMonth () const;
        int getYear () const;
        int getVisits () const;

        void create_List (int count);
        void print_List (int count);

        int AVG_Visits (int count);

        void AlwaysSick (int count);
};

const char *Patient::getName () const {
    return this->name;
}
 
int Patient::getDay () const {
    return this->day;
}

int Patient::getMonth () const {
    return this->month;
}

int Patient::getYear () const {
    return this->year;
}

int Patient::getVisits () const {
    return this->visits;
}

Patient list[MAX_SIZE];

void Patient::create_List (int count)
{
    std::cout << "[ List of Patients genereted ]" << std::endl;
    for (std::size_t i = 0; i < count; i++)
    {
        std::cout << "[ Name of patient Num(" << i + 1 << ") ] -> ";
        std::cin >> list[i].name;
        std::cout << "[ Birth of patient Num(" << i + 1 << ") ] -> " << std::endl;
        std::cin >> list[i].day >> list[i].month >> list[i].year;
        std::cout << "[ Visits of patient Num(" << i + 1 << ") for this year ] -> ";
        std::cin >> list[i].visits;
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}

void Patient::print_List (int count)
{
    std::cout << "[ List of patients genereted ]" << std::endl;
    for (std::size_t i = 0; i < count; i++)
    {
        std::cout << "[ Name of patient Num(" << i + 1 << ") ] -> " << list[i].name << std::endl;
        std::cout << "[ Birth of patient Num(" << i + 1 << ") ] -> " << list[i].day << '.' << list[i].month << '.' << list[i].year << std::endl;
        std::cout << "[ Visits of patient Num(" << i + 1 << ") for this year ] -> " << list[i].visits << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

int Patient::AVG_Visits (int count)
{
    int sum = 0;
    for (std::size_t i = 0; i < count; i++)
        sum += list[i].visits;

    return sum / count;
}

void Patient::AlwaysSick (int count)
{
    std::cout << "[ List of Always Sick Patients genereted ]" << std::endl;
    int max = 0;
    std::cout << "[ Insert how much visits is normal per year ]\n> ";
    std::cin >> max;

    for (std::size_t i = 0; i < count; i++)
    {
        if (list[i].visits > max)   
        {
            std::cout << "[ Patient Num(" << i + 1 << ") came more often than other ordinary patients ]" << std::endl;
            std::cout << "> Name: " << list[i].name << std::endl;
            std::cout << "> Birth: " << list[i].day << '.' << list[i].month << '.' << list[i].year << std::endl;
            std::cout << "> Visits: " << list[i].visits << std::endl;

            std::cout << std::endl;
        }
    }
}

int main ()
{
    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;

    int count = 0;
    do {
        std::cout << "[ How many patients did you have? ]\n> ";
        std::cin >> count;
    } while (count < 0);

    Patient list[MAX_SIZE];
    list->create_List(count);
    list->print_List(count);
    
    list->AVG_Visits(count);
    list->AlwaysSick(count);
}
//✅
 