//Да се дефинира клас Време, който да определя врепе по зададен час и минути. Класът да съдържа:
// - подходящи конструктори
// - мутатор променящ часа и минутите; мутатори добавящи към време цяло число, означаващо час и минути
// - метод, който предефинира оператора за преобразуване на типове така, че да може да се преобразува време в цяло число, означаващо време в часове към минути
//Да се предефинират операторите +, - и *, така, че да могат да събират, изваждат и умножават две времена, както и да умножават време с цяло число
//и цяло число с време

#include <iostream>

class Time 
{
    private:
        unsigned int hours, minutes;

        void copyFrom (const Time &other)
        {
            this->hours = other.hours;
            this->minutes = other.minutes;
        }

    public:
        Time (unsigned int,unsigned int);
        Time ();
        Time &operator= (const Time &);

        int getMinutes () const;
        int getHours () const;

        void setMinutes (unsigned int mins);
        void setHours (unsigned int hours);
        void simplify();

        void print ();

        operator int () const;

        void changeHours();

        Time operator+ (const Time &other) const;
        Time operator- (const Time &other) const;
        
        Time operator* (int) const;

        friend Time operator* (int m, const Time &t) {
            return t * m;   //умножава времето t с числото m
        }
};

Time::Time () : hours(0), minutes(0) {}
Time::Time(unsigned int hours,unsigned int minutes) : hours(hours), minutes(minutes) {}

Time &Time::operator= (const Time &other)
{
    if (this != &other)
        copyFrom(other);

    return *this;
}

int Time::getHours () const {
    return this->hours;
}

int Time::getMinutes () const {
    return this->minutes;
}

void Time::setHours (unsigned int hours) {
    this->hours = hours;
}

void Time::setMinutes (unsigned int minutes) {
    if (minutes < 60)
    {
        this->minutes += minutes;
        if (this->minutes > 59)
        {
            this->hours++;
            this->minutes -= 60;
        }
    }

    else if (60 <= minutes && minutes < 120) 
    {
        this->hours++;
        this->minutes = (this->minutes + minutes) - 60;
    }

    else if (120 <= minutes && minutes < 180)
    {
        this->hours += 2;
        this->minutes = (this->minutes + minutes) - 120;
    }
}

void Time::simplify ()
{
    if (minutes > 59)
    {
        this->hours += this->minutes / 60;
        this->minutes %= 60;
    }
}

void Time::print () {
    std::cout << "--> Time: " << this->hours << ":" << this->minutes << std::endl;
    std::cout << '\n';
}

//оператор за преобразуване на време в цяло число, изразяващо времето в минути
Time::operator int () const {
    return hours * 60 + minutes;
}

//ф-ции събиращи и изваждащи две времена
Time Time::operator+ (const Time &other) const 
{
    Time new_t;
    new_t.minutes = this->minutes + other.minutes;
    new_t.hours = this->hours + other.hours;
    new_t.simplify();

    return new_t;
}

Time Time::operator- (const Time &other) const 
{
    Time new_t;
    int m1, m2;

    m1 = other.hours + other.minutes;
    m2 = this->hours * 60 + this->minutes;

    new_t.hours = (m1 - m2) / 60; 
    new_t.minutes = (m2 - m1) % 60;

    return new_t;
}

void Time::changeHours ()
{
    std::cout << "[ change hours function genereted. Choose between options: m|M - minutes or h|H - hours ]\n> ";
    char c;
    std::cin >> c;
    
    if (c == 'm' || c == 'M')
    {
        int min = 0; 
        std::cout << "[ You chose minutes. How many? ]\n> ";
        std::cin >> min;

        setMinutes(min);
        std::cout << "> Time: " << this->hours << ":" << this->minutes << std::endl;
        std::cout << '\n';
    }

    else if (c == 'h' || c == 'H')
    {
        int h = 0; 
        std::cout << "[ You chose hours. How many? ]\n> ";
        std::cin >> h;

        this->hours += h;
        std::cout << "--> Time: " << this->hours << ":" << this->minutes << std::endl;
        std::cout << '\n';
    }

    else
        std::cout << "[ invalid command ]\n";

    std::cout << '\n';
} 

//оператор за умножение на време с цяло число
Time Time::operator* (int mult) const 
{
    Time new_t;
    int m = (hours * 60 + minutes) * mult;
    
    new_t.hours = m / 60;
    new_t.minutes = m % 60;

    return new_t;
}

int main ()
{
    std::cout << '\n';
    std::cout << "---------------------------\n";

    Time first (3, 45), t, second (5, 30), t3;
    t.print();
    first.print();

    Time t2 = first;
    t2.print();

    first.changeHours(); 

    t = first + t2;
    t.print();

    t3 = second - first;
    t3.print();

    t = t2 * 2;
    t.print();
}
//✅

