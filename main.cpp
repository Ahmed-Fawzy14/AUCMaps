#include <iostream>
#include "Trie.h"
#include "Astar.h"
#include <queue>
#include <unordered_map>
#include <vector>
#include <limits>


vector<vector<int>> convert(const vector<vector<Graph::Node>>& adjList, const unordered_map<string, int>& nodeToIndexMap)
{
    int n = nodeToIndexMap.size(); // Number of nodes
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // Initialize matrix with 0s

    for (int i = 0; i < adjList.size(); ++i) {
        for (const auto& node : adjList[i]) {
            int j = nodeToIndexMap.at(node.name); // Get the index of the node
            matrix[i][j] = node.weight; // Set the weight in the matrix
        }
    }

    return matrix;
}
// Function to display adjacency matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}




int main() {


    Graph g(100);
    int i = 0;


    g.createGraph(g.BruceLLudwigFamilySquare);
    g.createGraph(g.DrHamzaAlKohliInformationCentre);
    g.createGraph(g.Gate1);
    g.createGraph(g.AllamAmphitheatre);
    g.createGraph(g.SchoolOfContinuingEducation);
    g.createGraph(g.Jameel);
    g.createGraph(g.JameelFirstFloor);
    g.createGraph(g.JameelSecondFloor);
    g.createGraph(g.BusGate);
    g.createGraph(g.SSE);
    g.createGraph(g.SSEFirstFloor);
    g.createGraph(g.SSESecondFloor);
    g.createGraph(g.SSERoof);
    g.createGraph(g.SSEPlaza);
    g.createGraph(g.Hatem);
    g.createGraph(g.HatemFirstFloor);
    g.createGraph(g.HatemSecondFloor);
    g.createGraph(g.HatemThird);
    g.createGraph(g.HatemRoof);
    g.createGraph(g.Quick);
    g.createGraph(g.OmarMohsen);
    g.createGraph(g.Waleed);
    g.createGraph(g.WaleedFirstFloor);
    g.createGraph(g.WaleedSecondFloor);
    g.createGraph(g.AUCCenterForArts);
    g.createGraph(g.ArtFF);
    g.createGraph(g.TabaliPlaza);
    g.createGraph(g.ArtsGate);
    g.createGraph(g.Gate5);
    g.createGraph(g.SocialResearchCenter);
    g.createGraph(g.AUCPortal);
    g.createGraph(g.WatsonHouse);
    g.createGraph(g.LinkPlaza);
    g.createGraph(g.Administration);
    g.createGraph(g.AdministrationGarden);
    g.createGraph(g.AdministrationFirstFloor);
    g.createGraph(g.AdministrationSecondFloor);
    g.createGraph(g.WestGarden);
    g.createGraph(g.BarlettPlaza);
    g.createGraph(g.Library);
    g.createGraph(g.LibraryGarden);
    g.createGraph(g.LibraryFirstFloor);
    g.createGraph(g.LibrarySecondFloor);
    g.createGraph(g.LibraryThirdFloor);
    g.createGraph(g.CVC);
    g.createGraph(g.CampusCenter);
    g.createGraph(g.EastGarden);
    g.createGraph(g.NorthGarden);
    g.createGraph(g.GardensGate);
    g.createGraph(g.Gate2);
    g.createGraph(g.AUCResid);
    g.createGraph(g.AUCResidFF);
    g.createGraph(g.AUCResidSS);
    g.createGraph(g.SportsPlaza);
    g.createGraph(g.EastEntrance);
    g.createGraph(g.SportsComplex);
    g.createGraph(g.PepsiGate);
    g.createGraph(g.Gate4);
    g.createGraph(g.ArnoldPavillion);
    g.createGraph(g.SportGate);
    g.createGraph(g.IndoorSports);
    g.createGraph(g.SportsFF);
    g.createGraph(g.ComplexPool);
    g.createGraph(g.ComplexOutdoor);
    g.createGraph(g.Gate3);

   g.test = g.getAdjlist();
  // g.print();
   unordered_map<string, string> predecessors;
   unordered_map<string, int> dist;
   dijkstra(g, "Library", dist, predecessors);
   printPath(predecessors, "Library", "LibraryThirdFloor", dist);

//    vector<vector<int>> t = convert(g.getAdjlist(),g.nodeToIndexMap);



    return 0;
}

