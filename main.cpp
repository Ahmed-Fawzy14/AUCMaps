#include <iostream>
#include "LinkedList.cpp"
#include "LinkedList.h"
#include "graphHeader.h"
#include "Trie.h"




int main() {

    //we need to pair the trie with its wieght maybe using NodeData?

    Graph g(5);
    Trie a;
    Trie b;
    Trie c;
    Trie d;
    Trie e;

    Trie t[5] {a,b,c,d,e};
    string name[5] = {"Plaza", "Jameel", "SSE", "Hatem", "Quick"};
    int weight [5] = {1,2,3,4, 5};
    g.createGraph(name, t, weight);





    return 0;
}
