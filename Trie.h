//
// Created by Fawzy on 11/10/2023.
//

#ifndef APPLIED_PROJECT_TRIE_H
#define APPLIED_PROJECT_TRIE_H
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct trieNode
{
    unordered_map<char, trieNode *> children;;
            bool word=false;
            string building;
};

class Trie {

private:
    trieNode* root;
public:
    Trie();
    void insert(string room, string location);
    bool search(string room);
    string loc(string room);

};


#endif //APPLIED_PROJECT_TRIE_H
