//
// Created by Fawzy on 11/10/2023.
//

#include "LinkedList.h"
template <typename T>
LinkedList<T>::LinkedList(T data) : root(nullptr), last(nullptr) {
    Node* p;
    p = new Node;
    p->data = data;
    p->next  = nullptr;
    root = p;
    last = p;

}

template <typename T>
int LinkedList<T>::count(Node *p)
{
    if(p==0) //null
    return 0;
    else //may not use else
    return count(p->next) +1; //+1 can be before;

}
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::search(typename LinkedList<T>::Node* p,T key)
{
    while(p != nullptr)
    {
        if(key == p->data)
        return p;
        else
        p = p->next;
    }
    return nullptr;
}

template <typename T>
void LinkedList<T>::Append(T x)
{
    Node* t = new Node;
    t->data = x;
    t->next = nullptr;

    while(last->next != nullptr)
    {

        last = last->next;

    }

    if(root == nullptr)
    {
        root = last = t;
    }
    else
    {
        last->next = t;
        last=t;
    }

}

