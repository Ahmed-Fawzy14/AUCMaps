//
// Created by Fawzy on 11/10/2023.
//

#ifndef APPLIED_PROJECT_GRAPHHEADER_H
#define APPLIED_PROJECT_GRAPHHEADER_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Trie.h"
#include "LinkedList.h"
using namespace std;

class Graph{

private:


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

    enum Buildings {
        BruceLLudwigFamilySquare, DrHamzaAlKohliInformationCentre, Gate1, AllamAmphitheatre, SchoolOfContinuingEducation, Jameel, JameelFirstFloor, JameelSecondFloor, BusGate, SSE, SSEFirstFloor, SSESecondFloor, SSERoof, SSEPlaza, Hatem, HatemFirstFloor, HatemSecondFloor, HatemThird, HatemRoof, Quick, OmarMohsen, Waleed, WaleedFirstFloor, WaleedSecondFloor,AUCCenterForArts,ArtFF,TabaliPlaza,ArtsGate,Gate5,SocialResearchCenter,AUCPortal,WatsonHouse,LinkPlaza,Administration,AdministrationGarden,AdministrationFirstFloor,AdministrationSecondFloor,WestGarden,BarlettPlaza,Library,LibraryGarden,LibraryFirstFloor,LibrarySecondFloor,LibraryThirdFloor

    };



    vector<vector<Node>> test;


    Graph();

    Graph(int size);

    //reads a line and tell you how many elements are in it
    // then use this for the while loop (or a for loop)
    //commas +1
    void getLoop(int commaCount[]);

    void createGraph(Buildings ind);

    vector<string>  readFile(string &theFile);

    string createSub(int &index, string &theFile, Buildings ind);

    vector<vector<Node>> getAdjlist();

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
