#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::cin;

struct element // описание элемента очереди
{
    element* q_next = nullptr;// указатель на следующий элемнт
    int value ;// значение ячейки
};

struct Queue // описание самой очереди
{
    element* first;// указатель на превый элемент
    element* last;// указатель на последний элемент
    int count; // счетчик элементов
};

void constructor(Queue& myQueue) // конструктор
{
    myQueue.first = nullptr;// обнуляем адресс первого элемента
    myQueue.last = nullptr;// обнуляем адресс последнего элемента
    myQueue.count = 0;// обнуляем счетчик
}

void push(Queue& myQueue, element& myelement)// функция заполнения
{
    element* q = new element;// выделяем память под ячейки
    q -> value = myelement.value;
    if (myQueue.first == nullptr)// проверяем на заполненность
    {
        myQueue.first = q;// присваемпервому элементу и конец и начала списка
        myQueue.last = q;
    } else
    {
        myQueue.last -> q_next = q;// присваеваем временной пременной следующее значения
        myQueue.last = q;// присваеваем новому элементу конец очереди
    }
    myQueue.count ++;// счетчик элементов
    
}

unsigned int size(Queue& myQueue)// функция опрделения размера очереди
{
    return myQueue.count;
}

void print(Queue& myQueue)// функция печати
{
    element* temp = myQueue.first;// временная переменная
    while (temp != nullptr)// Условие цикла
    {
        int element = temp -> value;// вытаскиваем значение из первого элемента
        cout << element << " ";// обычный вывод
        temp = temp -> q_next;// переходим к следующему элементу
    }
}

int pop_front(Queue &myQueue)// функция удаления первого элемента
{
    element  *temp = myQueue.first;// временная переменная, чтобы запомнить начало списка
    int k = myQueue.first->value;
    myQueue.first = myQueue.first -> q_next;//назначаем началом списка второй элемент
    delete temp;// удаляем первыйй элемент, записанный во временную переменную
    myQueue.count --;// уменьшаем счетчки элементов
    std::cout << "First element: ";
    return k;
}

void destructor (Queue& myQueue)// деструктор(работает на основе удаления преовго элемента)
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
    int new1;
    int c;
    cout << "Enter the number of element = ";
    cin >> c;
    for (int i = 1; i <= c; ++i)
    {
        cout << "enter " <<"{"<< i << "}"<< " =";
        cin >> new1;
        element.value = new1;
        push(myQueue, element);
    }
    print(myQueue);
    cout << endl;
    cout << "Size:" << size(myQueue) << endl;
    cout << pop_front(myQueue)<<endl;
    cout << "Size:" << size(myQueue) << endl;
    print(myQueue);
    cout << endl;
    destructor(myQueue);
    cout << "Size: " << size(myQueue) << endl;
    return 0;
}
