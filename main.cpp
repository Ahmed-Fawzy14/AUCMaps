#include <iostream>
#include "Trie.h"
#include "Astar.h"
#include <queue>
#include <unordered_map>
#include <vector>
#include <limits>
#include <string>
using namespace std;


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




int main()
{

    Graph g(80);
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
    g.buildNodeToIndexMap();





//JAMEEL

//Ground
    vector<std::string> classGround;
    for (int i = 1; i <= 32; ++i) {

        if(i == 1)
        {
            string build = "Go to Building";
            classGround.push_back(build);
            string cp = "CP" + to_string(i);
            classGround.push_back(cp);
            //cout << classGround[i - 1] << "  " << endl;
        }
        else
        {
            string cp = "CP" + to_string(i);
            classGround.push_back(cp);
            //cout << classGround[i - 1] << "  " << endl;
        }

    }


    vector<string> typeJamG={"Building","Classroom", "Classroom", "Classroom", "Classroom", "Classroom",
                             "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Men's Bathroom", "Women's Bathroom",
                             "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom",
                             "Classroom", "Office", "Office", "Office", "Office", "Office"};


//FF
    vector<std::string> classFirst;
    for (int i = 1; i <= 30; ++i) {

        if(i<=15)
        {
            string cp = "10" + to_string(i);
            classFirst.push_back(cp);
            // cout << classFirst.back() << "  " << endl;
        }
        else
        {
            string cp = "P0" + to_string(i);
            classFirst.push_back(cp);
            //  cout << classFirst.back() << "  " << endl;

        }

    }

    vector<string> typeJamF={"Classroom","Classroom", "Classroom", "Classroom", "Classroom", "Classroom",
                             "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Men's Bathroom", "Women's Bathroom",
                             "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom",
                             "Classroom", "Office", "Office", "Office", "Office", "Office"};

    //SS
    vector<std::string> classSecond;

    for (int i = 1; i <= 31; ++i) {
        string cp = "20" + to_string(i);
        classSecond.push_back(cp);
        //cout << classSecond.back() << "  " << endl;
    }


    vector<string> typeJamS={"Classroom","Classroom", "Classroom", "Classroom", "Classroom", "Classroom",
                             "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Men's Bathroom", "Women's Bathroom",
                             "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom",
                             "Classroom", "Office", "Office", "Office", "Office", "Office"};



///////////////////////////////////////////////////
//SSE

    string cp = "";




////////////////////////////////////////////////
    string nodeName = "SSE";
    string startNode="Waleed";
    string endNode= "AUCPortal";
    g.insertInNode("Jameel",classGround, typeJamG);
    g.insertInNode("JameelFirstFloor",classFirst,typeJamF);
    g.insertInNode("JameelSecondFloor",classSecond,typeJamS);


    typeJamF={"Classroom","Classroom", "Classroom", "Classroom", "Classroom", "Classroom",
              "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Men's Bathroom", "Women's Bathroom",
              "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom",
              "Office", "Office", "Office", "Office", "Office", "Lab", "Lab", "Lab", "Lab", "Lab"};


    vector<string> AdminGround = classGround;
    vector<string> AdminFF = classFirst;
    vector<string> AdminSF = classSecond;




    //First Floor
    for (int i = 1; i <= 5; ++i) {
        string kj = "Physics Lab " + to_string(i);
        classFirst.push_back(kj);
        //   cout << classFirst.back() << "  " << endl;
    }



//Second Floor
    for (int i = 1; i <= 5; ++i) {
        string cp = "Computer Lab " + to_string(i);
        classSecond.push_back(cp);
        // cout << classSecond.back() << "  " << endl;
    }

    typeJamS={"Classroom","Classroom", "Classroom", "Classroom", "Classroom", "Classroom",
              "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Men's Bathroom", "Women's Bathroom",
              "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom",
              "Classroom", "Office", "Office", "Office", "Office","Office", "Lab", "Lab", "Lab", "Lab", "Lab"};


    g.insertInNode("SSE",classGround, typeJamG);
    g.insertInNode("SSEFirstFloor",classFirst,typeJamF);
    g.insertInNode("SSESecondFloor",classSecond,typeJamS);
    //g.searchClassroomInNode(nodeName,"Go to Building");
    //g.searchClassroomInNode(nodeName,"Computer Lab 4");




//////ADMIN


    vector<string> AdminG;
    vector<string> AdminGType ={"Office","Office","Office","Office","Office","Office","Office","Office","Office","Office",
                                "Office","Office","Office","Office","Office","Office","Office","Office","Office","Office","Office",
                                "Office", "Office", "Office", "Office", "Office","Office", "Office", "Office", "Office"};




    vector<string> AdminType ={"Office","Office","Office","Office","Office","Office","Office","Office","Office","Office",
                               "Office","Office","Office","Office","Office","Office","Office","Office","Office","Office","Office",
                               "Office", "Office", "Office", "Office", "Office","Office", "Office", "Office", "Office"};




    for (int i = 1; i <= 30; ++i) {

        string cp = "G" + to_string(i);
        AdminG.push_back(cp);


        //  cout << classSecond.back() << "  " << endl;
    }




    g.insertInNode("Administration",AdminGround, AdminGType);
    g.insertInNode("AdministrationGarden",AdminG,AdminType);
    g.insertInNode("AdministrationFirstFloor",AdminFF,AdminType);
    g.insertInNode("AdministrationSecondFloor",AdminSF,AdminType);





    int choice;
    cout << "Greetings!" << endl;
    cout << "How could we serve you today?" << endl;
    cout << "Service 1: Search for a room in a building and recieve its details"
         << endl;
    cout << "Service 2: Recieve the shortest path from one buidling to another "
         << endl;
    cin >> choice;

    if (choice == 1)
    {

        string n;
        string r;
        bool b;
        cout<<"Please enter the building name"<<endl;
        cin>>n;
        cout<<"Please enter the room name"<<endl;
        cin>>r;
       g.searchClassroomInNode(n,r);
       cout<<endl;

        cout << "Done! Thank you!" << endl;
    }
    else if (choice == 2)
    {
        string one;
        string two;
        vector<string> path;
        cout<<"Please enter the building you are at"<<endl;
        cin>>one;
        cout<<"Please enter building you want to go to"<<endl;
        cin>>two;
        int d=g.dijkstra(g.intNodeIndex(one), path, two);
        cout<<"Below we will provide you with the shortest path to your destination"<<endl;
        for(int i=0;i<path.size();i++) {
            if (i != path.size() - 1)
                cout << path[i] << " ->" << " ";
            else
                cout << path[i];
        }
        cout<<endl<<"The total desitance is "<<d<<endl;


        cout << "Done! Thank you!" << endl;
    }



    return 0;
}