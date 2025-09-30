#include <iostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList();

    void addAtFront(const T &n);
    void printList();
    bool isEmpty();
    void removeFront();
    T getFront();
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}

template <typename T>
void LinkedList<T>::addAtFront(const T &n)
{
    Node<T> *temp = new Node<T>;
    temp->data = n;
    temp->next = head;
    head = temp;
}

template <typename T>
void LinkedList<T>::printList()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << "\t" << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return head == nullptr;
}

template <typename T>
void LinkedList<T>::removeFront()
{
    if (head == nullptr)
        return;
    Node<T> *temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
T LinkedList<T>::getFront()
{
    if (head == nullptr)
        throw runtime_error("List is empty");
    return head->data;
}

#endif