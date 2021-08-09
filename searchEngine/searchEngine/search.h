#pragma once
#include "Trie.h"
#include <fstream>

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

// done
vector<int> normalSearch(const fileData& file, const string& key);


vector<int> exactSearch(const fileData& file,const vector<string>& query); // not done

//vector<string> stringToWord(string input);

void preprocess(string& input);

//void testDisplay(const string &fileName,  const vector<int> &places);