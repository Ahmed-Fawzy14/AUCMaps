//
// Created by Fawzy on 11/10/2023.
//
#include <iostream>
#include "Trie.h"
using namespace std;

Trie::Trie()
{
    root= new trieNode();

}

<<<<<<< Updated upstream
void Trie:: insert(string room, string location, string t)
=======
void Trie:: insert(string room, string location, string t) const
>>>>>>> Stashed changes
{
    trieNode* n=root;


    for (int i = 0; i < room.length(); i++)
    {
        char c = room[i];
        if (!n->children[c])
            n->children[c] = new trieNode();

        n = n->children[c];
    }
    n->word = true;
    n->building=location;
    n->type=t;
}

<<<<<<< Updated upstream
bool Trie:: search(string room)
=======
bool Trie:: search(const string room, trieNode*&pointer) const
>>>>>>> Stashed changes
{
    trieNode* n=root;

    for (int i = 0; i < room.length(); i++)
    {
<<<<<<< Updated upstream
         char c=room[i];
=======
        char c=room[i];
>>>>>>> Stashed changes
        if (!n->children[c])
            return false;

        n = n->children[c];
    }
<<<<<<< Updated upstream

    return n->word;
}

string Trie::loc(string room)
{
   trieNode* m = root;
=======
pointer=n;
    return n->word;
}
/*
string Trie::loc(string room)
{
    trieNode* m = root;
>>>>>>> Stashed changes

    for (int i = 0; i < room.length(); i++)
    {
        char c = room[i];
        if (!m->children[c])
            return "Nothing found";

        m = m->children[c];
    }

    if (m->word)
        return m->building;
    else
        return "Nothing found";
}

<<<<<<< Updated upstream
string Trie::model(string room)
=======
/*string Trie::model(string room)
>>>>>>> Stashed changes
{
    trieNode* m = root;

    for (int i = 0; i < room.length(); i++)
    {
        char c = room[i];
        if (!m->children[c])
            return "Nothing found";

        m = m->children[c];
    }

    if (m->word)
        return m->type;
    else
        return "Nothing found";
<<<<<<< Updated upstream
}


=======
} */
>>>>>>> Stashed changes




