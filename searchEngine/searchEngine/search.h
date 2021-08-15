#pragma once
#ifndef _SEARCH_H_
#define _SEARCH_H_
#include <iostream>
#include <fstream>
#include<string>
#include "fileHandling.h"
#include "Trie.h"
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

vector<searchData> selectTop5(vector<searchData>& searchResult);

// done
vector<int> normalSearch(const fileData& file, const string& key);
vector<string> stringToWord(const string & input);
void preprocess(string& input);
void preprocess_exactSearch(string& input);
vector<int> exactSearch(const fileData& file, const vector<string>& query);

//sorting
int getMax(vector<int> &arr);
void countSort(vector<int>& arr, int exp);
void radixsort(vector<int>& arr);

//void testDisplay(const string &fileName,  const vector<int> &places);

#endif