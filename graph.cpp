//
// Created by Fawzy on 11/10/2023.
//


#include "graphHeader.h"


Graph::Graph(int size) {

    //Initialize Adj List
    adjLists = new list<Node> [size];

}

void Graph::createGraph(string name[], Trie t[], int weight[]) {



    for(int i = 0; i<size; i++)
    {
        Node *p = new Node(name[i], t[i], weight[i]);
        list<Node> l;
        //LL<node>;


    }


}




