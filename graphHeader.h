//
// Created by Fawzy on 11/10/2023.
//

#ifndef APPLIED_PROJECT_GRAPHHEADER_H
#define APPLIED_PROJECT_GRAPHHEADER_H

#include <string>
#include <iostream>
#include <list>
#include "Trie.h"
using namespace std;

class Graph{

private:

    struct Node{

        string name;
        Trie t;
        int weight;

        Node();

        Node(string name, Trie t, int weight){
            this->name = name;
            this->t = t;
            this->weight = weight;

        }
    };

    //Adj List
    int size;
    list<Node> *adjLists;



public:


    Graph();

    Graph(int size);

    //need a funciton to initalize all nodes
    //give the node its name
    //give the node its respective trie
    //give the node its weight from the root node
    //(JAMEEL, t0, 0) -> (FF, t1, 1) -> (SF, t2, 2) -> (ROOF, t3, 3)
    //Name and weight can be gotten from a file
    //Trie needs to be sent from main function



    ~Graph();

};



#endif //APPLIED_PROJECT_GRAPHHEADER_H
