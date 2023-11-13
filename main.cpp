#include <iostream>
#include "LinkedList.cpp"
#include "LinkedList.h"
#include "graphHeader.h"
#include "Trie.h"




int main() {
/*
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

*/

/*
 Trie test case*/


    Trie trie;

    // Insert keys
    trie.insert("room 71","SSE");
    trie.insert("room 70","Huss");

    // Search for keys

    cout << "room 71: " << (trie.search("room 71") ? "Found" : "Not Found") << " in building " << trie.loc("room 71") << endl;
    cout << "room 60: " << (trie.search("room 60") ? "Found" : "Not Found") << " in building " << trie.loc("room 60") << endl;
    cout << "room 70: " << (trie.search("room 70") ? "Found" : "Not Found") << " in building " << trie.loc("room 70") << endl;





    return 0;
}
