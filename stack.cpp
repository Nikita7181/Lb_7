#include <iostream>
using std::endl;
using std::cout;
using std::string;
using std::cin;

struct element
{
    element* prev = nullptr;
    int value;
};

struct Stack
{
    element* first;
    element* last;
};

void constructor(Stack& myStack)
{
    myStack.first= nullptr;
    myStack.last= nullptr;
}

void destructor(Stack& myStack)
{
    while (myStack.first != nullptr)
    {
        element* tmp = new element;
        tmp=myStack.last;
        myStack.last=(*myStack.first).prev;
        delete tmp;
    }
}

unsigned int size(Stack& myStack)
{
    element* size_s = new element;
    size_s = myStack.last;
    unsigned int counter = 0;
    while (size_s != nullptr)
    {
        ++counter;
        size_s = (*size_s).prev;
    }
    return counter;
}

void push(Stack& myStack, element& l)
{
    if (myStack.first == nullptr)
    {
        element* new_s= new element;
        (*new_s).value = l.value;
        myStack.first = new_s;
        myStack.last = new_s;
    } else if (myStack.first != nullptr)
    {
        element* new_s = new element;
        (*new_s).value = l.value;
        (*new_s).prev = new_s;
        myStack.last = new_s;

    }
}

element pop(Stack& myStack)
{
    int k = (*myStack.last).value;
    element r;
    element* tmp = new element;
    tmp = myStack.first;
    myStack.first=(*myStack.last).prev;
    delete tmp;
    r.value = k;
    r.prev = myStack.last;
    return r;
}

int main()
{
   Stack mystack;
   constructor(mystack);
   element st_element;
   int k;
    for (int i = 0; i < 5 ; ++i)
    {
        cin >> k;
        st_element.value = k;
        push(mystack, st_element);
    }
    cout <<"Size:" << size(mystack) << endl;
    st_element = pop(mystack);
    cout << "The first element:" << st_element.value << endl;
    st_element = pop(mystack);
    cout << "The first element:" << st_element.value << endl;
    st_element = pop(mystack);
    cout << "The first element:" << st_element.value << endl;
    cout <<"size:" << size(mystack) << endl;
    destructor(mystack);
    return 0;
}
