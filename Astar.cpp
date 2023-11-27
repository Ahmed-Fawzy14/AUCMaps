// AStar.cpp
#include "AStar.h"
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void AStar::aStar(const Graph::Node &start, const Graph::Node &goal, const vector<vector<Graph::Node>> &adjList) {
    totalCost = 0.0;
    vector<AStarNode> openSet; // contains start node with cost 0
    vector<typename Graph::Node> closedSet; // nodes that have been processed
    // vector<typename Graph::Node> closedSet;

    openSet.push_back({start, 0.0, calculateHeuristic(start, goal)}); // adds start node to the open set
// algo iterates until the open set is empty or goal node is reached
    while (!openSet.empty()) {
        // Find the node with the lowest cost in openSet
        auto minCostNodeIt = min_element(openSet.begin(), openSet.end(), [](const AStarNode &a, const AStarNode &b) {
            return (a.cost + a.heuristic) < (b.cost + b.heuristic);
        });


        AStarNode current = *minCostNodeIt;
        openSet.erase(minCostNodeIt); // Remove the node from openSet

        if (current.node == goal) { // Goal reached
            // Reconstruct the path
            reconstructPath(start, goal, adjList);
            break;
        }

        closedSet.push_back(
                current.node); // adds the current node to the closed set and finds the index of the current node in the adjacency list.

        size_t currentIndex = 0;
        for (size_t i = 0; i < adjList.size(); ++i) {
            for (const typename Graph::Node &node: adjList[i]) {
                if (current.node == node) {
                    currentIndex = i;
                    break;
                }
            }
        }

// it expands the neighbors of the current node, calculates tentative costs, and updates the open set if a lower cost is found.
        for (const Graph::Node &neighbor: adjList[currentIndex]) {
            if (find(closedSet.begin(), closedSet.end(), neighbor) != closedSet.end()) {
                continue;  // Ignore nodes in the closed set
            }

            double tentativeCost = current.cost + neighbor.weight;
            totalCost += tentativeCost;


            // Check if neighbor is in the open set

            auto inOpenSetIt = find_if(openSet.begin(), openSet.end(), [&neighbor](const AStarNode &node) {
                return node.node == neighbor;
            });

            if (inOpenSetIt == openSet.end() || tentativeCost < inOpenSetIt->cost) {
                openSet.push_back({neighbor, tentativeCost, calculateHeuristic(neighbor, goal)});
            }
        }


    }
}
const vector<Graph::Node> &AStar::getOptimalPath() const {
    return optimalPath;
}

double AStar::calculateHeuristic(const Graph::Node &current, const Graph::Node &goal) {

    double positionDifference = abs(current.weight - goal.weight);
    return positionDifference;

}
double AStar:: getOptimalCost()const{
    return totalCost;
}

void AStar::reconstructPath(const Graph::Node &start, const Graph::Node &goal, const vector<vector<Graph::Node>> &adjList) {
// Reconstruct the path using the graph structure
    optimalPath.clear();
    typename Graph::Node current = goal;

    while (current != start) {
        optimalPath.push_back(current);

        int i = 0; //INDEX
        // finding the predecessor in the adjacency list
        for (const typename Graph::Node &neighbor: adjList[i]) {
            if (optimalPath.back() == neighbor) {
                current = neighbor;
                break;
            }
        }
    }

    // Add the start node to the path
    optimalPath.push_back(start);

    // Reverse the path so that it goes from start to goal
    reverse(optimalPath.begin(), optimalPath.end());
}

