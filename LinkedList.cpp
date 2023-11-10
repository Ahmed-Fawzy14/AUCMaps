//
// Created by Fawzy on 11/10/2023.
//

#include "LinkedList.h"

LinkedList::LinkedList(int data) {
    Node* p;
    p = new Node;
    p->data = data;
    p->next  = nullptr;
    root = p;
    last = p;

}

int LinkedList::count(Node *p)
{
    if(p==0) //null
    return 0;
    else //may not use else
    return count(p->next) +1; //+1 can be before;

}

typename LinkedList::Node* LinkedList::search(typename LinkedList::Node* p,int key)
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

void LinkedList::Append(int x)
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

