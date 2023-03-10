#include <iostream>

using namespace std;

template <class T>
class Stack
{
public:

    T stack[5];

    Stack(T vector[], int size);

    int isEmpty (int top);
    int isFull (int top, int size);
    T peek(int top);
    void push (T element, int* top, int size);
    void pop (int* top, T* n);
};

template <class T>
Stack<T>::Stack(T vector[], int size)
{
    int i, top = -1;
    T popped;
    
    // crearea stivei

    for (i = 0; i < size; i++)
    {
        push(vector[i], &top, size);
        cout << "Top element: " << peek(top) << endl;
    }
    push(vector[i], &top, size);
    cout << "\n\n";

    // stergerea elementelor din stiva

    for (i = 0; top >= 0; i++)
    {
        pop(&top, &popped);
        cout << "Popped element: " << popped << endl;
    }
    pop(&top, &popped);
}

template <class T>
int Stack<T>::isEmpty (int top)
{
    if (top == -1)
        return 1;
    else
        return 0;
}

template <class T>
int Stack<T>::isFull(int top, int size)
{
    if (top >= size - 1)
        return 1;
    else
        return 0;
}

template <class T>
T Stack<T>::peek(int top)
{
    return stack[top];
}

template <class T>
void Stack<T>::push(T element, int* top, int size)
{
    if (isFull(*top, size))
    {
        cout << "Stack is full.";
    }
    else if (*top == -1)
    {
        *top = 0;
        stack[0] = element;
    }
    else
    {
        stack[(*top) + 1] = element;
        (*top)++;
    }
}

template <class T>
void Stack<T>::pop(int* top, T* n)
{
    if (isEmpty(*top))
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        *n = stack[*top];
        (*top)--;
    }
}

int main()
{
    int a[5] = { 2, 4, 6, 8, 10 };
    char b[5] = { 'a', 'b', 'c', 'd', 'e' };

    cout << "Int:" << endl;
    Stack <int> stack1(a, 5);
    cout << endl;

    cout << "Char:" << endl;
    Stack <char> stack2(b, 5);
}

