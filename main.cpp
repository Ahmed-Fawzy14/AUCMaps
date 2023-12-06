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

<<<<<<< Updated upstream
    // Insert keys
    trie.insert("room 71","SSE", "Classroom");
    trie.insert("room 70","Huss","Bathroom");

    // Search for keys

    cout << "room 71: " << (trie.search("room 71") ? "Found" : "Not Found") << " in building " << trie.loc("room 71") << " Room type: "<<trie.model("room 71")<< endl;
    cout << "room 60: " << (trie.search("room 60") ? "Found" : "Not Found") << " in building " << trie.loc("room 60") << " Room type: "<<trie.model("room 60")<< endl;
    cout << "room 70: " << (trie.search("room 70") ? "Found" : "Not Found") << " in building " << trie.loc("room 70") << " Room type: "<<trie.model("room 70")<< endl;
=======
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


    g.buildNodeToIndexMap();

    vector<std::string> classJamG;
    for (int i = 1; i <= 5; ++i) {
        string cp = "CP" + to_string(i);
        classJamG.push_back(cp);
        cout << classJamG[i - 1] << "  " << endl;
    }

    vector<string> typeJamG={"classroom", "classroom", "classroom", "classroom", "classroom"};



    vector<std::string> classJamF;
    for (int i = 20; i <= 24; ++i) {
        string cp = "CP" + to_string(i);
        classJamF.push_back(cp);
        cout << classJamF.back() << "  " << endl;
    }

    vector<string> typeJamF={"classroom", "classroom", "classroom", "classroom", "classroom"};
    vector<string> typeJamS={"classroom", "classroom", "classroom", "classroom", "classroom"};

    vector<std::string> classJamS;

    for (int i = 30; i <= 34; ++i) {
        string cp = "CP" + to_string(i);
        classJamS.push_back(cp);
        cout << classJamS.back() << "  " << endl;
    }



    string nodeName = "Jameel";
    string startNode="Waleed";
    string endNode= "SSE";
    g.insertInNode("Jameel",classJamG, typeJamG);
    g.insertInNode("JameelFirstFloor",classJamF,typeJamF);
    g.insertInNode("JameelSecondFloor",classJamS,typeJamS);
    g.searchClassroomInNode(nodeName,"CP30");
    std::string classroomToSearch = "your_classroom";
    vector<string> l;
    int y=0;
    g.dijkstra(g.intNodeIndex(startNode),l, endNode, y );

    //for (size_t i = 0; i < l.size(); ++i)
      //  cout<<"Index "<<i<<": "<<l[i]<<endl;


//   Graph p(100); // Assuming 7 nodes in the graph
    //   g.createGraph(Graph::SSE); // Customize with your starting node

  //  Graph::Buildings startNode = Graph::BruceLLudwigFamilySquare;
    //   Graph::Buildings endNode = Graph::SocialResearchCenter;   // Customize with your ending node

    // int shortestDistance = g.findShortestDistance(startNode, endNode, g);
    //working but small but when using start as HatemRoof it acts as if OmarMohsen
    //if you subtract 2 it acts as HatemRoof normally check whats up
    //same thing with OmarMohes as start it goes to +2 Omar
    //at some point a +2 must be happening becuase this does not happen for bruce
    //Gate3 not showing up, probably same error
>>>>>>> Stashed changes




    //g.dijkstra(startNode);

<<<<<<< Updated upstream
    return 0;
}
=======


    bool result = g.searchClassroomInNode(nodeName, classroomToSearch);

    if (result) {
        std::cout << "Classroom '" << classroomToSearch << "' found in node '" << nodeName << "'." << std::endl;
    } else {
        std::cout << "Classroom '" << classroomToSearch << "' not found in node '" << nodeName << "'." << std::endl;
    }

   // cout<<g.findNodeIndex("Jameel");
    // Print the shortest distance between the start and end nodes
//    cout << "Shortest distance from node " << startNode << " to node " << endNode << ": " << shortestDistance << endl;


    return 0;
}
>>>>>>> Stashed changes
