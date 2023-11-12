//
// Created by Fawzy on 11/10/2023.
//


#include "graphHeader.h"


Graph::Graph(int size) {

    //Initialize Adj List
    this->size = size;
//    adjList = new LinkedList<Node>[size];

}

void Graph::createGraph() {

    for(int i = 0; i<size; i++)
    {
        string name;
        int weight;
        Trie t;
        Node p;

        while(0)//not end of line
        {
            p.name = ""; //read from file
            p.weight = 0; //read from file
            p.trie = t.getTrie();
            adjList[i].push_back(p);

        }

    }

}

Graph::~Graph() {





}




