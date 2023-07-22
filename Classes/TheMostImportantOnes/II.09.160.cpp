//Да се дефинира клас Калкулатор, който да допуска като вход символен низ, представящ аритметичен израз с цели операнди и операторите +, - , *, / и намира стойността на 
//израза и я извежда. Класът да има метод за проверка на валидност на израза

#include <iostream>
#include <string>

class Calculator
{
private:
    std::string expression;

    //функцията проверява дали символът ch е цифра (isdigit(ch)) или един от операторите '+' (ch == '+'), '-' (ch == '-'), '*' (ch == '*') или '/' (ch == '/').
    bool isValidCharacter(char ch) const {
        return (isdigit(ch) || ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    bool isValidExpression() const
    {
        //Инициализира се броячът parenthesesCount на отворени скоби със стойност 0
        int parenthesesCount = 0;

        //Обхожда се изразът символ по символ.
        for (int i = 0; i < expression.size(); i++)
        {
            //Ако срещне отваряща скоба '(', увеличава се стойността на parenthesesCount с 1.
            if (expression[i] == '(')
                parenthesesCount++;

            //Ако срещне затваряща скоба ')', намалява се стойността на parenthesesCount с 1.
            else if (expression[i] == ')')
            {
                parenthesesCount--;

                //Проверява се дали parenthesesCount става отрицателно. Ако стане, това означава, че има затваряща скоба, преди да има отваряща скоба, което не е валидно. 
                //В този случай функцията връща false.
                if (parenthesesCount < 0)
                    return false;
            }
        }
        
        //Накрая се проверява дали parenthesesCount е равно на 0. Ако е равно, това означава, че броят на отворените и затворените скоби съвпада, което е валидно. 
        return parenthesesCount == 0;
    }

    int calculateExpression(int &index) const
    {
        int result = 0;
        int num = 0;
        char op = '+';

        while (index < expression.length())
        {
            char ch = expression[index];
            
            //Ако текущият символ ch е цифра (цифри 0-9), числото се формира като num = num * 10 + (ch - '0'). Това позволява да се изгради числото от една или повече цифри.
            if (isdigit(ch))
                num = num * 10 + (ch - '0');

            //Ако текущият символ ch е отваряща скоба '(', се извиква рекурсивно функцията calculateExpression за изчисляване на стойността на израза в скобите. 
            //Резултатът се присвоява на num.
            else if (ch == '(')
            {
                index++;
                num = calculateExpression(index);
            }

            //Ако текущият символ ch е затваряща скоба ')', прекъсва се изпълнението на цикъла, защото сме завършили изчислението на израза в скобите
            else if (ch == ')')
                break;

            //Ако текущият символ ch е оператор '+', '-', '*', или '/', изпълнява се съответната операция върху result и num в зависимост от текущия оператор op. 
            //Резултатът от операцията се записва в result. След това op се променя на текущия оператор ch, а num се нулира, за да се започне ново формиране на число.
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                if (op == '+')
                    result += num;

                else if (op == '-')
                    result -= num;

                else if (op == '*')
                    result *= num;

                else if (op == '/')
                    result /= num;

                op = ch;
                num = 0;
            }

            //Увеличава се стойността на index за да се премине към следващия символ в израза.
            index++;
        }

        //След края на цикъла се извършва последната операция, използвайки текущия оператор op и стойността на num.
        if (op == '+')
            result += num;

        else if (op == '-')
            result -= num;

        else if (op == '*')
            result *= num;

        else if (op == '/')
            result /= num;

        return result;
    }

public:
    Calculator(const std::string &expr) : expression(expr) {}

    void setExpression(const std::string &expr) {
        expression = expr;
    }

    bool validateExpression() const
    {
        if (expression.empty())
        {
            std::cout << "Error: Empty expression!\n";
            return false;
        }

        for (int i = 0; i < expression.size(); i++)
        {
            if (!isValidCharacter(expression[i]))
            {
                std::cout << "Error: Invalid character '" << i << "' in the expression!\n";
                return false;
            }
        }

        if (!isValidExpression())
        {
            std::cout << "Error: Invalid parentheses in the expression!\n";
            return false;
        }

        return true;
    }

    int calculate() const
    {
        // if (!validateExpression())
        //     return 0; // В случай на грешка, връщаме 0

        int index = 0;
        return calculateExpression(index);
    }
};

int main()
{
    Calculator calculator("((25/5)+4)");
    int result = calculator.calculate();
    std::cout << "Result: " << result << std::endl;

    return 0;
}
//✅
