#include <iostream>
#include "LinkedList.cpp"
#include "LinkedList.h"
#include "graphHeader.h"
#include "Trie.h"




int main() {

    //we need to pair the trie with its wieght maybe using NodeData?

    Graph g(100);
    int i = 0;


    g.createGraph(g.BruceLLudwigFamilySquare);
    cout<<1<<endl;
    g.createGraph(g.DrHamzaAlKohliInformationCentre);
    cout<<1<<endl;
    g.createGraph(g.Gate1);
    cout<<1<<endl;
    g.createGraph(g.AllamAmphitheatre);
    cout<<1<<endl;
    g.createGraph(g.SchoolOfContinuingEducation);
    cout<<1<<endl;
    g.createGraph(g.Jameel);
    cout<<1<<endl;
    g.createGraph(g.JameelFirstFloor);
    cout<<1<<endl;
    g.createGraph(g.JameelSecondFloor);
    cout<<1<<endl;
    g.createGraph(g.BusGate);
    cout<<1<<endl;
    g.createGraph(g.SSE);
    cout<<1<<endl;
    g.createGraph(g.SSEFirstFloor);
    cout<<1<<endl;
    g.createGraph(g.SSESecondFloor);
    cout<<1<<endl;
    g.createGraph(g.SSERoof);
    cout<<1<<endl;
    g.createGraph(g.SSEPlaza);
    cout<<1<<endl;
    g.createGraph(g.Hatem);
    cout<<1<<endl;
    g.createGraph(g.HatemFirstFloor);
    cout<<1<<endl;
    g.createGraph(g.HatemSecondFloor);
    cout<<1<<endl;
    g.createGraph(g.HatemThird);
    cout<<1<<endl;
    g.createGraph(g.HatemRoof);
    cout<<1<<endl;
    g.createGraph(g.Quick);
    cout<<1<<endl;
    g.createGraph(g.OmarMohsen);
    cout<<1<<endl;
    g.createGraph(g.Waleed);
    cout<<1<<endl;
    g.createGraph(g.WaleedFirstFloor);
    cout<<1<<endl;
    g.createGraph(g.WaleedSecondFloor);
    cout<<1<<endl;
    g.test = g.getAdjlist();

    return 0;
}
