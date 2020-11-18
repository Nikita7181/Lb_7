#include <iostream>
using std::endl;
using std::cout;
using std::string;
using std::cin;

struct element
        {
element* q_next;
int value;
};

struct Queue
        {
    element* first;
    element* last;
};

void constructor(Queue& myQueue)
{
    myQueue.first= nullptr;
    myQueue.last= nullptr;
}

void destructor(Queue& myQueue)
{
    while (myQueue.first != nullptr)
    {
        element* tmp = new element;
        tmp=myQueue.first;
        myQueue.first=(*myQueue.first).q_next;
        delete tmp;
    }
}

unsigned int size(Queue& myQueue)
{
element* size_q = new element;
size_q = myQueue.first;
unsigned int counter = 0;
while (size_q != nullptr)
{
    ++counter;
    size_q = (*size_q).q_next;
}
    return counter;
}

void push(Queue& myQueue, element& l)
{
    if (myQueue.first == nullptr)
    {
        element* new_q= new element;
        (*new_q).value = l.value;
        myQueue.first = new_q;
        myQueue.last = new_q;
    } else if (myQueue.first != nullptr)
    {
        element* new_q = new element;
        (*new_q).value = l.value;
        (*new_q).q_next = new_q;
        myQueue.last = new_q;

    }
}

element pop(Queue& myQueue)
{
    int k = (*myQueue.first).value;
    element r;
    element* tmp = new element;
    tmp = myQueue.first;
    myQueue.first=(*myQueue.first).q_next;
    delete tmp;
    r.value = k;
    r.q_next = myQueue.first;
    return r;
}

int main()
{
    Queue queue;
    constructor(queue);
    element element;
    int k;
    for (int i =0; i<5; ++i)
    {
        cin >> k;
        element.value=k;
        push(queue, element);
    }
cout <<"size:" << size(queue) << endl;
    element = pop(queue);
    cout << "The first element:" << element.value << endl;
    element = pop(queue);
    cout << "The first element:" << element.value << endl;
    element = pop(queue);
    cout << "The first element:" << element.value << endl;
    cout <<"size:" << size(queue) << endl;
    destructor(queue);
    return 0;
}
