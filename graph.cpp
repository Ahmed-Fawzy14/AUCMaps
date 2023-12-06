//
// Created by Fawzy on 11/10/2023.
//


#include "graphHeader.h"
<<<<<<< Updated upstream

=======
#include <queue>
#include <unordered_map>
using namespace std;
>>>>>>> Stashed changes

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
            p.trie= t;
            adjList[i].push_back(p);

<<<<<<< Updated upstream
=======
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

/*void Graph::createGraph1(Buildings ind, vector<string> s)
{
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
        string number = {};
        int weight = 0;
        Trie t;
        Node *p = new Node;
        while (sub[i] != ' ') {
            p->name += sub[i];
            i++;
        }
        while (sub[i] != '\0') {
            if (sub[i] != ' ') {
                number += sub[i];
                //then change weight to be an int in the struct and then we can do stoi
            }

            i++;

        }
        //read from file
        p->trie = t;
        for (const std::string &word: s) {
            p->trie.insert(word, "hi", "hi");
            p->weight = stoi(number);
            //test number of loops
            j++;
            adjList[ind].push_back(*p);
            // addNodeToIndexMapping(p->name,ind);
            //nodeToIndexMap[p->name] = j;
            //  cout<<"nodeToIndex: "<<nodeToIndexMap[p->name]<<" j: "<<j<<endl;
        }


    }
}
*/
void Graph::insertInNode(string f, vector<string> s, vector<string> t) const {
    int x = intNodeIndex(f);

    if (x != -1) {

        for (int i = 0; i < s.size() && i < t.size(); i++)
            adjList[x][0].trie.insert(s[i], adjList[x][0].name, t[i]);



    } else {
        return;
    }
}


bool Graph::searchClassroomInNode(string nodeName, const std::string& classroom) const {

    int x = intNodeIndex(nodeName);
    trieNode* p = NULL;

    if (x!=-1)
    {
        bool classroomFound = adjList[x][0].trie.search(classroom, p);
        if (classroomFound)
        {
            cout<<"Classroom '"<<classroom<<" found in node "<<nodeName<<" and its type is "<<p->type<<endl;
            return true;
        } else
        {
            x = intNodeIndex(nodeName + "FirstFloor");
            classroomFound = adjList[x][0].trie.search(classroom, p);
            if (classroomFound)
            {
                string m="";
                m=nodeName + "FirstFloor";
                cout<<"Classroom '"<<classroom<<" found in node "<<m<<" and its type is "<<p->type<<endl;
                return true;
            } else
            {
                x = intNodeIndex(nodeName + "SecondFloor");
                classroomFound = adjList[x][0].trie.search(classroom, p);
                if (classroomFound)
                {
                    string k="";
                    k=nodeName + "SecondFloor";
                    cout<<"Classroom '"<<classroom<<" found in node "<<k<<" and its type is "<<p->type<<endl;
                    return true;
                } else
                {
                    x = intNodeIndex(nodeName + "ThirdFloor");
                    classroomFound = adjList[x][0].trie.search(classroom, p);
                    if (classroomFound)
                    {
                        string n="";
                        n=nodeName + "ThirdFloor";
                        cout<<"Classroom '"<<classroom<<" found in node "<<n<<" and its type is "<<p->type<<endl;
                        return true;
                    }
                }
            }
        }
    }
    cout << "Node " << nodeName << " not found" << endl;
    return false;
}





void Graph::printPath(int startNode, int endNode, const vector<int>& pred) {
    if (endNode == startNode) {
        cout << indexToNodeMap[startNode];
        return;
    }
    if (pred[endNode] == -1) {
        cout << "No path from " << indexToNodeMap[startNode] << " to " << indexToNodeMap[endNode] << endl;
        return;
    }
    printPath(startNode, pred[endNode], pred);
    cout << " -> " << indexToNodeMap[endNode];
}

void Graph::getPath(int startNode, int endNode, const vector<int>& pred, vector<string>& p)
{
    if (endNode == startNode)
    {
        p.push_back(indexToNodeMap[startNode]);
        return;
    }
    if (pred[endNode] == -1)
        return;

    getPath(startNode, pred[endNode], pred, p);
    p.push_back(indexToNodeMap[endNode]);
}

void Graph::dijkstra(int startNode, vector<string>& p, string endNode, int &x) {
    vector<int> dist(size, INT_MAX); // Distance of all nodes from startNode
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> pred(size, -1);

    dist[startNode] = 0;
    pq.push(make_pair(0, startNode)); // (distance, node)

    //cout << "Starting Dijkstra's algorithm from node " << startNode << endl;

    while (!pq.empty()) {
        int distance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        //cout << "Visiting node " << currentNode << " with distance " << distance << endl;

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

            if(nodeIndex == 0){cout<<"LOOK HERE: "<<adjNode.name <<endl;}

           // cout << "Checking adjacent node " << adjNode.name << " (Index: " << nodeIndex << ") with edge weight " << adjNode.weight << endl;

            // Check if a shorter path is found
            if (nodeDistance < dist[nodeIndex]) {
                dist[nodeIndex] = nodeDistance;
                pred[nodeIndex] = currentNode; // Update predecessor
                pq.push(make_pair(nodeDistance, nodeIndex));
              //  cout << "Updating distance of node " << adjNode.name << " to " << nodeDistance << endl;
            }
>>>>>>> Stashed changes
        }

    }

<<<<<<< Updated upstream
}

=======

   // for (int i = 0; i < size; i++) {
      //  if (dist[i] != INT_MAX && i != startNode) {
            //cout << "Path from " << indexToNodeMap[startNode] << " to " << indexToNodeMap[i] << ": ";
            getPath(startNode, intNodeIndex(endNode), pred, p);
            x=dist[intNodeIndex(endNode)];
  //  p.push_back(endNode);
           // cout << endl;
           // cout << "Shortest distance to node " << indexToNodeMap[i] << " is " << dist[i] << endl;
      //  }
   // }


}



void Graph::buildNodeToIndexMap() {
    nodeToIndexMap.clear();
    indexToNodeMap.clear();

    // Assuming that each node appears once in the adjacency list
    // and its index is determined by its position in this list
    for (int i = 0; i < 64; ++i) {

        // The first node in each list represents the node for that index
        string nodeName = adjList[i][0].name; // Assuming the first node in each list is the node itself
        if (nodeToIndexMap.find(nodeName) == nodeToIndexMap.end()) {
            // If it's not in the map, add it
            nodeToIndexMap[nodeName] = i;
            indexToNodeMap[i] = nodeName; // Reverse mapping
        } else {
            // Handle the case where the node already exists in the map, if necessary
            // For example, you might want to print an error message or update the value
        }

        //More than one at index 0


    }


}

int Graph::intNodeIndex(string nodeName) const{
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


>>>>>>> Stashed changes
Graph::~Graph() {



<<<<<<< Updated upstream


}




=======
}
>>>>>>> Stashed changes
