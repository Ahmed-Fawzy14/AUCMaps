//
// Created by Fawzy on 11/16/2023.
//

#ifndef APPLIED_PROJECT_ASTAR_H
#define APPLIED_PROJECT_ASTAR_H

//Created by Joudy El Gayar
#ifndef ASTAR_H
#define ASTAR_H

#include "GraphHeader.h"
#include <vector>
using namespace std;

class AStar {
public:
    static vector<typename Graph::Node*> findPath(Graph& graph, string start, string goal);

private:
    static double heuristic(const Graph::Node* node, const string& goal);
    static double getDirectDistance(const Graph::Node* node, const string& goal);


    };

#endif // ASTAR_H

#endif //APPLIED_PROJECT_ASTAR_H
