#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <iostream>
#include <stdexcept>

// Adapted from the supplied lecture List<T> implementation.
// Size tracking and getAt() let application code work without Node pointers.
// Template definitions stay in this header so List works with different types.
template <class T>
class List
{
private:
    Node<T>* pHead;
    Node<T>* pTail;
    int size;
    Node<T>* createNode(const T& data);

public:
    List();
    ~List();

    // A list owns its nodes; prevent shallow copies and double deletion.
    List(const List&) = delete;
    List& operator=(const List&) = delete;

    Node<T>* getpHead() const { return pHead; }
    Node<T>* getpTail() const { return pTail; }
    Node<T>* previousNode(Node<T>* pNode) const
    {
        return pNode == nullptr ? nullptr : pNode->pPrev;
    }
    Node<T>* nextNode(Node<T>* pNode) const
    {
        return pNode == nullptr ? nullptr : pNode->pNext;
    }
    T getData(Node<T>* pNode) const;
    Node<T>* NodeAt(int index) const;

    int getSize() const { return size; }
    T& getAt(int index);
    const T& getAt(int index) const;
    void appendNode(const T& value);
    void insertNode(const T& value, Node<T>* pAfter);
    void removeNode(Node<T>* pNode);
    bool isEmpty() const;
    void clear();
    void printList() const;
};

template <class T>
List<T>::List() : pHead(nullptr), pTail(nullptr), size(0)
{
}

template <class T>
List<T>::~List()
{
    clear();
}

template <class T>
Node<T>* List<T>::createNode(const T& data)
{
    return new Node<T>(data);
}

template <class T>
bool List<T>::isEmpty() const
{
    return pHead == nullptr;
}

template <class T>
Node<T>* List<T>::NodeAt(int index) const
{
    if (index < 0 || index >= size)
        return nullptr;

    Node<T>* pNode = pHead;
    int counter = 0;
    while (pNode != nullptr)
    {
        if (counter == index)
            return pNode;
        pNode = pNode->pNext;
        ++counter;
    }
    return nullptr;
}

template <class T>
T List<T>::getData(Node<T>* pNode) const
{
    if (pNode == nullptr)
        throw std::out_of_range("Cannot read an empty node.");
    return pNode->getData();
}

template <class T>
T& List<T>::getAt(int index)
{
    Node<T>* pNode = NodeAt(index);
    if (pNode == nullptr)
        throw std::out_of_range("List index is out of range.");
    return pNode->nData;
}

template <class T>
const T& List<T>::getAt(int index) const
{
    Node<T>* pNode = NodeAt(index);
    if (pNode == nullptr)
        throw std::out_of_range("List index is out of range.");
    return pNode->nData;
}

template <class T>
void List<T>::appendNode(const T& value)
{
    Node<T>* pNode = createNode(value);
    if (isEmpty())
    {
        pHead = pNode;
        pNode->pPrev = nullptr;
    }
    else
    {
        pTail->pNext = pNode;
        pNode->pPrev = pTail;
    }
    pTail = pNode;
    pNode->pNext = nullptr;
    ++size;
}

template <class T>
void List<T>::insertNode(const T& value, Node<T>* pAfter)
{
    // pAfter must belong to this list; nullptr means insert at the front.
    Node<T>* pNode = createNode(value);
    if (pAfter == nullptr)
    {
        pNode->pNext = pHead;
        if (pHead != nullptr)
            pHead->pPrev = pNode;
        else
            pTail = pNode;
        pHead = pNode;
    }
    else
    {
        pNode->pNext = pAfter->pNext;
        pNode->pPrev = pAfter;
        if (pAfter->pNext != nullptr)
            pAfter->pNext->pPrev = pNode;
        else
            pTail = pNode;
        pAfter->pNext = pNode;
    }
    ++size;
}

template <class T>
void List<T>::removeNode(Node<T>* pNode)
{
    // A non-null pNode must belong to this list.
    if (pNode == nullptr)
        return;

    if (pNode->pPrev == nullptr)
        pHead = pNode->pNext;
    else
        pNode->pPrev->pNext = pNode->pNext;

    if (pNode->pNext == nullptr)
        pTail = pNode->pPrev;
    else
        pNode->pNext->pPrev = pNode->pPrev;

    delete pNode;
    --size;
}

template <class T>
void List<T>::clear()
{
    while (!isEmpty())
        removeNode(pHead);
}

template <class T>
void List<T>::printList() const
{
    if (isEmpty())
    {
        std::cout << "The list is empty.\n";
        return;
    }

    for (Node<T>* pNode = pHead; pNode != nullptr; pNode = pNode->pNext)
        std::cout << pNode->nData << '\n';
}

#endif
