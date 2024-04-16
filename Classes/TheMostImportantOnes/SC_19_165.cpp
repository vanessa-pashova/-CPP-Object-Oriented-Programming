#include <iostream>
const short MAX_SIZE = 30;

class Queue {
private:
    char arr[MAX_SIZE];
    short size;

    void copyFrom(const Queue &other) {
        this->size = other.size;
        this->removeElements();

        strcpy(this->arr, other.arr);
    }

    void removeElements() {
        for(char &element : arr)
            element = ' ';
    }

public:
    Queue();
    Queue(const char*);
    Queue(const Queue &);

    void add(const char &);
    void remove();
    char atFront();
    bool isEmpty();
};

Queue::Queue() : size(0) {
    this->arr[0] = '\0';
}

Queue::Queue(const char *arr) {
    short size = strlen(arr) + 1;

    if(size > MAX_SIZE)
        this->size = 5;

    else this->size = size;

    for(short i = 0; i < this->size; i++)
        strcpy(this->arr, arr);
}

Queue::Queue(const Queue &other) {
    if(this != &other)
        this->copyFrom(other);
}

void Queue::add(const char &ch) {
    if(this->size < MAX_SIZE) {
        this->size++;
        this->arr[this->size - 1] = ch;
    }

    else std::cout << "--------------- could not be added [out of memory] ---------------\n";
}

void Queue::remove() {
    this->size--;
    this->arr[this->size] = '\0';
}

char Queue::atFront() {
    return this->arr[0];
}

bool Queue::isEmpty() {
    return this->arr[0] == '\0';
}

int main() {
    Queue queue1;

    queue1.add('A');
    queue1.add('B');
    queue1.add('C');

    std::cout << "Front element: " << queue1.atFront() << std::endl;

    queue1.remove();

    if (queue1.isEmpty())
        std::cout << "Queue is empty." << std::endl;

    else std::cout << "Queue is not empty." << std::endl;

    Queue queue2(queue1);

    queue2.add('D');
    queue2.add('E');

    std::cout << "Front element of copied queue: " << queue2.atFront() << '\n';

    queue2.remove();

    std::cout << "Front element of copied queue after removal: " << queue2.atFront() << std::endl;
}
