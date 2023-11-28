//
// Created by Fawzy on 11/10/2023.
//


#include "graphHeader.h"
#include <queue>


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
       // addNodeToIndexMapping(p->name,ind);
        //nodeToIndexMap[p->name] = j;
      //  cout<<"nodeToIndex: "<<nodeToIndexMap[p->name]<<" j: "<<j<<endl;
        }





}




void Graph::dijkstra(int startNode) {
    vector<int> dist(size, INT_MAX); // Distance of all nodes from startNode
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[startNode] = 0;
    pq.push(make_pair(0, startNode)); // (distance, node)

    cout << "Starting Dijkstra's algorithm from node " << startNode << endl;

    while (!pq.empty()) {
        int distance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        cout << "Visiting node " << currentNode << " with distance " << distance << endl;

        // Skip the first node in the adjacency list if it represents a self-link
        bool isFirstNode = true;

        // Iterate through all the adjacent nodes of currentNode
        for (auto& adjNode : adjList[currentNode]) {
            // Skip if it's the first node and a self-link
            if (isFirstNode) {
                isFirstNode = false;
                continue;
            }

            int nodeIndex = nodeToIndexMap[adjNode.name]; // Find the index of the adjacent node
            int nodeDistance = distance + adjNode.weight;

            cout << "Checking adjacent node " << adjNode.name << " (Index: " << nodeIndex << ") with edge weight " << adjNode.weight << endl;

            // Check if a shorter path is found
            if (nodeDistance < dist[nodeIndex]) {
                dist[nodeIndex] = nodeDistance;
                pq.push(make_pair(nodeDistance, nodeIndex));
                cout << "Updating distance of node " << adjNode.name << " to " << nodeDistance << endl;
            }
        }
    }

    // Print or process the shortest distances
    for (int i = 0; i < size; i++) {
        if(dist[i] == INT_MAX){

        }
        else
            cout << "Shortest distance to node " << i << " is " << dist[i] << endl;
    }
}



void Graph::buildNodeToIndexMap() {
    nodeToIndexMap.clear();

    // Assuming that each node appears once in the adjacency list
    // and its index is determined by its position in this list
    for (int i = 0; i < 64; ++i) {
        // The first node in each list represents the node for that index
        string nodeName = adjList[i][0].name; // Assuming the first node in each list is the node itself
        nodeToIndexMap[nodeName] = i;
    }


}

int Graph::findNodeIndex(const string& nodeName) {
    auto it = nodeToIndexMap.find(nodeName);

    if (it != nodeToIndexMap.end()) {
        // Node found, return its index
        return it->second;
    } else {
        // Node not found, return an indicator (e.g., -1)
        return -1;
    }
}

void printToIndex(Graph j)
{




}



vector<vector<typename Graph::Node>> Graph::getAdjlist() {
    return adjList;
}





void Graph::print(){

    for(int i = 0; i<adjList.size(); i++)
    {
        for (int j = 0; j<adjList[i].size(); j++)
        {
            cout<<adjList[i][j].name<<"-> "<<adjList[i][j].weight;
        }
        cout<<endl;
    }



}


Graph::~Graph() {



}

