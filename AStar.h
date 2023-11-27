//
// Created by Fawzy on 11/24/2023.
//

#ifndef APPLIED_PROJECT_ASTAR_H
#define APPLIED_PROJECT_ASTAR_H
// AStar.h

#include "graphHeader.h"//  for the node def
#include<vector>


class AStar {
public:

    struct AStarNode {
         Graph::Node node;
        double cost;       // Cost from the start node to this node
        double heuristic;  // Heuristic estimate from this node to the goal
        bool operator<(const AStarNode& other) const {
            return cost + heuristic > other.cost + other.heuristic;
        }
    };

    void aStar(const  Graph::Node& start, const Graph::Node& goal, const vector<vector< Graph::Node> >& adjList);
    const vector< Graph::Node>& getOptimalPath() const;
    double calculateHeuristic(const  typename Graph::Node& current, const typename Graph::Node& goal);
    void reconstructPath(const typename Graph::Node& start, const  typename Graph::Node& goal, const vector<vector< Graph::Node> >& adjList);
    vector< Graph::Node> optimalPath;
    double getOptimalCost() const;
    double totalCost;
private:




};



#endif //APPLIED_PROJECT_ASTAR_H






