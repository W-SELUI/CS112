#ifndef NODE_H
#define NODE_H

// Based on the Node<T> class supplied in the lecture sample.
template <class T>
class List;

template <class T>
class Node
{
    friend class List<T>;

private:
    T nData;
    Node<T>* pNext;
    Node<T>* pPrev;

public:
    explicit Node(const T& data)
        : nData(data), pNext(nullptr), pPrev(nullptr)
    {
    }

    T getData() const
    {
        return nData;
    }
};

#endif
