#pragma once
#include "Trie.h"


struct searchData
{
	int score = 0;
	vector<int> place;
	string fileName;
	//void sort();
};

vector<searchData> search(vector<fileData> docData, vector<fileData> stopwordData, vector<fileData> synonymData ,string query);

vector<int> normalSearch(trieNode* root, string key);