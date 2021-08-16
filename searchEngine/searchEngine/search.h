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
vector<searchData> search(const vector<fileData>& docData, const fileData& stopwordData, const vector<synonymData> & synoData,
const string& query);

vector<searchData> selectTop5(vector<searchData>& searchResult);

// done
vector<int> normalSearch(const fileData& file, const string& key);
vector<string> stringToWord(const string & input);
void preprocess(string& input);
void preprocess_exactSearch(string& input);
vector<int> exactSearch(const fileData& file, const vector<string>& query);

//sorting
void swap(int* a, int* b);
int Partition(vector<int>& v, int start, int end);
void Quicksort(vector<int>& v, int start, int end);

//void testDisplay(const string &fileName,  const vector<int> &places);


vector<int> findAnd(string ss1, string ss2, const fileData& file);
vector<int> findOr(string ss1, string ss2, const fileData& file);
bool findNOT(string ss, const fileData& file);
vector<int> findPrice(int amountSearch, const fileData& file);
vector<int> findRangePrice(int amountSearch1, int amountSearch2, const fileData& file);

vector<string> removeElements(vector<string> input, vector<int> remove);
bool isPriceRange(string input);
bool isNumber(char input);

void displayTest(searchData searchResult);
vector<string> synonymSearch(const synonymData& file, const string& key);

bool intitleSearch(fileData file, string key);
#endif