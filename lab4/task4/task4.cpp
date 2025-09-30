#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T val)
    {
        data = val;
        next = NULL;
    }
};

template <typename T>
class MyStack
{
    Node<T> *top;
    int size;

public:
    MyStack()
    {
        top = NULL;
        size = 0;
    }

    ~MyStack()
    {
        while (top != NULL)
        {
            Node<T> *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(T val)
    {
        Node<T> *temp = new Node<T>(val);
        temp->next = top;
        top = temp;
        cout << "Pushed " << val << " to the stack\n";
        size++;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }
        T val = top->data;
        Node<T> *temp = top;
        top = top->next;
        cout << "Popped " << val << " from the stack\n";
        delete temp;
        size--;
    }

    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top element is " << top->data << endl;
    }

    bool IsEmpty()
    {
        return top == NULL;
    }
};

int main()
{
    // Integer stack example
    MyStack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    s.pop();
    s.peek();

    cout << "Is empty: " << s.IsEmpty() << endl;

    // String stack example
    cout << "\nString stack example:\n";
    MyStack<string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.peek();
    stringStack.pop();

    // Character stack example
    cout << "\nCharacter stack example:\n";
    MyStack<char> charStack;
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    charStack.peek();
    charStack.pop();

    return 0;
}