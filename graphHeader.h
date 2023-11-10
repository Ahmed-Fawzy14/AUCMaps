//
// Created by Fawzy on 11/10/2023.
//

#ifndef APPLIED_PROJECT_GRAPHHEADER_H
#define APPLIED_PROJECT_GRAPHHEADER_H

#include <string>
#include "Trie.h"
using namespace std;

class Graph{

private:

    struct Node{

        string name;
        Trie t; //all classes on the floor
//For Jameel node Trie will have all nodes on ground floor
//For first floor node in Jameel will have all nodes on first floor
//etc.

    };



public:


    Graph();


    ~Graph();

};





#endif //APPLIED_PROJECT_GRAPHHEADER_H
