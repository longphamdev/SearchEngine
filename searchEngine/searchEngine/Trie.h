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
    bool existed = false;
};



struct trie
{
public:
    trieNode* root = new trieNode;
    trie(vector<string> input);
    ~trie();
};

struct price {
    int amount;
    int place;
};

struct fileData
{
    trie data;
    string fileName;
    vector<price> priceData;
    fileData(vector<string> input, string fileName);
};


struct synonymData {
    trie data;
    vector<string> words;
};




void insert(struct trieNode* root, string key, int place);
vector<fileData> getFileData(string folderName);

// function for stopword

//function for synonyms

#endif