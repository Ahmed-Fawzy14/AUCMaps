//
// Created by Fawzy on 11/10/2023.
//

#ifndef APPLIED_PROJECT_LINKEDLIST_H
#define APPLIED_PROJECT_LINKEDLIST_H
#pragma once


class LinkedList {


public:

    struct Node
    {
        int data;
        Node* next;

    };

    LinkedList();

    LinkedList(int data);

    int count (Node *p);

    Node* search(Node* p,int key);

    void Append(int x);

private:



    Node* root;

    Node* last;

};


#endif //APPLIED_PROJECT_LINKEDLIST_H
