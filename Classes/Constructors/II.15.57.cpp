//Да се дефинира клас Диффър, който проверява дали елементите на непразна редица от цели числа са различни (няма повтарящ се елемент).
//Създаването на редицата да се направи с подходящ конструктор

#include <iostream>
const std::size_t MAX_SIZE = 15;

class Differ 
{
    private:    
        int row[MAX_SIZE];

    public:
        Differ(std::size_t MAX_SIZE);
        int *getRow ();
        bool proof (std::size_t MAX_SIZE, int row[]);
};

Differ::Differ (std::size_t size)
{
    for (std::size_t i = 0; i < size; i++)
    {
        std::cout << "> Insert value for element[" << i + 1 << "]: ";
        std::cin >> row[i];
    }
}

int *Differ::getRow () {
    return row;
}

bool Differ::proof (std::size_t MAX_SIZE, int row[])
{
    for (int i = 0; i < MAX_SIZE - 1; i++) 
    {
        for (int j = i + 1; j < MAX_SIZE; j++) 
        {
            if (row[i] == row[j]) 
                return true;
        }
    }
    //Например, ако имаме редица [1, 2, 3, 2, 4, 5], методът ще сравни първия елемент (1) с всички следващи елементи (2, 3, 2, 4, 5). 
    //След това ще сравни втория елемент (2) с останалите елементи (3, 2, 4, 5) и т.н. Това включва и сравнението на елементите, 
    //които са едни до други в редицата, и тези, които са разделени от други елементи.

    return false;
}

int main ()
{
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;

    Differ first(MAX_SIZE);
    int *rowPtr = first.getRow();
    //Чрез извикването на метода getRow() връщаме указател към row от обекта first. Така получаваме достъп до данните в row чрез връщания указател.
    
    bool hasDuplicates = first.proof(MAX_SIZE, rowPtr);
    //След това, като предаваме rowPtr като аргумент на метода proof(), можем да използваме указателя, за да проверим наличието на повтарящи се елементи в редицата.

    if (hasDuplicates)
        std::cout << "Редицата съдържа повтарящи се елементи." << std::endl;
    else
        std::cout << "Редицата не съдържа повтарящи се елементи." << std::endl;
}

//✅