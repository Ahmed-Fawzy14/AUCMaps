//
// Created by Fawzy on 11/10/2023.
//


#include "graphHeader.h"


Graph::Graph(int size) {

    //Initialize Adj List
    this->size = size;
//    adjList = new LinkedList<Node>[size];

}


string Graph::readFile() {

    string ret;
    string line;
    ifstream file("Data.txt");
    if(!file.is_open())
    {
        cerr<<"File is not open"<<endl;
    }
    else
    {
        while(getline(file, line))
        {
            ret += line + '\n';
        }

    }

    file.close();

    return ret;

}





string Graph::createSub(int &index) {

    string ret = readFile();
    string s;
    int i = index;
//    std::string token = str.substr(0, pos);
    while(ret[i] != ',')
    {
        s += ret[i];
        i++;

    }

    index = i;

    return s;
}




void Graph::createGraph() {

    int index = 0;
    createSub(index);



    for(int i = 0; i<size; i++)
    {
        /*string name;
        int weight;
        Trie t;
        Node p;

        while(0)//not end of line
        {
            p.name = ""; //read from file
            p.weight = 0; //read from file
            p.trie = t.getTrie();
            adjList[i].push_back(p);*/

        //}

    }

}

Graph::~Graph() {





}
