//
// Created by Fawzy on 11/10/2023.
//


#include "graphHeader.h"


Graph::Graph(int size) {

    //Initialize Adj List
    this->size = size;
    adjList.resize(size);


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




//read file in creatEGraph and send it
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

    //the +1 may mess things up
    index = i+1;

    return s;
}


int Graph::getLoop() {


    return 0;
}



void Graph::createGraph(Buildings ind) {
    ifstream file("Data.txt");
    string line;
    int j = 0;

    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
    }



    int index = 0; //be careful

    //while not end of line
    //this is endling to early
    while (getline(file, line)) {
        //index of substring to get name and weight seperatly
        int i = 0;
        string sub = createSub(index);
        string number= {};
        int weight =0;
        Trie t;
        Node *p = new Node;
        while(sub[i] != ' ')
        {
            p->name += sub[i];
            i++;
        }
        while(sub[i] != '\0')
        {
            if(sub[i]!= ' ')
            {
                number += sub[i];
                //then change weight to be an int in the struct and then we can do stoi
            }

            i++;

        }
        //read from file
        p->trie = t.getTrie();
        p->weight = stoi(number);
        //test number of loops
        j++;
        adjList[ind].push_back(*p);

        delete p;

        }



    }






vector<vector<typename Graph::Node>> Graph::getAdjlist() {
    return adjList;
}


Graph::~Graph() {





}

