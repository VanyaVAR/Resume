#include <iostream>
#include <stdexcept>

using namespace std;

// Базовый класс, представляющий общий список
class List
{
protected:
    struct Node
    {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;  // Указатель на голову списка
    int size;    // Размер списка (количество элементов)

public:
    // Конструктор: Инициализирует пустой список
    List() : head(nullptr), size(0) {}

    // Чисто виртуальная функция для добавления элемента в список
    virtual void push(int data) = 0;

    // Чисто виртуальная функция для вывода содержимого списка
    virtual void print() const = 0;

    // Функция для удаления элемента из начала списка
    void pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Список пуст");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    // Функция для проверки, пуст ли список
    bool isEmpty() const
    {
        return size == 0;
    }

    // Функция для получения размера списка
    int getSize() const
    {
        return size;
    }

    // Деструктор: Удаляет все элементы из списка
    ~List()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

// Производный класс, представляющий стек (LIFO) с использованием класса List
class Stack : public List
{
public:
    // Функция для добавления элемента в стек
    void push(int data) override
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Функция для вывода элементов стека
    void print() const
    {
        Node* current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Производный класс, представляющий очередь (FIFO) с использованием класса Stack
class Queue : public Stack
{
public:
    // Функция для добавления элемента в очередь
    void enqueue(int data)
    {
        Stack::push(data);
    }

    // Функция для удаления элемента из очереди
    void dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("Очередь пуста");
        }

        Node* current = head;
        Node* prev = nullptr;

        // Проход до конца списка для поиска последнего узла
        while (current->next)
        {
            prev = current;
            current = current->next;
        }

        // Обновление указателя на следующий узел предыдущего узла
        if (prev)
        {
            prev->next = nullptr;
        }
        // Если предыдущего узла нет, значит, в очереди только один элемент
        else
        {
            head = nullptr;
        }

        // Удаление последнего узла и обновление размера
        delete current;
        size--;
    }
};

// Главная функция
int main()
{
    // Создание экземпляров Stack и Queue
    Stack stack;
    Queue queue;

    try
    {
        // Добавление элементов в стек
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);

        // Добавление элементов в очередь
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);

        // Вывод содержимого стека и очереди
        cout << "Стек: ";
        stack.print();
        cout << "Очередь: ";
        queue.print();

        // Удаление элемента из стека
        stack.pop();

        // Удаление элемента из очереди
        queue.dequeue();

        // Вывод измененного стека и очереди
        cout << "Стек после удаления: ";
        stack.print();
        cout << "Очередь после удаления: ";
        queue.print();
    }
    // Обработка исключений времени выполнения
    catch (const runtime_error& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }

    // Возврат 0 для указания успешного выполнения
    return 0;
}
