//
// Created by Fawzy on 11/10/2023.
//


#include "graphHeader.h"


Graph::Graph(int size) {

    //Initialize Adj List
    this->size = size;
    adjList.resize(size);


}


vector<string> Graph::readFile(string &theFile) {

    string ret;
    vector<string> str;
    str.resize(size);
    string line;
    ifstream file("Data.txt");
    int i =0;
    if(!file.is_open())
    {
        cerr<<"File is not open"<<endl;
    }
    else
    {
        while(getline(file, line))
        {
            str[i] += line + '\n';
            i++;
        }

    }

    file.close();

    //theFile = ret;

    return str;

}


//vector<string> s (each index is one line)
//s[ind]


//read file in creatEGraph and send it
string Graph::createSub(int &index, string &theFile, Buildings ind) {
    vector<string> ret = readFile(theFile);
    string s;
    int i = index;
    while(i < ret[ind].length() && (ret[ind])[i] != ',') {
        s += (ret[ind])[i];
        i++;
    }

    if (i == ret[ind].length()) {
        index = 0;
    } else {
        index = i + 1;
    }

    return s;
}



void Graph::getLoop(int commaCount[]) {
    ifstream file("Data.txt");
    string line;
    int i = 0;

    if (file.is_open()) {
        while(getline(file, line)) {
            commaCount[i] = count(line.begin(), line.end(), ',');
            i++;
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }

}



void Graph::createGraph(Buildings ind) {
    ifstream file("Data.txt");
    string line;
    string theFile;

    int commaCount[100];

    getLoop(commaCount);

    int j = 0;

    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
    }



    int index = 0; //be careful

    //the next index reads from the same area in the text file not the next line
    while (j<commaCount[ind]) {
        //index of substring to get name and weight seperatly
        int i = 0;
        string sub = createSub(index, theFile, ind);
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
        p->trie = t;
        p->weight = stoi(number);
        //test number of loops
        j++;
        adjList[ind].push_back(*p);


        }



    }






vector<vector<typename Graph::Node>> Graph::getAdjlist() {
    return adjList;
}


Graph::~Graph() {



}

