#pragma once
#ifndef _TRIE_H_
#define _TRIE_H_

#include <vector>
#include <string>
#include <iostream>
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
    bool isEmpty(trieNode*root);
    trie(const trie& origin);
    trie();
    ~trie();
};

void deleteTrie(trieNode* root);



void insert(struct trieNode* root, string key, int place);

void copyTrieNode(trieNode* origin, trieNode* &copy);

// function for stopword

// function for synonyms

#endif