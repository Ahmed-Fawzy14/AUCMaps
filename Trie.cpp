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

void Trie:: insert(string room, string location, string t)
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

bool Trie:: search(string room)
{
    trieNode* n=root;

    for (int i = 0; i < room.length(); i++)
    {
         char c=room[i];
        if (!n->children[c])
            return false;

        n = n->children[c];
    }

    return n->word;
}

string Trie::loc(string room)
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
        return m->building;
    else
        return "Nothing found";
}

string Trie::model(string room)
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
}






