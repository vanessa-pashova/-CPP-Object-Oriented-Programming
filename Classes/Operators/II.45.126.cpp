//Да се дефинира клас Матрица, реализиращ квадратна матрица от цели числа, разположена в динамична памет. Освен конструктори, деструктор и методи за извеждане 
//на информация, класът да предефинира оператори:
// - =, за да присвоя матрица;
// - (), за да работи като оператор за достъп до елементи на матрицата и проверява дали индексите са в ДС (ако не са, да се изведе грешка)

#include <iostream>
int overflowFlag = -99;
const std::size_t maxSide = 100;

class Matrix
{
    private:
        int side;
        int *arr;

        void destroy() {
            delete [] arr;
        }

        void copyFrom(const Matrix &other)
        {
            for (std::size_t i = 0; i < (other.side * other.side); i++)
                this->arr[i] = other.arr[i];

            this->side = other.side;
        }

    public:
        Matrix();
        Matrix(int);
        ~Matrix();

        Matrix &operator=(const Matrix &);
        int &operator() (int, int);

        void print();
};

Matrix::Matrix() : side(0) {}

Matrix::Matrix (int side) 
{
    if (side <= 0)
        std::cout << "[ side should be between 1 and 99 ]\n";

    else if (side > maxSide)
        std::cout << "[ side shouldn't be greater than maxSide ]\n";

    this->side = side;
    this->arr = new int[side * side];
}

Matrix::~Matrix() {
    this->destroy();
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        this->destroy();
        this->copyFrom(other);
    }

    return *this;
}

int &Matrix::operator() (int i, int j)
{
    if (i < 0 || j < 0 || i >= side || j >= side)
    {
        std::cout << "[ out of the limits ]\n";
        return overflowFlag;  
    }

    else 
        return arr[i * side + j]; 
}

void Matrix::print()
{
    for (std::size_t i = 0; i < side; i++)
    {
        for (std::size_t j = 0; j < side; j++)
            std::cout << (*this)(i, j) << " ";
            //Изразът (*this)(i, j) извиква оператора operator() на текущия обект *this с аргументите i и j и връща резултата - стойността на съответния елемент в матрицата.
            //Това става възможно, защото operator() е предефиниран като член-функция в класа Matrix.
    }
    std::cout << '\n';
}

int main ()
{
    std::cout << '\n';
    std::cout << "----------------------------\n";

    Matrix m(5);
    for (std::size_t i = 0; i < 5; i++)
    {
        for (std::size_t j = 0; j < 5; j++)
            m(i, j) = i * j + 1;
    }

    Matrix n(5);
    n = m;

    n.print();
    m.print();
}
