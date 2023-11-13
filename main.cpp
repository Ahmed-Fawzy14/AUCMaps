#include <iostream>
#include "LinkedList.cpp"
#include "LinkedList.h"
#include "graphHeader.h"
#include "Trie.h"




int main() {

    //we need to pair the trie with its wieght maybe using NodeData?

    Graph g(25);
    int i = 0;
   // g.createSub(i);
   //there are two or so missing nodes
    g.createGraph(g.BruceLLudwigFamilySquare);
    g.createGraph(g.DrHamzaAlKohliInformationCentre);
    g.test = g.getAdjlist();



    return 0;
}
