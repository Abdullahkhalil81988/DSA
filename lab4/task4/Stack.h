
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

// stack implementation
template <typename T>
class Stack
{
private:
    LinkedList<T> list;

public:
    Stack() {}

    bool isEmpty()
    {
        return list.isEmpty();
    }

    void push(const T &data)
    {
        list.addAtFront(data); // reuse LL function
    }

    void pop()
    {
        if (list.isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        list.removeFront();
    }

    T peek()
    {
        if (list.isEmpty())
        {
            throw runtime_error("Stack is empty!");
        }
        return list.getFront();
    }

    void display()
    {
        cout << "Stack (top to bottom): ";
        list.printList();
    }
};

#endif