//
// Created by Fawzy on 11/10/2023.
//

#ifndef APPLIED_PROJECT_GRAPHHEADER_H
#define APPLIED_PROJECT_GRAPHHEADER_H

#include <string>
#include <iostream>
#include <vector>
#include "Trie.h"
#include "LinkedList.h"
using namespace std;

class Graph{

private:

    enum Buildings {
    Jameel, SSE,

    };

    struct Node{

        string name;
        Trie trie;
        int weight;

        Node(){

        };

        Node(string name, Trie t, int weight){
            this->name = name;
            this->trie = t;
            this->weight = weight;

        }
    };

    struct NodeData{
        Trie t;
        int weight;

        NodeData(){

        };

        NodeData(Trie t, int weight){
            this->t = t;
            this->weight = weight;
        }
    };

    //Adj List
    int size; //number of buildings
    vector<vector<Node>> adjList;



public:


    Graph();

    Graph(int size);

<<<<<<< Updated upstream
    void createGraph();
=======
    //reads a line and tell you how many elements are in it
    // then use this for the while loop (or a for loop)
    //commas +1
    void getLoop(int commaCount[]);
    void createGraph(Buildings ind);
   // void createGraph1(Buildings ind, vector<string> s);
    void insertInNode(string nodeName, vector<string> s, vector<string> t) const ;
    bool searchClassroomInNode(string nodeName, const std::string& classroom) const;
    vector<string>  readFile(string &theFile);

    string createSub(int &index, string &theFile, Buildings ind);
    void dijkstra(int startNode, vector<string>& p, string endNode, int &x);

    vector<vector<Node> > getAdjlist();

    int intNodeIndex(string nodeName) const;
    map<int, string> indexToNodeMap;

    void printPath(int startNode, int endNode, const vector<int>& pred);
    void getPath(int startNode, int endNode, const vector<int>& pred, vector<string>& p);
>>>>>>> Stashed changes

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
