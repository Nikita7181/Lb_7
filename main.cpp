#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::cin;

struct element
        {
element* q_next = nullptr;
int value = -7;
};

struct Queue
        {
    element* first;
    element* last;
};

void constructor(Queue& myQueue)
{
    myQueue.first = nullptr;
    myQueue.last = nullptr;
}

void push(Queue& myQueue, element& l)
{
    element* newQ_e = new element;
    newQ_e -> value = l.value;
    if (myQueue.first == nullptr) {
        myQueue.first = newQ_e;
        myQueue.last = newQ_e;
        
    } else if (myQueue.first != nullptr) {
        myQueue.last -> q_next = newQ_e;
        myQueue.last = newQ_e;
    }
    
}

element pop(Queue& myQueue)
{
    int a = myQueue.first -> value;
    element z;
    myQueue.first = myQueue.first -> q_next;
    z.value = a;
    z.q_next = myQueue.first;
    return z;
}

 int size(Queue& myQueue)
{
    element* c = new element;
    c = myQueue.first;
    unsigned int counter = 0;
    while (c != nullptr) {
        counter++;
        c = c -> q_next;
    }
    delete c;
    return counter;
}

void print(Queue& myQueue)
{
    element* c = new element;
    c = myQueue.first;
    while (c != nullptr) {
        cout << c -> value << " ";
        c = c -> q_next;
    }
    cout << endl;
    delete c;
}

void del(element* myQueue)
{
    if (myQueue != nullptr)
    {
        del(myQueue -> q_next);
        delete myQueue;
    }
}

void destructor (Queue& myQueue)
{
    del(myQueue.first);
}


int main()
{
    Queue myQueue;
    constructor(myQueue);
    element element;
    int a;
    for (int i = 0; i < 5; ++i) {
        std::cin >> a;
        element.value = a;
        push(myQueue, element);
    }
    print(myQueue);
    cout << "there is " << size(myQueue) << " in queue." << endl;
    element = pop(myQueue);
    cout << "Get the first element from queue. It is " << element.value << endl;
    element = pop(myQueue);
    std::cout << "Get the first element from queue. It is " << element.value << endl;
    element = pop(myQueue);
    cout << "Get the first element from queue. It is " << element.value << endl;
    cout << "there is " << size(myQueue) << " in queue." << endl;
    print(myQueue);
    destructor(myQueue);
    return 0;
}
