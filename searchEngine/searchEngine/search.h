#pragma once
#ifndef _SEARCH_H_
#define _SEARCH_H_
#include "Trie.h"
#include <fstream>
#include<string>
using namespace std;

int const MIN_INT = -2147483647;

struct searchData
{
	int score = 0;
	vector<int> place;
	string fileName;
	//void sort();
};

// not done
vector<searchData> search(const vector<fileData>& docData, const vector<fileData>& stopwordData,
	const vector<fileData>& synonymData, const string& query);

vector<int> exactSearch(const fileData& file, vector<string>& query);

// done
vector<int> normalSearch(const fileData& file, const string& key);
vector<string> stringToWord(const string & input);
void preprocess(string& input);
void preprocess_exactSearch(string& input);



//void testDisplay(const string &fileName,  const vector<int> &places);

#endif