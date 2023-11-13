#include <iostream>
#include "LinkedList.cpp"
#include "LinkedList.h"
#include "graphHeader.h"
#include "Trie.h"




int main() {

    //we need to pair the trie with its wieght maybe using NodeData?

    Graph g(25);
    int i = 0;


   g.createGraph(g.BruceLLudwigFamilySquare);

    g.createGraph(g.DrHamzaAlKohliInformationCentre);
    g.test = g.getAdjlist();

    //segmentation fault idk why
    g.createGraph(g.Gate1);
    g.test = g.getAdjlist();

    g.createGraph(g.AllamAmphitheatre);
    g.test = g.getAdjlist();

    g.createGraph(g.SchoolOfContinuingEducation);
    g.test = g.getAdjlist();



    return 0;
}
