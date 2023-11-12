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

void Trie:: insert(string room)
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



