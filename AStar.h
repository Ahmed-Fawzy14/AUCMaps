//Created by Joudy El Gayar
#ifndef ASTAR_H
#define ASTAR_H

#include "GraphHeader.h"
#include <vector>
using namespace std;

class AStar {
public:
    static vector<Graph::Node*> findPath(Graph& graph, string start, string goal);

private:
    static double heuristic(const Graph::Node* node, const string& goal);
    static double getDirectDistance(const Graph::Node* node, const string& goal);
};

#endif // ASTAR_H
