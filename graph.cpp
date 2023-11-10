//
// Created by Fawzy on 11/10/2023.
//


#include "graphHeader.h"


Graph::Graph(int size) {

    //Initialize Adj List
    this->size = size;
    adjList = new LinkedList<Node>[size];

}

void Graph::createGraph(string name[], Trie t[], int weight[]) {


    //for now we are taking a array of all node items and adding them to the list
    //I need to test this

    //this creates the nodes for the buildings but idk about the floors yet
    for(int i = 0; i<size; i++)
    {
        Node *p = new Node(name[i], t[i], weight[i]);
        LinkedList<Node> l(*p);
        adjList[i] = l;

    }

}

Graph::~Graph() {

    delete[] adjList;



}




