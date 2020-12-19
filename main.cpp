#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::cin;

struct element
{
    element* q_next = nullptr;
    int value ;
};

struct Queue
{
    element* first;
    element* last;
    int count;
};

void constructor(Queue& myQueue)
{
    myQueue.first = nullptr;
    myQueue.last = nullptr;
    myQueue.count = 0;
}


void push(Queue& myQueue, element& l)
{
    element* newQ_e = new element;
    newQ_e -> value = l.value;
    if (myQueue.first == nullptr)
    {
        myQueue.first = newQ_e;
        myQueue.last = newQ_e;
    } else
    {
        myQueue.last -> q_next = newQ_e;
        myQueue.last = newQ_e;
    }
    myQueue.count ++;
    
}

int size(Queue& myQueue)
{
  return myQueue.count;
}

void print(Queue& myQueue)
{
    element* temp = myQueue.first;
    while (temp != nullptr)
    {
        int element = temp -> value;
        cout << element << " ";
        temp = temp -> q_next;
    }
}

void pop_front(Queue &myQueue)
{
    element  *temp = myQueue.first;
     myQueue.first = myQueue.first -> q_next;
     delete temp;
     myQueue.count --;
}

void destructor (Queue& myQueue)
{
    while (myQueue.first != nullptr)
    {
        element* temp = temp = myQueue.first;
        myQueue.first = myQueue.first -> q_next;
        delete temp;
        myQueue.count --;
    }
}

int main()
{
    Queue myQueue;
    constructor(myQueue);
    element element;
    int a;
    int c;
    cout << "Enter the number of element = ";
    cin >> c;
    for (int i = 1; i <= c; ++i)
    {
        cout << "enter " << i << " element:";
        cin >> a;
        element.value = a;
        push(myQueue, element);
    }
    print(myQueue);
    cout << endl;
    cout << "Size:" << size(myQueue) << endl;
    cout << "get the first element: " << myQueue.first -> value << endl;
    pop_front(myQueue);
    cout << "Size:" << size(myQueue) << endl;
    print(myQueue);
    destructor(myQueue);
    cout << "there is " << size(myQueue) << " in queue" << endl;
    return 0;
}
