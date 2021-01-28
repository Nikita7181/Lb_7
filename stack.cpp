#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::cin;

struct element // описание элемента стек
{
    element* prev = nullptr; // указатель на предыдущий элемент
    int value; // ячейка для хранения информации
};

struct Stack // описание самого стека
{
    element* last;// указатель на последний элемент
    int count; // счетчик элементов
};

void constructor(Stack& myStack)// конструктор
{
    myStack.last= nullptr;// обнуляем адресс последнего элемента
    myStack.count= 0;// обнуляем счетчик
}

void destructor(Stack& myStack)// деструктор(работает, как pop)
{
    while (myStack.last != nullptr)
    {
        element* tmp;
        tmp=myStack.last;
        myStack.last=myStack.last -> prev;
        delete tmp;
        myStack.count --;
    }
}

unsigned int size(Stack& myStack)// функция для вывода размера стек
{
    return myStack.count;// обращение к счетчику элемнтов
}

void push(Stack& myStack, element& myelement)
{
    element* tmp = new element;// выделяем память под ячейки
    tmp -> value = myelement.value;
    if (myStack.last == nullptr)// проверяем на заполненность
    {// присваемпервому элементу и конец и начала стекаж
        myStack.last = tmp;
    }
    else
    {
        tmp -> prev = myStack.last;// присваеваем временной пременной предыдущее значения
        myStack.last = tmp;// присваеваем новому элементу конец стека
    }
    myStack.count ++; // счетчик элементов
}

int pop_last(Stack& myStack)// функция удаления последнего элемента
{
    int k = myStack.last -> value;
    element  *temp = myStack.last;// временная переменная, чтобы запомнить конец списка
    myStack.last = myStack.last -> prev;//назначаем концом списка второй элемен
    delete temp;// удаляем последний элемент, записанный во временную переменную
    myStack.count --;// уменьшаем счетчик
    cout << "Last element: ";
    return k;
}

void print(Stack& myStack)// функция печати
{
    element * temp = myStack.last;
    while (temp != nullptr)
    {
        int element = temp -> value;// вытаскиваем значение из последнего элемента
        cout << element << endl;// обычный вывод
        temp = temp -> prev;// переходим к предыдущему элементу
    }
    
}

int main()
{
    Stack myStack;
    constructor(myStack);
    element myelement;
    int new1;
    int k;
    cout << "Enter the number of element = ";
    cin >> k;
    for (int i = 1; i <= k; ++i)
    {
        cout << "enter " << "{"<< i << "}" << " =";
        cin >> new1;
        myelement.value = new1;
        push(myStack, myelement);
    }
    print(myStack);
    cout << "Size:" << size(myStack) << endl;
    cout << pop_last(myStack);
    cout << endl;
    cout << "Size:" << size(myStack) << endl;
    print(myStack);
    destructor(myStack);
    cout << "Size:" << size(myStack) << endl;
    return 0;
}
