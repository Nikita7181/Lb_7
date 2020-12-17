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

void print_element(element* myStack)
{
    if (myStack != nullptr)
    {
        print_element(myStack -> prev);
        cout << myStack -> value << " ";
    }
}

void print_struct(Stack& myStack)
{
    print_element(myStack.last);
    std::cout << std::endl;
}

void del_elem(element* myStack)
{
    if (myStack != nullptr)
    {
        del_elem(myStack -> prev);
        delete myStack;
    }
}

int main()
{
    Stack myStack;
    constructor(myStack);
    element element;
    int a;
    for (int i = 0; i < 5; ++i) {
        std::cin >> a;
        element.value = a;
        push(myStack, element);
    }
    print_struct(myStack);
    cout << "there is " << size(myStack) << " in stack." << endl;
    element = pop(myStack);
    cout << "Get the last element from stack. It is " << element.value << endl;
    print_struct(myStack);
    element = pop(myStack);
    cout << "Get the last element from stack. It is " << element.value << endl;
    print_struct(myStack);
    element = pop(myStack);
    cout << "Get the last element from stack. It is " << element.value << endl;
    print_struct(myStack);
    std::cout << "there is " << size(myStack) << " in stack." << endl;
    std::cin >> a;
    element.value = a;
    push(myStack, element);
    std::cout << "there is " << size(myStack) << " in stack." << endl;
    element = pop(myStack);
    cout << "Get the last element from stack. It is " << element.value << endl;
    cout << "there is " << size(myStack) << " in stack." << endl;
    print_struct(myStack);
    destructor(myStack);
    return 0;

}
