//Created by Joudy El Gayar
#include "AStar.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

double AStar::heuristic(const Graph::Node* node, const string& goal) {

    double directDistance = getDirectDistance(node, goal); // calculates distance between a given node and goal
    return directDistance;
}

double AStar::getDirectDistance(const Graph::Node* node, const string& goal) { 

   
    // Find the goal node based on its name
    Graph::Node* goalNode = nullptr;
    for (const Graph::Node& n : graph.getNodes()) {
        if (n.name == goal) {
            goalNode = &n;
            break;
        }
    }

    if (!goalNode) { //if goal node is not found 
        /
        return 0.0;
    }
    double x1 = node->x;
    double y1 = node->y;
    double x2 = goalNode->x;
    double y2 = goalNode->y;

    // Euclidean distance (calculates the distance between the given node and the goal using their coordinates)
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
  
vector<Graph::Node*> AStar::findPath(Graph& graph, string start, string goal) {
    priority_queue<pair<double, Graph::Node*>> openSet;    // use of priority queue and maps 
    unordered_map<Graph::Node*, double> gScore;
    unordered_map<Graph::Node*, Graph::Node*> cameFrom;

    Graph::Node* startNode = nullptr;
    Graph::Node* goalNode = nullptr;

    for (Graph::Node& node : graph.getNodes()) { // find the satrt and goal odes based on their names.
        if (node.name == start) {
            startNode = &node;
        } else if (node.name == goal) {
            goalNode = &node;
        }
    }

    if (!startNode || !goalNode) { 
    
        return vector<Graph::Node*>();
    }

    gScore[startNode] = 0;  // intilaize the gscore to the start node 
    double heuristicValue = heuristic(startNode, goal); // calculate the heuristic value for the start node  and push into the priority queue 
    openSet.push(make_pair(heuristicValue, startNode));

    while (!openSet.empty()) {  
        Graph::Node* current = openSet.top().second;
        openSet.pop();

        if (current == goalNode) { // it will check if the current node is the goal node and if it is true it will contruct the path
            // Reconstruct the path from the goal to the start
            vector<Graph::Node*> path;
            while (current != startNode) {
                path.push_back(current);
                current = cameFrom[current];
            }
            path.push_back(startNode);
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& neighbor : graph.getAdjList()[current - &graph.getNodes()[0]]) { // it will iterate over neighbors of the current node , updating "gScore" and "cameFrom" based on the cost to reach a neighbor
            Graph::Node* next = neighbor.node;
            double tentativeGScore = gScore[current] + neighbor.distance;

            if (!gScore.count(next) || tentativeGScore < gScore[next]) { // it will continue th eloop until the open set is empty 
                gScore[next] = tentativeGScore;
                double priority = tentativeGScore + heuristic(next, goal);
                openSet.push(make_pair(priority, next));
                cameFrom[next] = current;
            }
        }
    }

    // No path found , so empty vector
    return vector<Graph::Node*>();
}