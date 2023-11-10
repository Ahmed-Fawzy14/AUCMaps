//
// Created by Fawzy on 11/10/2023.
//

#ifndef APPLIED_PROJECT_LINKEDLIST_H
#define APPLIED_PROJECT_LINKEDLIST_H
#pragma once

template <typename T>
class LinkedList {


public:

    struct NodeL
    {
        T data;
        NodeL* next;

    };

    LinkedList();

    LinkedList(T data);

    int count (NodeL *p);

    NodeL* search(NodeL* p,T key);

    void Append(T x);

    void Delete();

    NodeL* getRoot();

    ~LinkedList();


private:



    NodeL* root;

    NodeL* last;

};


//
// Created by Fawzy on 11/10/2023.
//

template <typename T>
LinkedList<T>::LinkedList(T data) : root(nullptr), last(nullptr) {
    NodeL* p;
    p = new NodeL;
    p->data = data;
    p->next  = nullptr;

    root = p;
    last = p;

}

template<typename T>
LinkedList<T>::LinkedList() {

}


template <typename T>
int LinkedList<T>::count(NodeL *p)
{
    if(p==0) //null
        return 0;
    else //may not use else
        return count(p->next) +1; //+1 can be before;

}
template <typename T>
typename LinkedList<T>::NodeL* LinkedList<T>::search(typename LinkedList<T>::NodeL* p,T key)
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
    NodeL* t = new NodeL;
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


template<typename T>
typename LinkedList<T>::NodeL *LinkedList<T>::getRoot() {
    return root;
}


template<typename T>
LinkedList<T>::~LinkedList() {

    NodeL* current = root;
    while (current != nullptr) {
        NodeL* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}







#endif //APPLIED_PROJECT_LINKEDLIST_H
