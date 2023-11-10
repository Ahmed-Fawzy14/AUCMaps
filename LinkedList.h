//
// Created by Fawzy on 11/10/2023.
//

#ifndef APPLIED_PROJECT_LINKEDLIST_H
#define APPLIED_PROJECT_LINKEDLIST_H
#pragma once

template <typename T>
class LinkedList {


public:

    struct Node
    {
        T data;
        Node* next;

    };

    LinkedList();

    LinkedList(T data);

    int count (Node *p);

    Node* search(Node* p,T key);

    void Append(T x);

private:



    Node* root;

    Node* last;

};


#endif //APPLIED_PROJECT_LINKEDLIST_H
