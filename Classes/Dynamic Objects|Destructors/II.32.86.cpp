//Да се дефинира клас ArrInt, наподобяващ на едномерен масив, но порверяващ границите на индексираната променлива. Класът да притежава и член-функции за 
//търсене на елемент и за сортиране на едномерен масив 
#include <iostream>
const std::size_t MAX_SIZE = 20;

class IntArray
{
    private:
        int *array;
        int num;
        bool isValid(int);

        void deallocate () {
            delete [] this->array;
        }

        void copyFrom (const IntArray &other) 
        {
            this->array = new int[other.num + 1];

            for (std::size_t i = 0; i < other.num; i++)
                this->array[i] = other.array[i];

            this->num = other.num;
        }

    public: 
        IntArray (int);
        ~IntArray ();
        IntArray &operator= (const IntArray &other);

        bool set (int, int);
        bool get (int, int&);

        int linearSearch (int);
        int binarySearch (int);

        void selectingSort ();
        void bubleSort ();
};

IntArray::IntArray (int size) 
{
    if (size > MAX_SIZE)
    {
        std::cout << "[ Size out of limit! ]\n";
        exit(1);
    }

    else if (size < 0)
    {
        std::cout << "[ Size should be greater than zero! ]\n";
        exit(1);
    }

    this->array = new int[size];
    if (!array)
    {
        std::cout << "[ Memory problem ]\n";
        exit(1); 
    }

    this->num = size;
    for (std::size_t i = 0; i < size; i++)
        this->array[i] = 0;
}

IntArray::~IntArray () {
    this->deallocate();
}

IntArray &IntArray::operator= (const IntArray &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }

    return *this;
}

//връща дали индексът е валиден
bool IntArray::isValid (int element) {
    return element >= 0 && element < num;
}

//присвоява стойност на указан елемент на масива; ако стойнността се, присвоява от валиден елемент дава тру, иначе фолс;
bool IntArray::set(int element, int value)
{
    if(isValid(element))
    {
        array[element] = value;
        return true;
    }

    return false;
}

//намира стойност на даден указан елемент от масива; ако индексът е коректен, връща тру, иначе фолс
bool IntArray::get(int element, int &value)
{
    if(isValid(element))
    {
        value = array[element];
        return true;
    }

    return false;
}

//Когато се намери съвпадение на стойността на елемента x с елемент в масива, се излиза от цикъла и се проверява дали x == array[i]. 
//Ако условието е вярно, то значи, че елементът x е намерен в масива и се връща индексът i, който указва позицията на намерения елемент.
//Ако не се намери съвпадение и се стигне до края на масива, се връща стойността на променливата num, 
//която представлява индекс, извън границите на масива и сигнализира, че търсеният елемент не е намерен в масива.
int IntArray::linearSearch (int x)
{
    int i = 0; 
    while (i < num - 1 && x != array[i])
        i++;

    if (x == array[i])
        return i;

    else
        return num;
}

//
int IntArray::binarySearch (int x)
{
    int middle, left = 0, right = num - 1;
    if (x < array[left])
        return -1;
    
    if (x == array[left])
        return 0;

    //Ако елементът x е по-малък от най-малкия елемент в масива (array[left]), се връща -1, което указва, че x не може да бъде намерен в масива.
    //Ако елементът x съвпада с най-малкия елемент в масива (array[left]), се връща 0, което указва, че x е намерен в първата позиция на масива.

    if (x > array[right])
        return num;

    //Ако горните две условия не се изпълнят, се проверява дали елементът x е по-голям от най-големия елемент в масива (array[right]). 
    //Ако е така, се връща num, което указва, че x трябва да бъде вмъкнат след последния елемент на масива.

    while (right - left > 1)
    {
        //След това се извършва самото бинарно търсене в цикъл, докато разликата между right и left е по-голяма от 1. 
        middle = (left + right) / 2;    //Вътре в цикъла се определя новата средна позиция middle, като се изчислява средата между left и right чрез формулата (left + right) / 2.
        if (x <= array[middle])
            return middle;
        //Ако елементът x е по-малък или равен на елемента на позиция middle, се връща middle, което указва, че x трябва да бъде вмъкнат на или преди позицията middle.

        else 
            left = middle;
        //В противен случай, променя се стойността на left и на middle, което означава, че търсенето продължава във втората половина на масива.
    }

    return right;
    //Ако цикълът приключи и разликата между right и left стане по-малка или равна на 1, се връща right, което указва, 
    //че x трябва да бъде вмъкнат след right позицията или че x вече се съдържа на позиция right в масива.
}

void IntArray::selectingSort ()
{
    std::cout << "[ Selecting Sort ]\n";
    int min = 0;

    for (int i = 0; i < num - 1; i++)
    {
        int k = i;
        min = array[k];

        for (int j = i + 1; j < num; j++)
        {
            if (array[j] < min)
            {
                k = j;
                min = array[k];
            }
        }

        array[k] = array[i];
        array[i] = min;
    }
}

void IntArray::bubleSort ()
{
    int k, right = num - 1;

    while (right > 0)
    {
        //След това се изпълнява цикълът while, който продължава докато right е по-голям от 0. Този цикъл се изпълнява повтарящо се число пъти,
        //като с всяка итерация най-голямата стойност в неподредената част на масива "възлиза" най-отзад.
        std::cout << "[ Buble Sort ]\n";
        k = 0; 
        int swap;
        //Вътре в цикъла се инициализира променливата k със стойност 0, която показва последната позиция, на която е извършена размяна на елементи. 
        //Също така се дефинира и променливата swap, която се използва за временно съхранение на стойността на елемента, който ще бъде разменен.

        for (int i = 0; i < right; i++)
        {
            //След това се изпълнява цикълът for, който обхожда неподредената част на масива до позиция right. 
            //Вътре в него се прави проверка дали следващият елемент (array[i + 1]) е по-малък от текущия (array[i]). 
            //Ако условието е изпълнено, се извършва размяна на стойностите на двата елемента чрез временната променлива swap, 
            //а променливата k се променя на текущата позиция i. 
            //Това означава, че е била извършена размяна на елементи и най-голямата стойност от неподредената част на масива е преместена на позиция k.
            if (array[i + 1] < array[i])
            {
                swap = array[i];
                array[i] = array[i + 1];
                array[i + 1] = swap;
                k = i;
            }
        }

        //След приключване на цикъла for се актуализира променливата right със стойността на k, което намалява броя на неподредените елементи в масива.
        right = k;

        //Така се повтаря цикълът while до момента, когато всички елементи в масива са подредени във възходящ ред (когато right стане по-малък или равен на 0).
    }
}

int main ()
{
    std::cout << std::endl;
    std::cout << "------------------------" << std::endl;

    int n = 0;
    std::cout << "> n: ";
    std::cin >> n;

    IntArray arr(n);

    int value = 0;    
    for (int i = 0; i < n; i++)
    {
        std::cout << "> element: ";
        std::cin >> value;

        if (!arr.set(i, value))
            std::cout << "[ initialization error ]\n";
    }

    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        if (arr.get(i, value))
            std::cout << value << "  ";
        
        else    
            std::cout << "[ initialization error ]\n";
    }

    if(arr.get(arr.linearSearch(value), value))
        std::cout << "[ element found ]\n";

    else 
        std::cout << "[ element not found ]\n";

    arr.bubleSort();
    // arr.selectingSort();

    int other = 0;
    std::cout << "> other element: ";
    std::cin >> other;
    std::cout << "[ position of element in the array is: " << arr.binarySearch(other) << " ]\n";
}

//✅
