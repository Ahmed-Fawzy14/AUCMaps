//
// Created by Fawzy on 11/27/2023.
//

#ifndef APPLIED_PROJECT_ASTAR_H
#define APPLIED_PROJECT_ASTAR_H
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <list>
#include "graphHeader.h"
using namespace std;



void dijkstra(Graph& graph, const string& sourceName, unordered_map<string, int>& dist, unordered_map<string, string>& predecessors)
{

    //create min heap
    //pq, container, how it is sorted
    //weight, name
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> verticies;


    // Get the number of vertices in graph
    int size = graph.adjList.size();

    // dist values used to pick
    //map not vector for []

    vector<string> allNodeNames;
    allNodeNames.resize(100);

    for(int k =0; k<64; k++)
    {
        allNodeNames[k] = graph.adjList[k][0].name;
    }

    for(int l=0; l<allNodeNames.size(); l++)
    {
        dist[allNodeNames[l]] = INT_MAX;
    }

    dist[sourceName] = 0;
    verticies.push(make_pair(0, sourceName));

    while (!verticies.empty()) {
       string small = verticies.top().second; // Node name with the smallest distance from current source
       cout<<"vercticies top: "<<verticies.top().second<<endl;
        verticies.pop();

        int uIndex = graph.nodeToIndexMap[small];  //why 30 not 2
        cout<<"index: "<<graph.nodeToIndexMap[small]<<" small: "<<small<<endl;


        // Iterate through all neighbors of 'u'
        for (const auto& neighborNode : graph.adjList[uIndex]) {
       //     cout<<"Source Adj List: "<<graph.adjList[uIndex][0].name<<endl;
            cout<<"Source Adj List: "<<neighborNode.name<<endl;
            cout<<"weight before: "<<neighborNode.weight<<endl;
            string v = neighborNode.name;
            int weight = neighborNode.weight;
            cout<<"V: "<<neighborNode.name<<'\t';
            cout<<"weight: "<<neighborNode.weight<<endl;

            // If a shorter path to 'v' is found
            if (dist[small] + weight < dist[v]) {
                dist[v] = dist[small] + weight;
                cout<<"dist[v]: "<< dist[v]<<endl;
                predecessors[v] = small; // Track the predecessor
                cout<<"predecessors[v]: "<< predecessors[v]<<endl;
                verticies.push(make_pair(dist[v], v));
            }
        }
    }
}

void printPath(const unordered_map<string, string>& predecessors, const string& source, const string& target,  unordered_map<string, int> dist) {
    if (source == target) {
        cout << source;
        return;
    }
    if (predecessors.find(target) == predecessors.end()) {
        cout << "No path from " << source << " to " << target << endl;
        return;
    }
    printPath(predecessors, source, predecessors.at(target), dist);
    cout << " -> " << target;
    cout<<" "<<dist[target];
}
#endif //APPLIED_PROJECT_ASTAR_H
