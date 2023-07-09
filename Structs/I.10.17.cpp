//Да се напише програма, която:
//а) въвежда факултетни номера (цели числа с максимум 5 цифри), фамилия (символни низове с max дължина 11) и оценките по k (1 <= k <= 10) учебни дисциплини
//б) сортира в низходящ ред по среден успех въведената информация за студентите от групата

#include <iostream>
const std::size_t MAX_Students = 30;

struct Student
{
    int fn;
    char surname[11];
    int sub_c;
    int subjects[10];
};

Student group[MAX_Students];

void create_Student (Student &obj) 
{
    do {
        std::cout << "Please, insert your Faculty Number: ";
        std::cin >> obj.fn;
    } while (obj.fn < 0 || 99999 < obj.fn);

    std::cout << "Please, insert your Surname: ";
    std::cin >> obj.surname;
 
    do {
        std::cout << "Please, insert how many subjects: ";
        std::cin >> obj.sub_c;
    } while (obj.sub_c < 1 || 10 < obj.sub_c);

    for (std::size_t i = 0; i < obj.sub_c; i++)
    {
        do {
            std::cout << "Please, insert note (sub " << i + 1 << "): ";
            std::cin >> obj.subjects[i];
        } while (obj.subjects[i] < 2 || 6 < obj.subjects[i]);
    } 

    std::cout << std::endl;
}

void create_Group (int &count, Student group[])
{
    for (std::size_t i = 0; i < count; i++)
        create_Student(group[i]);
}

double AVG (Student &obj)
{
    double avg = 0;
    for (std::size_t i = 0; i < obj.sub_c; i++)
        avg += obj.subjects[i];
        
    avg /= obj.sub_c;

    return avg;
}

void print_OneStudent (Student &obj)
{
    std::cout << "Faculty Number > " << obj.fn << "  ---  ";
    std::cout << "Surname > " << obj.surname << "  ---  ";
    
    for (std::size_t i = 0; i < obj.sub_c; i++)
        std::cout << "Note for subject[" << i + 1 << "] > " << obj.subjects[i] << std::endl;

    std::cout << "AVG note from all subjects: " << AVG(obj) << std::endl;
    std::cout << std::endl;
}

void print_AVGallStudents (int &count, Student group[])
{
    for (std::size_t i = 0; i < count; i++)
        std::cout << "AVG note from all subjects: " << AVG(group[i]) << std::endl;

    std::cout << std::endl;
}

void sort_Group (int &count, Student group[])
{
    for (std::size_t i = 0; i < count - 1; i++)
    {
        int k = i;
        double max = AVG(group[i]);

        for (std::size_t j = i + 1; j < count; j++)
        {
            if (AVG(group[j]) > AVG(group[i]))
            {
                max = AVG(group[j]);
                k = j;
            }
        }

        Student obj = group[i];
        group[i] = group[k];
        group[k] = obj;
    }
}

void print_AllStudents (int &count, Student group[])
{
    sort_Group(count, group);
    for (std::size_t i = 0; i < count; i++)
        print_OneStudent(group[i]);
}

int main ()
{
    std::cout << std::endl;
    std::cout << "----------------------------" << std::endl;

    int count = 0;
    std::cout << "Please, insert how many students there are: ";
    std::cin >> count;

    create_Group(count, group);
    print_AllStudents(count, group);
    //print_AVGallStudents(count, group);
    sort_Group(count, group);
}

//✅
