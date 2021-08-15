#pragma once
#ifndef _TRIE_H_
#define _TRIE_H_

#include <vector>
#include <string>
using namespace std;

struct trieNode
{
public:
    trieNode();
    trieNode* child[38]; // 0-> 25 : letters, 26-> 35: numbers, 36,37: # $
    vector<int> place; 
};



struct trie
{
public:
    trieNode* root;
    void insertTrie(vector<string> input);
    trie();
    ~trie();
};




void insert(struct trieNode* root, string key, int place);


// function for stopword

//function for synonyms

#endif